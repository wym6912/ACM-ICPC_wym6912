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

const ll mod = 1e9 + 7;
const int maxn = 100001 << 2;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

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

typedef struct 
{
	ll mul, pow, sum;
}node;

node tree[maxn];

void pushup(int p, int l, int r)
{
	tree[p].sum = (tree[DXA(p)].sum * tree[DXB(p)].sum) % mod;
}

ll pow_mod(ll a, ll b, ll mod)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

void pushdown(int p, int l, int r)
{
	if(tree[p].pow == 1 && tree[p].mul == 1)return ;
	int mid = midf(l, r);
	tree[DXA(p)].mul = pow_mod(tree[DXA(p)].mul, tree[p].pow, mod) * tree[p].mul % mod;
	tree[DXB(p)].mul = pow_mod(tree[DXB(p)].mul, tree[p].pow, mod) * tree[p].mul % mod;
	tree[DXA(p)].pow = tree[DXA(p)].pow * tree[p].pow % (mod - 1);
	tree[DXB(p)].pow = tree[DXB(p)].pow * tree[p].pow % (mod - 1); //Lucas ∂®¿Ì 
	tree[DXA(p)].sum = pow_mod(tree[DXA(p)].sum, tree[p].pow, mod) * pow_mod(tree[p].mul, mid - l + 1, mod) % mod;
	tree[DXB(p)].sum = pow_mod(tree[DXB(p)].sum, tree[p].pow, mod) * pow_mod(tree[p].mul, r - mid, mod) % mod;
	tree[p].mul = 1;
	tree[p].pow = 1;
}

void pre(int l, int r, int p)
{
	tree[p].pow = 1;
	tree[p].mul = 1;
	if(l == r)
	{
		scan_d(tree[p].sum);
		tree[p].sum %= mod;
		tree[p].mul = tree[p].sum;
		return;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update_mul(int l, int r, int nl, int nr, ll m, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].mul = (tree[p].mul * m) % mod;
		tree[p].sum = tree[p].sum * pow_mod(m, nr - nl + 1, mod) % mod;
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_mul(l, r, nl, mid, m, DXA(p));
	if(mid < r) update_mul(l, r, mid + 1, nr, m, DXB(p));
	pushup(p, nl, nr);
}

void update_pow(int l, int r, int nl, int nr, ll m, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].pow = tree[p].pow * m % (mod - 1);
		tree[p].mul = pow_mod(tree[p].mul, m, mod);
		tree[p].sum = pow_mod(tree[p].sum, m, mod);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_pow(l, r, nl, mid, m, DXA(p));
	if(mid < r) update_pow(l, r, mid + 1, nr, m, DXB(p));
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p].sum % mod;
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 1;
	if(l <= mid)ans = (ans * query(l, r, nl, mid, DXA(p))) % mod;
	if(mid < r) ans = (ans * query(l, r, mid + 1, nr, DXB(p))) % mod;
	return ans;
}

int n;

int main()
{
	int q, type, f, t, T;
	ll val;
	scan_d(T);
	while(T --)
	{
		scan_d(n);scan_d(q);
		pre(1, n, 1);
		while(q --)
		{
			scan_d(type);
			scan_d(f);
			scan_d(t);
			switch(type)
			{
				case 1:
					scan_d(val);
					update_mul(f, t, 1, n, val, 1);
					break;
				case 2:
					scan_d(val);
					update_pow(f, t, 1, n, val, 1);
					break;
				case 3:
					out_number(query(f, t, 1, n, 1) % mod);
					puts("");
					break;
				default:
					assert(type == 1 || type == 2 || type == 3);
			}
		}
	}
	return 0;
}
/*
1
5 10
1 2 1 2 1
3 2 4
1 1 5 2
3 1 1
3 2 2
3 3 3
3 4 4
3 5 5
3 2 4
2 1 1 4
3 1 1
*/
