#define NOSTDCPP
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
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = maxn << 1;
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

int v[maxm], prevv[maxm];
int info[maxn], deep[maxn], size[maxn];
int father[maxn], head[maxn], len[maxn], son[maxn], id[maxn], pid[maxn];
bool vis[maxn];
int l, r, ans, cnt;
int N, nedge;
ll val;

struct edg
{
	int f, t, cost;
}edge[maxn];

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
}

struct edg_2
{
	int f, t;
	ll c;
}__edg[maxn];

ll A[maxn], tree[maxn << 2];

void pushup(int p){tree[p] = tree[DXA(p)] + tree[DXB(p)];}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p] = A[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

void update(int nl, int nr, int p)
{
	if(nl == nr)
	{
		tree[p] = val;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	else update(mid + 1, nr, DXB(p));
	pushup(p);
}

ll query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p];
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query(nl, mid, DXA(p));
	if(mid < r)  ans += query(mid + 1, nr, DXB(p));
	return ans;
}


ll __query__(int u, int v)
{
	ll ans = 0;
    int f1 = head[u], f2 = head[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        //operation(p[f1], p[u]);
        l = id[f1], r = id[u];
        ans += query(1, N, 1);
        u = father[f1]; f1 = head[u];
    }
    if(u == v)return ans;
    if(deep[u] > deep[v]) swap(u, v);
	//operation(id[son[u]], id[v]);
	l = id[son[u]], r = id[v];
	ans += query(1, N, 1);
	return ans;
}

int main()
{
    int f, M, type;
	while(~ scanf("%d %d", &N, &M))
	{
		cnt = 0;
		nedge = 0;
	    init();
	    for(int i = 1; i < N; ++ i)
	    {
	        scanf("%d %d %I64d", &__edg[i].f, &__edg[i].t, &__edg[i].c);
	        insert(__edg[i].f, __edg[i].t);
	        insert(__edg[i].t, __edg[i].f);
	    }
	    for(int i = 1; i <= N; ++ i)
	    	if(deep[i] == -1)
				dfs1(i, 0, 0);
		for(int i = 1; i <= N; ++ i)
			if(id[i] == 0)
				getpos(i, i);
		for(int i = 1; i < N; ++ i)
		{
			if(deep[__edg[i].f] < deep[__edg[i].t])
				swap(__edg[i].f, __edg[i].t);
			A[id[__edg[i].f]] = __edg[i].c;
		}
		pre(1, N, 1);
		while(M --)
		{
			scanf("%d", &type);
			switch(type)
			{
				case 0:
					scanf("%d %I64d", &f, &val);
					l = id[__edg[f].f];
					update(1, N, 1);
					break;
				case 1:
					scanf("%d %d", &l, &r);
					printf("%I64d\n", __query__(l, r));
					break;
				default:
					assert(type == 0 || type == 1);
			}
		}
	}
	return 0;
}

