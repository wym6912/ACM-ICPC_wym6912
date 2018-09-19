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
const int maxm = (1 << 21) + 10;
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

ll a[maxn], num[maxm], sum[maxn];
ll n, m, unit, k;

struct query
{
	ll L, R, id;
	bool operator < (const query &b) const
	{
		return (L / unit != b.L / unit ? (L / unit < b.L / unit) : (R < b.R));
	}
}node[maxn];

ll ans[maxn];

void modui()
{
	RESET(num);
	/*
	int L = node[1].L, R = node[1].R;
	ll temp = 0;
	for(int i = L; i <= R; ++ i)
	{
		temp += num[sum[i] ^ k];
		++ num[sum[i]];
	}
	ans[node[1].id] = temp;
	*/
	int L = 1, R = 0;
	ll temp = 0;
	for(int i = 1; i <= m; i ++)
	{
		while(R < node[i].R) // ??1:??????
		{
            ++ R;
			temp += num[sum[R] ^ k];
			++ num[sum[R]];
		}
		while(R > node[i].R) // ??2:??????
		{
			-- num[sum[R]];
			temp -= num[sum[R] ^ k];
			-- R;
		}
		while(L < node[i].L) // ??3:??????
		{
			-- num[sum[L]];
			temp -= num[sum[L] ^ k];
			++ L;
		}
		while(L > node[i].L) // ??4:??????
		{
			-- L;
			temp += num[sum[L] ^ k];
			++ num[sum[L]];
		}
		ans[node[i].id] = temp;
	}

}

int main()
{
	/*
	scan_d(n);
	scan_d(m);
	scan_d(k);
	*/
	scanf("%d %d %d", &n, &m, &k);
	sum[0] = 0;
	for(int i = 1; i <= n; ++ i)
	{
		//scan_d(a[i]);
		scanf("%d", a + i);
		sum[i] = a[i] ^ sum[i - 1];
	}
	for(int i = 1; i <= m; ++ i)
	{
		node[i].id = i;
		/*
		scan_d(node[i].L);
		scan_d(node[i].R);
		*/
		scanf("%d %d", &node[i].L, &node[i].R);
		-- node[i].L;
	}
	unit = (ll)sqrt(n);
	sort(node + 1, node + m + 1);
	modui();
	for(int i = 1; i <= m; i ++)
	{
		//out_number(ans[i]);
		printf("%I64d\n", ans[i]);
	}
	return 0;
}
/*
6 2 3
1 2 1 1 0 3
1 6
3 5

5 3 1
1 1 1 1 1
1 5
2 4
1 3
*/
