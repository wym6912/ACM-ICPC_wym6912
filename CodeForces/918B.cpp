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

typedef struct ip
{
	int a, b, c, d;
	char info[15];
	friend bool operator == (const ip &ipa, const ip &ipb)
	{
		return (ipa.a == ipb.a && ipa.b == ipb.b && ipa.c == ipb.c && ipb.d == ipa.d);
	}
}ip;

ip data[1009], pre[1009];

int n, m;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(~ scanf("%d%d", &n, &m))
	{
		for(int i = 1; i <= n; i ++)
			scanf("\n%s%d.%d.%d.%d", &data[i].info, &data[i].a, &data[i].b, &data[i].c, &data[i].d);
		for(int i = 1; i <= m; i ++)
			scanf("\n%s%d.%d.%d.%d;", &pre[i].info, &pre[i].a, &pre[i].b, &pre[i].c, &pre[i].d);
		for(int i = 1; i <= m; i ++)
		{
			printf("%s %d.%d.%d.%d; #", pre[i].info, pre[i].a, pre[i].b, pre[i].c, pre[i].d);
			for(int j = 1; j <= n; j ++)
				if(data[j] == pre[i])
				{
					puts(data[j].info);
					break;
				}
		}
	}
	return 0;
}

