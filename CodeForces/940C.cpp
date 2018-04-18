//#define NOSTDCPP
//#define Cpp11
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

int n, q;
string str;
vi strcnv;
bool hasch[256];
map <int, char> mp;
map <char, int> mpp;

void cnv()
{
	int strsize = str.size();
	for(int i = 0; i < strsize; i ++)
		strcnv.pb(mpp[str[i]]);
}

void gen(int mod, int q)
{
	int i = q - 1;
	strcnv[i] ++;
	while(strcnv[i] == mod)
	{
		strcnv[i] = 0;
		strcnv[i - 1] ++;
		i --;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int demptr;
	char ch;
	bool f;
	while(cin >> n >> q)
	{
		demptr = 0;
		f = false;
		mp.clear();
		cin >> str;
		int strsize = str.size();
		for(int i = 0; i < strsize; i ++)
			hasch[str[i]] = true;
		for(int i = 0; i < 255; i ++)
			if(hasch[i])
			{
				mp[demptr ++] = i;
				mpp[i] = demptr - 1;
			}
		if(n < q)
		{
			cout << str;
			for(int i = n + 1; i <= q; i ++)
				cout << mp[0];
			cout << endl;
			continue;
		}
		cnv();
		gen(demptr, q);
		for(int i = 0; i < q; i ++)
			cout << mp[strcnv[i]];
		cout << endl;
	}
	return 0;
}
