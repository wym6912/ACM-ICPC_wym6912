//#define NOSTDCPP
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
#include <fstream>
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

template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
}

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

ll ppp[maxn][6];
ll ze[maxn];
ll datam[50], datab[50];
int n, m, k;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	ll tmp;
	//scan_d(T);
	scanf("%d", &T);
	while(T --)
	{
		/*
		scan_d(n);
		scan_d(m);
		scan_d(k);
		*/
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1; i <= n; ++ i)
		{
			//scan_d(ze[i]);
			scanf("%lld", &ze[i]);
			for(int j = 0; j < k; ++ j)
				//scan_d(ppp[i][j]);
				scanf("%lld", &ppp[i][j]);
		}
		for(int i = n + 1, p = 1; p <= m; ++ i, ++ p)
		{
			//scan_d(ze[i]);
			scanf("%lld", &ze[i]);
			for(int j = 0; j < k; ++ j)
				//scan_d(ppp[i][j]);
				scanf("%lld", &ppp[i][j]);
		}
		for(int i = 0; i < (1 << k); ++ i)
			datam[i] = -1e11, datab[i] = -1e11;
		for(int i = 1; i <= n; i ++)
		{
			for(int status = 0; status < (1 << k); ++ status)
			{
				tmp = 0;
				for(int j = 0; j < k; j ++)
				{
					if(status & (1 << j))
					{
						tmp += ppp[i][j];
					}
					else tmp -= ppp[i][j];
				}
				datam[status] = max(datam[status], tmp + ze[i]);
			}
		}
		for(int i = n + 1; i <= n + m; i ++)
		{
			for(int status = 0; status < (1 << k); ++ status)
			{
				tmp = 0;
				for(int j = 0; j < k; j ++)
				{
					if(status & (1 << j))
					{
						tmp += ppp[i][j];
					}
					else tmp -= ppp[i][j];
				}
				datab[status] = max(datab[status], tmp + ze[i]);
			}
		}
		/*
		for(int i = 0; i < (1 << k); i ++)
			cout << datam[i] << ' ' << datab[i] << endl;
		*/
		ll ans = 0;
		for(int status1 = 0; status1 < (1 << k); ++ status1)
			ans = max(ans, datam[status1] + datab[(1 << k) - 1 - status1]);
		out_number(ans);
		puts("");
	}
	return 0;
}
