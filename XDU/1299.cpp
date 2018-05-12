//#define NOSTDCPP
//#define Cpp11
#define Linux_System
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

ll max(ll a, ll b)
{
	if(a > b)return a;
	return b;
}

ll data[maxn], nn[maxn];
int n;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, f, t0, t1;
	ll ans;
	scan_d(T);
	while(T --)
	{
		scan_d(n);
		for(int i = 1; i <= n; i ++)
		{
			scan_d(data[i]);
			nn[i] = data[i];
		}
		ans = data[1] - data[n];
		sort(nn + 1, nn + 1 + n);
		int p = unique(nn + 1, nn + 1 + n) - nn;
		for(int i = 1; i <= n; i ++)
		{
			nn[0] = data[i];
			data[i] = lower_bound(nn + 1, nn + p, nn[0]) - nn;
			//cout << data[i] << ' ';
		}
		for(int i = 1; i <= n; i ++)
		{
			t0 = 1;
			while(true)
			{
				//cout << i << "?" << endl;
				while((f = find(data + i + 1, data + n + 1, t0) - data) == n + 1)
				{
					t0 ++;
					//cout << f << endl;
					if(t0 == p)break;
				}
				if(t0 != p)ans = max(ans, nn[data[i]] - nn[t0]);
				break;
			}
		}
		out_number(ans);
		puts("");
	}
	return 0;
}
/*
5
4
8 1 2 3
3
3 2 1
4
6 8 9 10
4
13 8 7 1
10
9 72 87 28 19 83 28 29 10 29
*/
