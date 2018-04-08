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

ll data[maxn], aw[maxn];

pii d[100009];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int pe = 0, f = 1, t = 1;
	ll ans = 0, tmp, tmpans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> data[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> aw[i];
		ans += aw[i] * data[i];
		! aw[i] ? d[++ pe].fi = i, d[pe].se = data[i] : 0;
	}
	/*
	for(int beg = 1; beg <= n - m + 1; beg ++)
	{
		tmp = 0;
		for(int i = 1; i <= n; i ++)
			if((beg <= i && i <= beg + m - 1) && ! aw[i])
				tmp += data[i];
		tmpans = max(tmpans, tmp);
	}
	*/
	//for(int i = 1; i <= pe; i ++)
	//	cout << d[i].fi << ' ' << d[i].se << endl;
	tmp = 0;
	//cout << pe << endl;
	while(f <= pe)
	{
		while(t <= pe && d[t].fi - d[f].fi < m)tmp += d[t].se, t ++;
		//cout << f << ' ' << d[f].fi << ' ' << t << " " << d[t].fi << ' ' << tmp << endl;
		tmpans = max(tmp, tmpans);
		tmp -= d[f].se;
		f ++;
	}
	cout << ans + tmpans << endl;
	return 0;
}
/*
6 6
1 2 3 4 5 6
0 0 0 0 0 0
6 3
1 3 5 2 5 4
1 1 0 1 0 0
6 6 
1 2 3 4 5 6
0 0 0 0 0 0
6 1
12 3 4 5 6 1
0 0 0 0 0 1
*/
