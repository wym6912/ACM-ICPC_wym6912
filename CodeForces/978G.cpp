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

struct node{
	int from, to, cost, id;
}data[maxn];

int ans[maxn], n, m, tmp;

bool cmp1(const node &a, const node &b)
{
	return a.id < b.id;
}

bool cmp2(const node &a, const node &b)
{
	/*if(a.from <= tmp && tmp < a.to && b.from <= tmp && tmp < b.to)
	{
		//if(a.from != b.from)return a.from < b.from;
		if(a.cost + a.from - a.to != b.cost + b.from - b.to)
			return a.cost + a.from - a.to > b.cost + b.from - b.to;
	}
	if(a.from != b.from)return a.from < b.from;
	if(a.to != b.to)
	*/return a.to < b.to;
	//return a.cost > b.cost;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> m)
	{
		bool ok = true;
		for(int i = 1; i <= n; i ++)
			ans[i] = 0;
		for(int i = 1; i <= m; i ++)
			cin >> data[i].from >> data[i].to >> data[i].cost, data[i].id = i;
		for(int i = 1; i <= m; i ++)
			ans[data[i].to] = m + 1;
		tmp = 1;
		sort(data + 1, data + 1 + m, cmp2);
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
				if(data[j].from <= i && i < data[j].to)
				{
					if(! ans[i] && data[j].cost > 0)
						data[j].cost --, ans[i] = data[j].id;
				}
			tmp = i + 1;
			//sort(data + 1, data + 1 + m, cmp2);
		}
		for(int i = 1; i <= m; i ++)
			if(data[i].cost > 0)
				ok = false;
		if(! ok)cout << -1 << endl;
		else 
		{
			for(int i = 1; i <= n; i ++)
				cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}
/*
100 2
1 3 1
4 19 10
6 2
1 5 2
2 3 1
20 5
6 16 3
4 14 4
3 13 1
1 11 1
10 20 4
*/
