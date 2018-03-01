//#define NOSTDCPP
//#define Cpp11
#define Linux_System
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

ll mod;
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
	ll mul, add, sum;
}node;

node tree[maxn];

void pushup(int p, int l, int r)
{
	tree[p].sum = (tree[DXA(p)].sum + tree[DXB(p)].sum) % mod;
}

void pushdown(int p, int l, int r)
{
	if(tree[p].add == 0 && tree[p].mul == 1)return ;
	int mid = midf(l, r);
	tree[DXA(p)].add = (tree[DXA(p)].add * tree[p].mul + tree[p].add) % mod;
	tree[DXB(p)].add = (tree[DXB(p)].add * tree[p].mul + tree[p].add) % mod;
	tree[DXA(p)].mul = (tree[p].mul * tree[DXA(p)].mul) % mod;
	tree[DXB(p)].mul = (tree[p].mul * tree[DXB(p)].mul) % mod;
	tree[DXA(p)].sum = (tree[DXA(p)].sum * tree[p].mul + (mid - l + 1) * tree[p].add) % mod;
	tree[DXB(p)].sum = (tree[DXB(p)].sum * tree[p].mul + (r - mid) * tree[p].add) % mod;
	tree[p].add = 0;
	tree[p].mul = 1;
}

void pre(int l, int r, int p)
{
	tree[p].add = 0;
	tree[p].mul = 1;
	if(l == r)
	{
		scan_d(tree[p].sum);
		tree[p].sum %= mod;
		tree[p].add = tree[p].sum;
		tree[p].mul = 1;
		return;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update_add(int l, int r, int nl, int nr, ll a, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].add = (tree[p].add + a) % mod;
		tree[p].sum = ((nr - nl + 1) * a + tree[p].sum) % mod;
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_add(l, r, nl, mid, a, DXA(p));
	if(mid < r) update_add(l, r, mid + 1, nr, a, DXB(p));
	pushup(p, nl, nr);
}


void update_mul(int l, int r, int nl, int nr, ll m, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].mul = (tree[p].mul * m) % mod;
		tree[p].add = (tree[p].add * m)	% mod;
		tree[p].sum = (tree[p].sum * m) % mod;
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_mul(l, r, nl, mid, m, DXA(p));
	if(mid < r) update_mul(l, r, mid + 1, nr, m, DXB(p));
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p].sum % mod;
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid)ans = (ans + query(l, r, nl, mid, DXA(p))) % mod;
	if(mid < r)ans = (ans + query(l, r, mid + 1, nr, DXB(p))) % mod;
	return ans;
}

int n;

int main()
{
	int q, type, f, t;
	ll val;
	scan_d(n);
	scan_d(mod);
	pre(1, n, 1);
	scan_d(q);
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
				update_add(f, t, 1, n, val, 1);
				break;
			case 3:
				out_number(query(f, t, 1, n, 1) % mod);
				puts("");
				break;
			default:
				assert(type == 1 || type == 2 || type == 3);
		}
	}
	return 0;
}
/*
7 43
1 2 3 4 5 6 7
19
1 2 5 5
3 1 1
3 2 2
3 3 3
3 4 4
3 5 5
3 6 6
3 7 7
3 2 4
2 3 7 9
3 1 1
3 2 2
3 3 3
3 4 4
3 5 5
3 6 6
3 7 7
3 1 3
3 4 7
*/
