#define NOSTDCPP
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

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("java_c.in", "r", stdin);
//	freopen("java_c.out", "w", stdout);
	string str;
	cin >> str;
	int strsize = str.size();
	bool cpp = false, java = false, cppf;
	for(int i = 0; i < strsize; ++ i)
	{
		if(str[i] == '_') cpp = true;
		if(isupper(str[i])) java = true;
	}
	if(java && cpp) cout << "Error!\n";
	else if(java)
	{
		if(isupper(str[0])) 
		{
			cout << "Error!\n";
			return 0;
		}
		for(int i = 0; i < strsize; ++ i)
		{
			if(isupper(str[i]))
				cout << "_";
			cout << (char)tolower(str[i]);
		}
		cout << "\n";
	}
	else if(cpp)
	{
		cppf = false;
		if(str[0] == '_')
		{
			cout << "Error!\n";
			return 0;
		}
		for(int i = 0; i < strsize; ++ i)
		{
			if(str[i] == '_' && cppf) 
			{
				cout << "Error!\n";
				return 0;
			}
			if(str[i] == '_') 
			{
				cppf = true;
			}
			if(cppf && str[i] != '_') cppf = false;
		}
		if(cppf) 
		{
			cout << "Error!\n";
			return 0;
		}
		cppf = false;
		for(int i = 0; i < strsize; ++ i)
		{
			if(str[i] == '_') 
			{
				cppf = true;
				continue;
			}
			if(cppf) cout << (char)toupper(str[i]), cppf = false;
			else cout << str[i];
		}
		cout << "\n";
	}
	else cout << str << "\n";
	return 0;
}
/*
long_and_mnemonic_identifier 
anotherExample
i
bad_Style
longAndMnemonicIdentifier
another_example
_v
javaIdentifier
c_identifier
hui_xi_hua_yuan
assWe_Can
n_e_e_r_c
*/
