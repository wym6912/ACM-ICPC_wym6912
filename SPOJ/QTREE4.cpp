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
int val[maxn], mx[maxn], sz[maxn], tag[maxn], sum[maxn], lmx[maxn], rmx[maxn], w[maxn], len[maxn];
multiset <int> chain[maxn], path[maxn]; // 维护链上信息、路径信息 
int q[maxn];
bool rev[maxn];
int n, m, f, t, type, ans;
////边 beg///
struct edge
{
	int to, next, cost;
}edg[maxn << 1];
int fir[maxn], cnt;
void addedge(int f, int t, int w)
{
	edg[++ cnt].next = fir[f];
	fir[f] = cnt;
	edg[cnt].cost = w;
	edg[cnt].to = t;
}
////边 end/// 
int fir_place(multiset <int> &s)
{
	//如果有值的话，返回最后一个 
	return s.size() ? *s.rbegin() : -inf;
}
int sec_place(multiset <int> &s)
{
	//倒数第二个 
	return s.size() > 1 ? *(++ s.rbegin()) : -inf;
}
void init(){
    sz[0] = 0;
	for(int i = 1; i <= n; i ++)
    	sz[i] = 1;
    for(int i = 0; i <= n; i ++)
    	lmx[i] = rmx[i] = mx[i] = -inf;
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    int l = c[x][0], r = c[x][1];
    sz[x] = sz[l] + sz[r] + 1;
    sum[x] = sum[l] + sum[r] + len[x];
    int cha = max(w[x], fir_place(chain[x]));
    int lmm = max(cha, rmx[l] + len[x]);
    int rmm = max(cha, lmx[r]);
    lmx[x] = max(lmx[l], sum[l] + len[x] + rmm);
    rmx[x] = max(rmx[r], sum[r] + lmm);
    mx[x] = max(mx[l], mx[r]);
    mx[x] = max(mx[x], fir_place(chain[x]) + sec_place(chain[x]));
    mx[x] = max(mx[x], fir_place(path[x]));
    mx[x] = max(mx[x], max(rmx[l] + len[x] + rmm, lmx[r] + lmm));
    if(w[x] == 0) mx[x] = max(mx[x], max(fir_place(chain[x]), 0));
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
    	if(c[x][1]) chain[x].insert(lmx[c[x][1]]), path[x].insert(mx[c[x][1]]);
    	if(i) chain[x].erase(chain[x].find(lmx[i])), path[x].erase(path[x].find(mx[i]));
		c[x][1] = i;
		update(x);
	}
}
void makeroot(int x)
{
    access(x);splay(x);rev[x] ^= 1;
}
void link(int x,int y)
{
    makeroot(x);fa[x] = y;
	splay(x);
}

void cut(int x, int y)
{
	makeroot(x);
	access(y);
	splay(y);
    c[y][0] = fa[c[y][0]] = 0;
    update(y);
}

int find(int x){
    access(x);splay(x);
    while(c[x][0]) x = c[x][0];
    return x;
}

void modify(int x)
{
    access(x);
    splay(x);
    w[x] = (w[x] == 0 ? -inf : 0);
    update(x);
    ans = mx[x];
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
			len[v] = edg[i].cost;
			dfs(v);
			chain[x].insert(lmx[v]);
			path[x].insert(mx[v]);
		}
	}
	update(x);
}

int main()
{
	char op[2];
	scan_d(n);
	init();
	cnt = 0;
	for(int i = 1; i < n; i ++)
	{
		scan_d(f);
		scan_d(t);
		scan_d(type);
		addedge(f, t, type);
		addedge(t, f, type);
	}
	dfs(1);
	ans = mx[1];
	scan_d(m);
	while(m --)
	{
		scanf("%s", op);
		if(op[0] == 'A')
		{
			if(ans < 0) puts("They have disappeared.");
			else printf("%d\n", ans);
		}
		else scanf("%d", &f), modify(f);
	}
	return 0;
}
