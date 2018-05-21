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

struct node
{
	ll cap;
	int id, ans;
}data[maxn];

bool cmp1(const node &a, const node &b)
{
	return a.cap < b.cap;
}

bool cmp2(const node &a, const node &b)
{
	return a.id < b.id;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int f, t, n, m;
	while(cin >> n >> m)
	{
		for(int i = 1; i <= n; i ++)
		{
			cin >> data[i].cap;
			data[i].id = i;
		}
		sort(data + 1, data + 1 + n, cmp1);
		int same = 0, pp = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(data[i].cap == data[i - 1].cap && i != 0)same ++;
			else 
			{
				pp += same;
				same = 1;
			}
			//if(i == n) pp += same;
			//cout << pp << ' ' << same << endl;
			data[i].ans = pp;
		}
		//for(int i = 1; i <= n; i ++)
		//	cout << data[i].ans << ' ' ;
		//cout << endl;
		sort(data + 1, data + 1 + n, cmp2);
		while(m --)
		{
			cin >> f >> t;
			if(data[f].cap > data[t].cap) data[f].ans --;
			if(data[f].cap < data[t].cap) data[t].ans --;
		}
		for(int i = 1; i <= n; i ++)
			cout << data[i].ans << ' ';
		cout << endl;
	}
	return 0;
}

/*
4 2
10 4 10 15
1 2
4 3

10 4
5 4 1 5 4 3 7 1 2 5
4 6
2 1
10 8
3 5

*/
