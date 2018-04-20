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
const int maxn = 1000004;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-4;

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

int data[maxn], delta[maxn], zp, sum[maxn], n;

double calc(int f, int t)
{
	return abs((double)(sum[t] - sum[f - 1]) / (double)(t - f + 1));
}

double f(int lx)
{
	//for(int i = 1; i < n; i ++)
	//	cout << delta[i] << ' ';
	//cout << endl;
	int r = n - 1, mid, l = lx;
	double ans = calc(lx, r);
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(calc(lx, mid) < ans)
		{
			ans = calc(lx, mid);
			r = mid;
		}
		else l = mid + 1;
		//cout << l <<  ' ' << r << ' ' << ans << endl;
	}
	return ans;
}

int main()
{
	//freopen("test.in", "r", stdin);
	double ans, mid;
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i ++)
			scanf("%d", &data[i]),
			delta[i - 1] = data[i] - data[i - 1];
		sum[0] = 0;
		//sort(delta + 1, delta + n);
		for(int i = 1; i < n; i ++)
			sum[i] = sum[i - 1] + delta[i];
		ans = 1e10;
		for(int i = 1; i < n; i ++)
			ans = min(ans, f(i));
		printf("%.2f\n", ans);
		//getchar();
	}
	return 0;
}
/*
10
2983 2863 187 2783 2982 278 2386 276 128973 1
*/
