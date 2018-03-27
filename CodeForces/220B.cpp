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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100005;
const int maxm = 100005;
const double pi = acos(-1.0);
const double eps = 1e-6;

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

ll a[maxn], num[maxm];
ll n, m, unit;

struct query
{
	ll L, R, id;
	bool operator < (const query &b) const
	{
		return (L / unit != b.L / unit ? (L / unit < b.L / unit) : (R < b.R));
	}
}node[maxm];

ll ans[maxm];

void modui()
{
    ll temp = 0;
	RESET(num);
	int L = 1, R = 0;
	for(int i = 1; i <= m; i ++)
	{
		while(R < node[i].R) // 转移1：将右边值放大
		{
            ++ R;
			temp -= (num[a[R]] == a[R] && a[R] != 0);
			++ num[a[R]];
			temp += (num[a[R]] == a[R] && a[R] != 0);
		}
		while(R > node[i].R) // 转移2：将右边值缩小
		{
			temp -= (num[a[R]] == a[R] && a[R] != 0);
			-- num[a[R]];
			temp += (num[a[R]] == a[R] && a[R] != 0);
			-- R;
		}
		while(L < node[i].L) // 转移3：将左边值缩小
		{
			temp -= (num[a[L]] == a[L] && a[L] != 0);
			-- num[a[L]];
			temp += (num[a[L]] == a[L] && a[L] != 0);
			++ L;
		}
		while(L > node[i].L) // 转移4：将左边值增大
		{
			-- L;
			temp -= (num[a[L]] == a[L] && a[L] != 0);
			++ num[a[L]];
			temp += (num[a[L]] == a[L] && a[L] != 0);
		}
		ans[node[i].id] = temp;
	}

}

int main()
{
	while(scan_d(n) && scan_d(m))
	{
		for(int i = 1; i <= n; i ++)
			scan_d(a[i]), a[i] = (a[i] <= n ? a[i] : 0);
		for(int i = 1; i <= m; i ++)
		{
			node[i].id = i;
			scan_d(node[i].L);
			scan_d(node[i].R);
		}
		unit = (ll)sqrt(n);
		sort(node, node + m);
		modui();
		for(int i = 1; i <= m; i ++)
		{
			out_number(ans[i]);
			puts("");
		}
	}
	return 0;
}
/*
7 2
3 1 2 2 3 3 7
1 7
3 4
*/
