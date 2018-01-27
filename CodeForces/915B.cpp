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

int n, pos, l, r;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> pos >> l >> r)
	{
		int ans = 0;
		if(pos >= l && pos <= r)
		{
			if(l != 1 && r != n)
			{
				ans += min(pos - l, r - pos);
				ans ++;
				ans += r - l;
				ans ++;
			}
			else if(l == 1 && r != n)
			{
				ans += r - pos;
				ans ++;
			}
			else if(r == n && l != 1)
			{
				ans += pos - l;
				ans ++;
			}
			else ans += 0;
		}
		else 
		{
			if(pos <= l)
			{
				ans += l - pos;//pos = l
				ans ++;
				if(l != 1 && r != n)
				{
					ans += r - l;
					ans ++;
				}
				else if(l == 1 && r != n)
				{
					ans += r - pos;
					ans ++;
				}
				else if(r == n && l != 1)
				{
					;
				}
				else ans += 0;
			}
			else 
			{
				ans += pos - r; //pos = r;
				ans ++;
				if(l != 1 && r != n)
				{
					ans += r - l;
					ans ++;
				}
				else if(l == 1 && r != n)
				{
					;
				}
				else if(r == n && l != 1)
				{
					ans += pos - l;
					ans ++;
				}
				else ans += 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

