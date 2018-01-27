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

string a;
ll b;

int numa[10];

ll e10[19];

void judge(ll x, int p)
{
	if(x <= b)
	{
		cout << x << endl;
		exit(0);
	}
}
/*
void ooo(ll x, int p)
{
	cout << x << ' ' << p << endl;
}
*/
bool isend()
{
	for(int i = 0; i <= 9; i ++)
		if(numa[i])
			return false;
	return true;
}

void dfs(ll x, int p)
{
	if(p == 0)
		judge(x, p);
	else
	{
		int px;
		for(px = 9; px >= 0; px --)
			if(numa[px] && x * e10[p] <= b)
			{
				numa[px] --;
				//ooo(x, p);
				dfs(x * 10 + px, p - 1);
				numa[px] ++;
			}
	}
}

int orphan(string a)
{
	RESET(numa);
	for(int i = 0; i < a.size(); i ++)
		numa[a[i] - '0'] ++;
	return a.size();
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	e10[0] = 1;
	for(int i = 1; i <= 18; i ++)
		e10[i] = e10[i - 1] * 10;
	///////////////
	cin >> a >> b;
	int p = orphan(a);
	dfs(0, p);
	return 0;
}

