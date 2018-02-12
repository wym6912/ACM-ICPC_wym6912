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
const int maxn = 300009 * 4;
const int maxm = 10000007;
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

template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
}

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

ll euler[maxm];

void init(int Max)
{
	euler[1] = 1;
	for(int i = 2;i < Max; i ++)
		euler[i] = i;
	for(int i = 2;i < Max; i ++)
		if(euler[i] == i)
			for(int j = i; j < Max; j += i)
				euler[j] = euler[j] / i * (i - 1);
}

typedef struct
{
	ll sum, tag;
}node;

node tree[maxn];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
		if(tree[DXA(p)].tag == tree[DXB(p)].tag)tree[p].tag = tree[DXA(p)].tag;
		else tree[p].tag = 0;
	}
}

void pushup_2(int p, ll len)
{
	tree[p].sum = tree[p].tag * len;
}

void pushdown(int p, int nl, int nr)
{
	if(tree[p].tag)
	{
		int mid = midf(nl, nr);
		tree[DXA(p)].tag = tree[DXB(p)].tag = tree[p].tag;
		tree[DXA(p)].sum = tree[DXA(p)].tag * (ll)(mid - nl + 1);
		tree[DXB(p)].sum = tree[DXB(p)].tag * (ll)(nr - mid);
		tree[p].tag = 0;
	}
}

void pre(int l, int r, int p)
{
	tree[p].tag = 0;
	if(l == r)
	{
		scan_d(tree[p].sum);
		tree[p].tag = tree[p].sum;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int n;

void update_1(int l, int r, int nl, int nr, int p)
{
	if(tree[p].tag && l <= nl && nr <= r)
	{
		tree[p].tag = euler[tree[p].tag];
		tree[p].sum = tree[p].tag * (ll)(nr - nl + 1);
		return ;
	}
	if(l == r)return ;
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_1(l, r, nl, mid, DXA(p));
	if(mid < r) update_1(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void update_2(int l, int r, int nl, int nr, ll c, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].tag = c;
		tree[p].sum = c * (ll)(nr - nl + 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_2(l, r, nl, mid, c, DXA(p));
	if(mid < r) update_2(l, r, mid + 1, nr, c, DXB(p));
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, q, ty, f, t;
	ll x;
	scan_d(T);
	init(1e7 + 2);
	while(T --)
	{
		scan_d(n, q);
		pre(1, n, 1);
		while(q --)
		{
			scan_d(ty);
			switch(ty)
			{
				case 1:
					scan_d(f, t);
					update_1(f, t, 1, n, 1);
					break;
				case 2:
					scan_d(f, t, x);
					update_2(f, t, 1, n, x, 1);
					break;
				case 3:
					scan_d(f, t);
					out_number(query(f, t, 1, n, 1));
					puts("");
					break;
				default:
					assert(ty == 1 || ty == 2 || ty == 3);
			}
		}
	}
	return 0;
}

