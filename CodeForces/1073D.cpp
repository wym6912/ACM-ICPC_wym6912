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
const int maxn = 300009;
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
ll A[maxn], sum[maxn << 2];

inline void pushup(int p){sum[p] = sum[DXA(p)] + sum[DXB(p)];}

void pre(int l, int r, int p)
{
	sum[p] = 0;
	if(l == r)
	{
		sum[p] = A[l];
		return;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int l, r;
void update(int nl, int nr, int p)
{
	if(nl == nr)
	{
		sum[p] = 0;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	else update(mid + 1, nr, DXB(p));
	pushup(p);
}

ll query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r) return sum[p];
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query(nl, mid, DXA(p));
	if(mid < r)  ans += query(mid + 1, nr, DXB(p));
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k;
	scanf("%d %I64d", &n, &k);
	for(register int i = 1; i <= n; ++ i) scanf("%I64d", A + i);
	pre(1, n, 1);
	int lll, rr, midd, siz = n, pl;
	ll ans = 0;
	while(siz)
	{
		if(k >= sum[1])
		{
			ans += (k / sum[1]) * siz;
			k %= sum[1];
		}
		lll = 1, rr = n, midd, pl = -1;
		l = 1;
		while(lll <= rr)
		{
			midd = midf(lll, rr);
			r = midd;
			if(query(1, n, 1) > k)
			{
				pl = midd;
				rr = midd - 1;
			}
			else lll = midd + 1;
		}
		l = pl;
		update(1, n, 1);
		-- siz;
	}
	printf("%I64d\n", ans);
	return 0;
}
/*
?t¡¤??¡ã¡Áoo¨ª¡ê?¡¤¡é???¦Ì?¨²?D??¡ê?¨¦?¨°?¡ä?¨ºy¡ê?o¨®??¦Ì??¡ã¡Áoo¨ªDT??¡ê?
*/
