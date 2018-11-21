//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#endif

# ifdef Linux_System
# define getchar getchar_unlocked
# define putchar putchar_unlocked
# endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define mp make_pair
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 300009;
const ll inf = 1e18;
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

template <class T>
inline void out_number(T x)
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

int deep[maxn], father[maxn], son[maxn], siz[maxn], id[maxn], head[maxn], cnt_id;

void dfs1(int u, int fa, int dep)
{
	deep[u] = dep;
	siz[u] = 1;
	father[u] = fa;
	son[u] = 0;
	for(register int i = fir[u], v; i; i = edg[i].next)
	{
		if((v = edg[i].to) != fa)
		{
			dfs1(v, u, dep + 1);
			siz[u] += siz[v];
			if(! son[u] || siz[son[u]] < siz[v])
				son[u] = v;
		}
	}
}

void getpos(int u, int sp)
{
	head[u] = sp;
	id[u] = ++ cnt_id;
	if(son[u]) getpos(son[u], sp);
	for(register int i = fir[u], v; i; i = edg[i].next)
	{
		if((v = edg[i].to) != son[u] && v != father[u])
		{
			getpos(v, v);
		}
	}
}

#define ls(_) tree[_].l
#define rs(_) tree[_].r
struct node
{
	int sum, maxv, l, r;
}tree[maxn * 50];

int cnt_cmt, root[maxn];

void pushup(int p)
{
	tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;
	tree[p].maxv = max(tree[ls(p)].maxv, tree[rs(p)].maxv);
}

int l, r, val;
void update(int nl, int nr, int &p)
{
	if(! p) p = ++ cnt_cmt;
	if(nl == nr)
	{
		tree[p].sum = tree[p].maxv = val;
		return;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, ls(p));
	else update(mid + 1, nr, rs(p));
	pushup(p);
}

int query_max(int nl, int nr, int p)
{
	if(! p) return 0;
	if(l <= nl && nr <= r) return tree[p].maxv;
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans = query_max(nl, mid, tree[p].l);
	if(mid < r)  ans = max(ans, query_max(mid + 1, nr, tree[p].r));
	return ans;
}

int query_sum(int nl, int nr, int p)
{
	if(! p) return 0;
	if(l <= nl && nr <= r) return tree[p].sum;
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans += query_sum(nl, mid, tree[p].l);
	if(mid < r)  ans += query_sum(mid + 1, nr, tree[p].r);
	return ans;
}

#undef ls
#undef rs

int w[maxn], lovelive[maxn];

inline int __sum__(int u, int v)
{
    int f1 = head[u], f2 = head[v], ans = 0, rt = root[lovelive[u]];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        l = id[f1], r = id[u];
        ans += query_sum(1, n, rt);
        u = father[f1]; f1 = head[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = id[u], r = id[v];
    ans += query_sum(1, n, rt);
    return ans;
}

inline int __max__(int u, int v)
{
    int f1 = head[u], f2 = head[v], ans = 0, rt = root[lovelive[u]];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        l = id[f1], r = id[u];
        ans = max(ans, query_max(1, n, rt));
        u = father[f1]; f1 = head[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = id[u], r = id[v];
    ans = max(query_max(1, n, rt), ans);
    return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(register int i = 1; i <= n; ++ i) scanf("%d %d", w + i, lovelive + i);
	for(register int i = 1, f, t; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs1(1, 1, 1); 
	getpos(1, 1);
	for(register int i = 1; i <= n; ++ i)
	{
		l = id[i], val = w[i];
		update(1, n, root[lovelive[i]]);
	}
	char str[5];
	int f, t;
	while(m --)
	{
		scanf("%s %d %d", str, &f, &t);
		switch(str[1])
		{
			case 'C':
				l = id[f], val = 0;
				update(1, n, root[lovelive[f]]);
				lovelive[f] = t;
				l = id[f];
				val = w[f];
				update(1, n, root[lovelive[f]]);
				break;
			case 'W':
				l = id[f], val = w[f] = t;
				update(1, n, root[lovelive[f]]);
				break;
			case 'S':
				printf("%d\n", __sum__(f, t));
				break;
			case 'M':
				printf("%d\n", __max__(f, t));
				break;
			default:
				assert(false);
		}
	}
	return 0;
}

