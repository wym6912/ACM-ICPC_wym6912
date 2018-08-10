//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
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

const int MOD = 19260817;
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

ll a[maxn], b[maxn], c[maxn], l[maxn], r[maxn], tree[maxn];
int n;

int lowbit(int x){return x & -x;}

void update(int x, ll val)
{
	for(int i = x; i <= n; i += lowbit(i))
		tree[i] = (tree[i] + val) % MOD;
}

ll query(int x)
{
	ll ans = 0;
	for(int i = x; i; i -= lowbit(i))
		ans = (ans + tree[i]) % MOD;
	return ans;
}

int main()
{
	ll ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	int p = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i ++)
	{
		c[i] = lower_bound(b + 1, b + 1 + p, a[i]) - b;
	}
	for(int i = 1; i <= n; i ++)
	{
		l[i] = query(c[i] - 1) % MOD;
		update(c[i], a[i]);
	}
	RESET(tree);
	for(int i = n; i; i --)
	{
		r[i] = (query(n) - query(c[i]) + MOD) % MOD;
		update(c[i], a[i]);
	}
	for(int i = 1; i <= n; i ++)
	{
		ans = (ans + (l[i] * r[i] % MOD * (a[i] % MOD) % MOD)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}

