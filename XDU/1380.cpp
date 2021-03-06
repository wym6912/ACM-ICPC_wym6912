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
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define next __Chtholly__
# define distance __Mercury__
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
const int maxm = 100009;
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

int n, m, cnt, cnt_hld;
int fir[maxn], dfs_time[maxn << 1], deep[maxn], pos[maxn], st2[maxn << 1][21], log_2[maxn << 1];
ll dis[maxn];

struct edg
{
	int to, next;
	ll val;
}edg1[maxn << 1];

inline void addedge(int f, int t, ll val)
{
	edg1[++ cnt].to = t;
	edg1[cnt].next = fir[f];
	edg1[cnt].val = val;
	fir[f] = cnt;
}

void dfs1(int u, int fa, int dep)
{
	pos[u] = ++ cnt_hld;
	dfs_time[cnt_hld] = u;
	deep[u] = dep;
	for(register int i = fir[u], v; i; i = edg1[i].next)
		if((v = edg1[i].to) != fa)
		{
			dis[v] = dis[u] + edg1[i].val;
			dfs1(v, u, dep + 1);
			dfs_time[++ cnt_hld] = u;
		}
}

inline void rmqinit()
{
	for(register int i = 1; i <= cnt_hld; ++ i)
		st2[i][0] = dfs_time[i];
	for(register int i = 1; i <= 20; ++ i)
		for(register int j = 1; j + (1 << i) - 1 <= cnt_hld; ++ j)
		{
			if(deep[st2[j][i - 1]] < deep[st2[j + (1 << (i - 1))][i - 1]])
				st2[j][i] = st2[j][i - 1];
			else st2[j][i] = st2[j + (1 << (i - 1))][i - 1];
		}
	log_2[1] = 0;// ���뿪���� 
	for(register int i = 2; i <= cnt_hld; ++ i)
	{
		if((1 << (log_2[i - 1] + 1)) < i) log_2[i] = log_2[i - 1] + 1;
		else log_2[i] = log_2[i - 1]; 
	}
}

int RMQ(int x, int y)
{
	int a = log_2[y - x + 1];
	if(deep[st2[x][a]] < deep[st2[y - (1 << a) + 1][a]])
		return st2[x][a];
	return st2[y - (1 << a) + 1][a];
}

ll distance(int x, int y)
{
	if(pos[x] > pos[y]) swap(x, y);
	int LCA = RMQ(pos[x], pos[y]);
	return dis[x] + dis[y] - (dis[LCA] << 1);
}

int tree[maxn << 2][2];

inline void __make(ll &ans, int &s1, int &s2, int v1, int v2)
{
	ans = distance(v1, v2), s1 = v1, s2 = v2;
}

inline void __pushup(int &s1, int &s2, int a1, int a2, int b1, int b2)
{
	ll ans = 0; 
	if(ans < distance(a1, a2)) __make(ans, s1, s2, a1, a2);
	if(ans < distance(a1, b1)) __make(ans, s1, s2, a1, b1);
	if(ans < distance(a2, b2)) __make(ans, s1, s2, a2, b2);
	if(ans < distance(a1, b2)) __make(ans, s1, s2, a1, b2);
	if(ans < distance(a2, b1)) __make(ans, s1, s2, a2, b1);
	if(ans < distance(b1, b2)) __make(ans, s1, s2, b1, b2);
}

inline void pushup(int p)
{
	__pushup(tree[p][0], tree[p][1], tree[DXA(p)][0], tree[DXA(p)][1], tree[DXB(p)][0], tree[DXB(p)][1]);
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p][0] = tree[p][1] = l;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int l, r, ans1, ans2;
void query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__pushup(ans1, ans2, tree[p][0], tree[p][1], ans1, ans2);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) query(nl, mid, DXA(p));
	if(mid < r)  query(mid + 1, nr, DXB(p));
}

int main()
{
	int a, b, c, d, a1, a2, b1, b2;
	ll ans, val;
	scanf("%d", &n);
	cnt = cnt_hld = 0;
	for(register int i = 1, f, t; i < n; ++ i)
	{
		scanf("%d %d %lld", &f, &t, &val);
		addedge(f, t, val);
		addedge(t, f, val);
	}
	dis[1] = 0;
	dfs1(1, 0, 0);
	rmqinit();
	pre(1, n, 1);
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		ans = 0;
		ans1 = a, ans2 = a;
		l = a, r = b;
		query(1, n, 1);
		a1 = ans1, a2 = ans2;
		ans1 = c, ans2 = c;
		l = c, r = d;
		query(1, n, 1);
		b1 = ans1, b2 = ans2;
		ans = max(ans, distance(a1, b1));
		ans = max(ans, distance(a2, b1));
		ans = max(ans, distance(a1, b2));
		ans = max(ans, distance(a2, b2));
		printf("%lld\n", ans);
	}
	return 0;
}

