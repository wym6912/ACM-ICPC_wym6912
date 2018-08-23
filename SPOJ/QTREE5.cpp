#include <bits/stdc++.h>
#define RESET(_) memset(_, 0, sizeof(_))

using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
const int inf = 1e9;

template <class T>
inline bool scan_d(T & ret)
{
	char c;
	int sgn;
	if(c = getchar(), c == EOF)return false;
	while(c != '-' && (c < '0' || c > '9'))c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while(c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + (c - '0');
	ret *= sgn;
	return true;
}

int top;
int fa[maxn],c[maxn][2];
int val[maxn], mx[maxn], sz[maxn], sum[maxn], lmx[maxn], rmx[maxn], w[maxn];
multiset <int> chain[maxn];// 维护链上信息
int q[maxn];
bool rev[maxn];
int n, m, f, t, type, ans;
////边 beg///
struct edge
{
	int to, next;
}edg[maxn << 1];
int fir[maxn], cnt;
void addedge(int f, int t)
{
	edg[++ cnt].next = fir[f];
	fir[f] = cnt;
	//edg[cnt].cost = w;
	edg[cnt].to = t;
}
////边 end/// 
int fir_place(multiset <int> &s)
{
	//如果有值的话，返回第一个 
	return s.size() ? *s.begin() : inf;
}
void init(){
    sz[0] = 0;
	for(int i = 1; i <= n; i ++)
    	sz[i] = 1;
    for(int i = 0; i <= n; i ++)
    	lmx[i] = rmx[i] = w[i] = inf, chain[i].clear();
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    int l = c[x][0], r = c[x][1];
    sz[x] = sz[l] + sz[r] + 1;
    sum[x] = sum[l] + sum[r] + 1;
    int cha = min(w[x], fir_place(chain[x]));
    int lmm = min(cha, rmx[l] + 1);
    int rmm = min(cha, lmx[r]);
    lmx[x] = min(lmx[l], sum[l] + 1 + rmm);
    rmx[x] = min(rmx[r], sum[r] + lmm);
    mx[x] = min(lmm, rmm); // 不用维护子树相关的标记 
}
void pushdown(int x)
{
    int l=c[x][0],r=c[x][1];
    if(rev[x])
    {
        rev[x]^=1;rev[l]^=1;rev[r]^=1;
        swap(c[x][0],c[x][1]);
    }
}
void rotate(int x)
{
    int y=fa[x],z=fa[y],l,r;
    l=(c[y][1]==x);r=l^1;
    if(!isroot(y))c[z][c[z][1]==y]=x;
    fa[c[x][r]]=y;fa[y]=x;fa[x]=z;
    c[y][l]=c[x][r];c[x][r]=y;
    update(y);update(x);
}
void splay(int x)
{
    top = 0;
    q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i])
        q[++top]=fa[i];
    while(top)pushdown(q[top--]);
    while(!isroot(x))
    {
        int y=fa[x],z=fa[y];
        if(!isroot(y))
        {
            if(c[y][0]==x^c[z][0]==y)rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void access(int x)
{
    for(int i = 0; x; i = x, x = fa[x])
    {
    	splay(x);
    	if(c[x][1]) chain[x].insert(lmx[c[x][1]]);
    	if(i) chain[x].erase(chain[x].find(lmx[i]));
		c[x][1] = i;
		update(x);
	}
}

void modify(int x)
{
    access(x);
    splay(x);
    w[x] = (w[x] == 0 ? inf : 0);
    update(x);
}

int query(int x)
{
	access(x);
	splay(x);
	return mx[x] == inf ? -1 : mx[x];
}

void dfs(int x)
{
	int v;
	for(int i = fir[x]; i; i = edg[i].next)
	{
		v = edg[i].to;
		if(fa[x] != v)
		{
			fa[v] = x;
			dfs(v);
			chain[x].insert(lmx[v]);
		}
	}
	update(x);
}

int main()
{
	scan_d(n);
	init();
	cnt = 0;
	for(int i = 1; i < n; i ++)
	{
		scan_d(f);
		scan_d(t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs(1);
	scan_d(m);
	while(m --)
	{
		scanf("%d%d", &type, &f);
		switch(type)
		{
			case 0:
				modify(f);
				break;
			case 1:
				printf("%d\n", query(f));
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
