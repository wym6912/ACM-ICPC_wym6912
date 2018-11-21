#include <bits/stdc++.h>

# define midf(x, y) ((x + y) >> 1)
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int maxn = 100009;

int n, m;

struct edge
{
	int to, next;
}edg[maxn << 1];
int fir[maxn], cnt_edg;

inline void addedge(int f, int t)
{
	edg[++ cnt_edg].to = t;
	edg[cnt_edg].next = fir[f];
	fir[f] = cnt_edg;
}

int son[maxn], father[maxn], head[maxn], id[maxn], pid[maxn], cnt_id, deep[maxn], siz[maxn];
void dfs1(int u, int fa, int dep)
{
	deep[u] = dep ++;
	father[u] = fa;
	siz[u] = 1;
	son[u] = 0;
	for(register int i = fir[u], v; i; i = edg[i].next)
	{
		if((v = edg[i].to) != fa)
		{
			dfs1(v, u, dep);
			siz[u] += siz[v];
			if(! son[u] || siz[son[u]] < siz[v])
				son[u] = v;
		}
	}
}

void getpos(int u, int sp)
{
	id[u] = ++ cnt_id;
	pid[cnt_id] = u;
	head[u] = sp;
	if(son[u]) getpos(son[u], sp);
	for(register int i = fir[u], v; i; i = edg[i].next)
	{
		if((v = edg[i].to) != father[u] && v != son[u])
			getpos(v, v);
	}
}

int cnt_cmt, tree[maxn << 2];

void pushup(int p)
{
	if(tree[DXA(p)]) tree[p] = tree[DXA(p)];
	else if(tree[DXB(p)]) tree[p] = tree[DXB(p)];
	else tree[p] = 0;
}

int l, r, val;
void update(int nl, int nr, int p)
{
	if(nl == nr)
	{
		if(tree[p]) tree[p] = 0;
		else tree[p] = nl;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	else update(mid + 1, nr, DXB(p));
	pushup(p);
}

int query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r) return tree[p];
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans = query(nl, mid, DXA(p));
	if(ans) return ans;
	if(mid < r)  ans = query(mid + 1, nr, DXB(p));
	return ans;
}

int ans(int u)
{
    int f1 = head[u], ans = -1, tmp;
    while(f1 != 1)
    {
        //printf("%d %d %d\n", id[f1], id[u], query(1, n + 1, root));
        l = id[f1], r = id[u];
        if(tmp = query(1, n, 1)) ans = pid[tmp];
        u = father[f1]; f1 = head[u];
    }
    //printf("%d %d\n", id[u], id[v]);
    l = 1, r = id[u];
    if(tmp = query(1, n, 1)) ans = pid[tmp];
    return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(register int i = 1, f, t; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs1(1, 1, 1);
	getpos(1, 1);
	int f, t;
	while(m --)
	{
		scanf("%d %d", &f, &t);
		switch(f)
		{
			case 0:
				l = id[t];
				update(1, n, 1);
				break;
			case 1:
				printf("%d\n", ans(t));
				break;
		}
	}
	return 0;
}

