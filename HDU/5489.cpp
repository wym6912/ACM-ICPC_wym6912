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
int A[maxn], LIS[maxn], InvA[maxn], thisLIS[maxn];

int main()
{
	int T, tmp, ans, mxlen;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++ i)
		{
			scanf("%d", A + i);
			InvA[i] = -A[i]; // 取相反数，这样可以从后往前 LIS
		}
		RESET_(LIS, 127);
		for(int i = n; i >= m + 1; -- i) //倒着求 LIS 
		{
			tmp = lower_bound(LIS + 1, LIS + 1 + n, InvA[i]) - LIS;
			LIS[tmp] = InvA[i];
			thisLIS[i] = tmp;
		}
		RESET_(LIS, 127);
		ans = mxlen = 0;
		for(int i = m + 1; i <= n; ++ i)
		{
			tmp = lower_bound(LIS + 1, LIS + 1 + n, A[i]) - LIS;
			ans = max(ans, tmp + thisLIS[i] - 1);
			tmp = lower_bound(LIS + 1, LIS + 1 + n, A[i - m]) - LIS;
			LIS[tmp] = A[i - m];
			mxlen = max(mxlen, tmp);
		}
		ans = max(ans, mxlen);
		//for(int i = 1; i <= n; ++ i) printf("%d ", LIS[i]);
		//puts("");
		//for(int i = 1; i <= n; ++ i) printf("%d ", thisLIS[i]);
		//puts("");
		printf("Case #%d: %d\n", Casen, ans);
	}
	return 0;
}
/*
3
11 4
1 4 3 5 7 4 9 4 5 6 8
5 2
1 2 3 4 5
5 3
5 4 3 2 1
*/

