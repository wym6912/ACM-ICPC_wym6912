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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct fraction
{
	ll num, den;
	fraction(ll num = 0, ll den = 1)
	{
		if(den < 0)num = -num, den = -den;
		assert(den > 0);
		ll g = gcd(abs(num), den);
		this -> num = num / g;
		this -> den = den / g;
	}
	fraction operator + (const fraction &o)const
	{
		return fraction(num * o.den + den * o.num, den * o.den);
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, c, d;
	fraction fa, fb;
	while(~ scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d))
	{
		fa = fraction(a, b);
		fb = fraction(c, d);
		fa = fa + fb;
		printf("%lld/%lld\n", fa.num, fa.den);
	}
	return 0;
}

