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
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
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
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

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
const int maxn = 200009;
const int maxm = 200009 << 1;
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

int v[maxm], prevv[maxm];
int info[maxn], deep[maxn], size[maxn];
int father[maxn], head[maxn], len[maxn], son[maxn], id[maxn], pid[maxn];
bool vis[maxn];
int l, r, ans, cnt;
int nedge;

struct edg
{
	int f, t, cost;
}edge[maxm];

inline void insert(int x, int y)
{
	++ nedge;
	v[nedge] = y;
	prevv[nedge] = info[x];
	info[x] = nedge;
}

void dfs1(int u, int pre, int d)
{
	deep[u] = d;
	father[u] = pre;
	son[u] = 0;
	size[u] = 1;
	for(int i = info[u]; i; i = prevv[i])
	{
		if(v[i] != pre)
		{
			dfs1(v[i], u, d + 1);
			size[u] += size[v[i]];
			if(! son[u] || size[v[i]] > size[son[u]])
				son[u] = v[i];
		}
	}
}

void getpos(int u, int sp)
{
	head[u] = sp;
	id[u] = ++ cnt;
    pid[id[u]] = cnt;
	if(son[u]) getpos(son[u], sp);
	for(int i = info[u]; i; i = prevv[i])
	{
		if(v[i] != son[u] && v[i] != father[u])
			getpos(v[i], v[i]); 
	}
}

void init()
{
    RESET(info);
    RESET_(deep, -1);
    RESET(size);
    RESET(father);
    RESET(head);
    RESET(len);
    RESET(son);
    RESET(id);
    RESET(pid);
    RESET(v);
    nedge = 0;
}

int n, m;

int sum[maxn << 2], sum_t[maxn << 2], tag[maxn << 2];
short need_clr[maxn << 2];

void pushup(int p)
{
	sum[p] = sum[DXA(p)] + sum[DXB(p)]; 
	sum_t[p] = sum_t[DXA(p)] + sum_t[DXB(p)];
}

void __add(int p, int val, int sz)
{
	sum[p] += sz * val;
	tag[p] += val;
}

void __need_clr(int p, short val)
{
	need_clr[p] = val;
	if(val == -1) sum_t[p] = 0;
	if(val == 1) sum_t[p] = sum[p];
}

void pushdown(int p, int nl, int nr)
{
	if(tag[p])
	{
		int mid = midf(nl, nr);
		__add(DXA(p), tag[p], mid - nl + 1);
		__add(DXB(p), tag[p], nr - mid);
		tag[p] = 0;
	}
	if(need_clr[p])
	{
		__need_clr(DXA(p), need_clr[p]);
		__need_clr(DXB(p), need_clr[p]);
		need_clr[p] = 0;
	}
}

void pre(int l, int r, int p)
{
	tag[p] = 0;
	need_clr[p] = 0;
	if(l == r)
	{
		sum[p] = sum_t[p] = 0;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int val;
void update(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__add(p, val, nr - nl + 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	if(mid < r)  update(mid + 1, nr, DXB(p));
	pushup(p);
}

void sum_tree(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__need_clr(p, 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) sum_tree(nl, mid, DXA(p));
	if(mid < r)  sum_tree(mid + 1, nr, DXB(p));
	pushup(p);
}

void __sum__(int u, int v)
{
    int f1 = head[u], f2 = head[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        l = id[f1], r = id[u];
        //operation(id[f1], id[u]);
        sum_tree(1, n, 1);
        u = father[f1]; f1 = head[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    //operation(id[u], id[v]);
    l = id[u], r = id[v];
    sum_tree(1, n, 1);
}

void clr(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__need_clr(p, -1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) clr(nl, mid, DXA(p));
	if(mid < r)  clr(mid + 1, nr, DXB(p));
	pushup(p);
}

void __clr__(int u, int v)
{
    int f1 = head[u], f2 = head[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        l = id[f1], r = id[u];
        //operation(id[f1], id[u]);
        clr(1, n, 1);
        u = father[f1]; f1 = head[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    //operation(id[u], id[v]);
    l = id[u], r = id[v];
    clr(1, n, 1);
}

int uu[10], vv[10];

int main()
{
	int type, f, t, k;
	scanf("%d", &n);
	init();
	pre(1, n, 1);
	for(int i = 1; i < n; ++ i)
	{
		scanf("%d %d", &l, &r);
		insert(l, r);
		insert(r, l);
	}
	dfs1(1, -1, 0);
	getpos(1, 1);
	//for(int i = 1; i <= n; ++ i) printf("%d ", size[i]); puts("");
	//for(int i = 1; i <= n; ++ i) printf("%d ", id[i]); puts("");
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d", &type);
		switch(type)
		{
			case 0:
				scanf("%d %d", &f, &val);
				l = id[f], r = id[f] + size[f] - 1;
				update(1, n, 1);
				break;
			case 1:
				scanf("%d", &k);
				for(int i = 1; i <= k; ++ i)
				{
					scanf("%d %d", &uu[i], &vv[i]);
					__sum__(uu[i], vv[i]);
				}
				printf("%d\n", sum_t[1] & 0x3fffffff);
				for(int i = 1; i <= k; ++ i)
				{
					__clr__(uu[i], vv[i]);
				}
				break;
			default:
				assert(type == 1 || type == 0);
		}
	}
	return 0;
}

