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

struct info
{
	ll from, to, id;
	bool operator < (const info &b) const
	{
		return from < b.from;
	}
}iii[maxn];

struct query
{
	ll data, pl, ans;
}data[maxn];

bool cmp1(const query &a, const query &b)
{
	return a.data < b.data;
}

bool cmp2(const query &a, const query &b)
{
	return a.pl < b.pl;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, n, m;
	bool isend;
	scan_d(T);
	while(T --)
	{
		RESET(iii);
		scan_d(n);
		for(int i = 1; i <= n; i ++)
		{
			scan_d(iii[i].from);
			scan_d(iii[i].to);
			scan_d(iii[i].id);
		}
		sort(iii + 1, iii + 1 + n);
		scan_d(m);
		for(int i = 1; i <= m; i ++)
		{
			scan_d(data[i].data);
			data[i].pl = i;
			data[i].ans = 0;
		}
		sort(data + 1, data + 1 + m, cmp1);
		int ans = 1;
		isend = false;
		for(int i = 1; i <= m; i ++)
		{
			//if(ans == n + 1)isend = true;
			while(data[i].ans == 0)
			{
				if(isend)
					data[i].ans = -1;
				else if(iii[ans].from <= data[i].data && data[i].data <= iii[ans].to)
					data[i].ans = ans;
				else if(ans == n + 1 || data[i].data < iii[ans].from)
				{
					data[i].ans = -1;
					if(ans == n + 1)isend = true;
				}
				else if(iii[ans].to < data[i].data)
					ans ++;
			}
		}
		sort(data + 1, data + 1 + m, cmp2);
		//for(int i = 1; i <= m; i ++)
		//	cout << data[i].data << ' ';
		//cout << endl;
		for(int i = 1; i <= m; i ++)
		{
			if(data[i].ans != -1)out_number(iii[data[i].ans].id);
			else out_number(-1);
			puts("");
		}
	}
	return 0;
}
/*
4

3
3 5 99
1 2 77
8 9 9
3
1
3
9

2
10000 39399 2939
1 38 28379
5
39
1
23009
293
10002

2
3 5 1298
1 2 2983
3
1
3
9

0
3
2039
283
3

*/
