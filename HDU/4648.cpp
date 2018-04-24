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
const int maxn = 100009;
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

ll data[maxn], sum[maxn], modp;
vi dq[10009];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, mod;
	while(cin >> n >> mod)
	{
		for(int i = 0; i < mod; i ++)dq[i].clear();
		for(int i = 1; i <= n; i ++)
		{
			cin >> data[i];
			data[i] %= mod;
			/*if(data[i] >= 0)data[i] %= mod;
			else 
			{
				int k = -data[i] / mod;
				data[i] = (k + 1) * mod + data[i];
				cout << data[i] << endl;
			}*/
		}
		sum[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			sum[i] = sum[i - 1] + data[i];
			sum[i] %= mod;
			if(sum[i] < 0)sum[i] += mod;
		}
		for(int i = 0; i <= n; i ++)
		{
			modp = sum[i] % mod;
			//cout << i << ' ' << modp << ' ' << sum[i] << endl;
			dq[modp].pb(i);
		}
		int ans = 0;
		for(int i = 0; i < mod; i ++)
		{
			//cout << dq[i].size() << endl;
			//for(int j = 0; j < dq[i].size(); j ++)
			//	cout << dq[i][j] << ' ';
			//cout << endl;
			if(dq[i].size() >= 2)
			{
				ans = max(ans, dq[i][dq[i].size() - 1] - dq[i][0]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
2 3
1 6
3 3
2 3 6
2 5
1 3
5 5
1 2 3 2 3
*/
