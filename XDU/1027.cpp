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
const int maxn = 2;
const int maxm = 2;
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

struct Matrix
{
	int n, m;
	ll a[maxn][maxm];
	void reset()
	{
		n = m = 0;
		RESET(a);
	}
	Matrix operator * (const Matrix &b)const
	{
		Matrix tmp;
		tmp.reset();
		tmp.n = n;
		for(int i = 0; i < n; i ++)
			for(int k = 0; k < n; k ++)
				for(int j = 0; j < n; j ++)
					tmp.a[i][j] += (a[i][k] * b.a[k][j]) % MOD;
		return tmp;
	}
	Matrix one()
	{
		Matrix tmp;
		tmp.reset();
		tmp.n = n;
		for(int i = 0; i < n; i ++)
			tmp.a[i][i] = 1;
		return tmp;
	}
	Matrix operator ^ (const ll &k)
	{
		ll b = k;
		Matrix tmp, tmp2 = one();
		tmp.n = n;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n;j ++)
				tmp.a[i][j] = a[i][j];
		while(b)
		{
			if(b & 1)tmp2 = tmp2 * tmp;
			b >>= 1;
			tmp = tmp * tmp;
		}
		return tmp2;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	Matrix a0, a1, a2;
	a0.n = 2;
	a0.a[0][0] = 2;
	a0.a[1][1] = 0;
	a0.a[0][1] = a0.a[1][0] = 1;
	while(~ scanf("%lld", &n))
	{
		a1.a[0][0] = 1;
		a1.a[1][0] = 0;
		a1.n = 2;
		a2 = (a0 ^ (n - 1)) * a1;
		//a1 = a2 * a1;
		printf("%lld\n", a2.a[0][0]);
	}
	return 0;
}

