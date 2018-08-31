#ifndef NOSTDCPP
	
#include <bits/stdc++.h>
	
#endif
	
	
# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)
	
# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__
	
using namespace std;
	
typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;
	
const int inf = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;
	
ll myrand(ll mod){return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod;}
	
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
#ifdef Cpp11
template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
}
#define cin.tie(0); cin.tie(nullptr);
#define cout.tie(0); cout.tie(nullptr);
#endif
inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n')ch = getchar();
	return true;
}
	
inline void out_number(ll x)
{
	if(x < 0)
	{
		putchar('-');
		out_number(- x);
		return ;
	}
	if(x > 9)out_number(x / 10);
	putchar(x % 10 + '0');
}
	
int n, m;
	
struct edge_1
{
	int f, t, c;
	bool s;
	bool operator < (const edge_1 &b) const
	{
		return c > b.c;
	}
}edg_1[maxn];
	
int dsu[maxn];
int find_dsu(int x) {return x == dsu[x] ? x : dsu[x] = find_dsu(dsu[x]);}
void unionn(int x, int y)
{
	x = find_dsu(x);
	y = find_dsu(y);
	if(x != y)
	{
		dsu[x] = y;
	}
}
	
struct Edge
{
    int to, next;
}edge[maxn << 1];
int head[maxn], tot, top[maxn], fa[maxn], deep[maxn], num[maxn], p[maxn], fp[maxn];
int son[maxn];
int pos;
	
void init()
{
    tot = 0;
    RESET_(head, -1);
    pos = 1;
    RESET_(son, -1);
    RESET_(deep, -1);
}
	
void addedge(int u,int v)
{
	edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
	
void dfs1(int u,int pre,int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}
	
void getpos(int u,int sp)
{
    top[u] = sp;
    if(son[u] != -1)
    {
        p[u] = pos++;
        fp[p[u]] = u;
        getpos(son[u],sp);
    }
    else
    {
        p[u] = pos++;
        fp[p[u]] = u;
        return;
    }
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}
	
int min_ans[maxn << 2], A[maxn];
	
void pushup(int p, int l, int r)
{
	if(l < r)
		min_ans[p] = min(min_ans[DXA(p)], min_ans[DXB(p)]);
}
	
void pre(int l, int r, int pp)
{
	min_ans[pp] = inf;
	if(l == r)
	{
		min_ans[pp] = A[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(pp));
	pre(mid + 1, r, DXB(pp));
	pushup(pp, l, r);
}
	
int query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return min_ans[p];
	int mid = midf(nl, nr), ans = inf;
	if(l <= mid) ans = min(ans, query(l, r, nl, mid, DXA(p)));
	if(mid < r)  ans = min(ans, query(l, r, mid + 1, nr, DXB(p)));
	return ans;
}
	
int ans(int f, int t)
{
	int ff = top[f], tt = top[t];
	int ans = inf;
	while(ff != tt)
	{
		if(deep[ff] < deep[tt]) swap(ff, tt), swap(f, t);
		ans = min(ans, query(p[ff], p[f], 1, n, 1));
		f = fa[ff];
		ff = top[f];
	}
	//if(f == t) return ans;
	if(deep[f] > deep[t]) swap(f, t);
	ans = min(ans, query(p[son[f]], p[t], 1, n, 1));
	return ans;
}
	
void Krusual()
{
	int s = n - 1;
	init();
	for(int i = 1; i <= n; i ++)
		dsu[i] = i;
	for(int i = 1; i <= m; i ++)
	{
		if(find_dsu(edg_1[i].f) != find_dsu(edg_1[i].t))
		{
			unionn(edg_1[i].f, edg_1[i].t);
			edg_1[i].s = true;
			addedge(edg_1[i].f, edg_1[i].t);
			addedge(edg_1[i].t, edg_1[i].f);
			s --;
		}
		//if(! s) break;
	}
}
	
int main()
{
	int f, t;
	scan_d(n);
	for(int i = 1; i <= n; i ++) A[i] = inf;
	scan_d(m);
	for(int i = 1; i <= m; i ++)
	{
		scan_d(edg_1[i].f);
		scan_d(edg_1[i].t);
		scan_d(edg_1[i].c);
		edg_1[i].s = false;
	}
	sort(edg_1 + 1, edg_1 + 1 + m);
	Krusual();
	dfs1(1, 0, 0);
	for(int i = 1; i <= n; i ++)
		if(deep[i] == -1)
			dfs1(i, 0, 0);
	getpos(1, 1);
	for(int i = 1; i <= n; i ++)
		if(p[i] == 0) 
			getpos(i, i);
	for(int i = 1; i <= m; i ++)
		if(edg_1[i].s)
		{
			if(deep[edg_1[i].f] > deep[edg_1[i].t])
				swap(edg_1[i].f, edg_1[i].t);
			A[p[edg_1[i].t]] = edg_1[i].c;
		}
	//for(int i = 1; i <= n; i ++) cout << A[i] << ' ';cout << endl;
	pre(1, n, 1);
	scan_d(m);
	while(m --)
	{
		scan_d(f);
		scan_d(t);
		if(find_dsu(f) == find_dsu(t))
			out_number(ans(f, t)), puts("");
		else puts("-1");
	}
	return 0;
}
/*
5 7
4 3 4440
3 1 22348
1 3 28368
2 4 25086
5 3 6991
4 3 10638
3 1 11106
4
4 5
1 3
5 4
2 5
*/

