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

const int MOD = 1e9 + 7;
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

ll fac[maxn], inv[maxn];
ll pow_mod(ll a, ll b, ll m = MOD)
{
	ll ans = 1; 
	while(b)
	{
		if(b & 1) ans = ans * a % m;
		b >>= 1;
		a = a * a % m;
	} 
	return ans;
}

int block, T;

struct query
{
	int l, r, id;
	bool operator < (const query &b) const
	{
		return l / block == b.l / block ? r < b.r : l / block < b.l / block;
	}
}qqq[maxn];

ll ans[maxn];

ll C(ll n, ll m)
{
	ll ans = fac[n] * inv[m] % MOD * inv[n - m] % MOD;
	return ans;
}

void modui()
{
	RESET(ans);
	ll tmp = 2;
	int L = 1, R = 1;
	for(int i = 1; i <= T; i ++)
	{
		while(L < qqq[i].l)
		{
			tmp = (tmp * 2 % MOD - C(L, R) + MOD) % MOD;
			L ++;
			//S(n, m) = 2S(n - 1, m) - C(n - 1, m)
		}
		while(R < qqq[i].r)
		{
			R ++;
			tmp = (tmp + C(L, R)) % MOD; 
			//+C(L, R)
		}
		while(L > qqq[i].l)
		{
			tmp = (tmp + C(L - 1, R)) % MOD * inv[2] % MOD;
			L --;
		}
		while(R > qqq[i].r)
		{
			tmp = (tmp - C(L, R) + MOD) % MOD; 
			R --;
			//-C(L, R)
		}
		ans[qqq[i].id] = tmp;
	}
}

int main()
{
	fac[0] = 1; inv[0] = 1;
	for(int i = 1; i <= 100000; i ++)
		fac[i] = i * fac[i - 1] % MOD;
	for(int i = 1; i <= 100000; i ++)
		inv[i] = pow_mod(fac[i], MOD - 2, MOD);
	scanf("%d", &T);
	block = (int) sqrt(100000.0);
	for(int i = 1; i <= T; i ++)
		scanf("%d %d", &qqq[i].l, &qqq[i].r), qqq[i].id = i;
	sort(qqq + 1, qqq + 1 + T);
	modui();
	for(int i = 1; i <= T; i ++)
		printf("%lld\n", ans[i]);
	return 0;
}

