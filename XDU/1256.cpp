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

string rome(int a)
{
	string s;
	int i, j;
	if(a >= 1000)
	{
		i = a / 1000;
		for(j = 0; j < i; j ++)
			s += "M";
		a -= 1000 * i;
	}
	if(a >= 900)
	{
		s += "CM";
		a -= 900;
	}
	if(a >= 500)
	{
		s += "D";
		a -= 500;
	}
	if(a >= 400)
	{
		s += "CD";
		a -= 400;
	}
	if(a >= 100)
	{
		i = a / 100;
		for(j = 0; j < i; j ++)
			s += "C";
		a -= 100 * i;
	}
	if(a >= 90)
	{
		s += "XC";
		a -= 90;
	}
	if(a >= 50)
	{
		s += "L";
		a -= 50;
	}
	if(a >= 40)
	{
		s += "XL";
		a -= 40;
	}
	if(a >= 10)
	{
		i = a / 10;
		for(j = 0; j < i; j ++)
			s += "X";
		a -= 10 * i;
	}
	if(a >= 9)
	{
		s += "IX";
		a -= 9;
	}
	if(a >= 5)
	{
		s += "V";
		a -= 5;
	}
	if(a >= 4)
	{
		s += "IV";
		a -= 4;
	}
	for(j = 0; j < a; j ++)
		s += "I";
	return s;
}

int main()
{
	int n;
	string str;
	while(cin >> n)
	{
		str = rome(n);
		cout << str << endl;
	}
	return 0;
}

