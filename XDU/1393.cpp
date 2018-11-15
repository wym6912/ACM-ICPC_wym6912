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
vi g[maxn];
int deep[maxn], st[maxn], ed[maxn], cnt;

void dfs(int u, int dep)
{
	st[u] = ++ cnt;
	deep[cnt] = dep;
	for(register int i = 0, gsize = g[u].size(); i < gsize; ++ i)
	{
		dfs(g[u][i], dep + 1);
	}
	ed[u] = cnt;
}

int maxd[maxn << 2], mind[maxn << 2];

void pushup(int p)
{
	maxd[p] = max(maxd[DXA(p)], maxd[DXB(p)]); 
	mind[p] = min(mind[DXA(p)], mind[DXB(p)]);
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		maxd[p] = mind[p] = deep[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int dl, dr, l, r;
int query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(mind[p] > dr || maxd[p] < dl) return 0;
		else if (dl <= mind[p] && maxd[p] <= dr) return nr - nl + 1;
	}
	if(mind[p] > dr || maxd[p] < dl) return 0;
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans += query(nl, mid, DXA(p));
	if(mid < r)  ans += query(mid + 1, nr, DXB(p));
	return ans;
}

int main()
{
	int x, dep;
	scanf("%d", &n);
	for(register int i = 2, t; i <= n; ++ i)
	{
		scanf("%d", &t);
		g[t].push_back(i);
	}
	/*
	for(register int i = 1; i <= n; ++ i)
	{
		cout << i << ": ";
		for(register int j = 0; j < g[i].size(); ++ j)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	*/
	cnt = 0;
	dfs(1, 1);
	pre(1, n, 1);
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d %d", &x, &dep);
		l = st[x], r = ed[x], dl = deep[st[x]], dr = deep[st[x]] + dep - 1;
		//cout << l << ' ' << r << ' ' << dl << ' ' << dr << endl;
		printf("%d\n", query(1, n, 1));
	}
	return 0;
}

