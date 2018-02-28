#define NOSTDCPP
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
	ll data;
	ll maxd, mind;
}node;

node tree[maxn];

int n, q;

ll maxx, minx;

void pushup(int p)
{
	tree[p].maxd = max(tree[DXA(p)].maxd, tree[DXB(p)].maxd);
	tree[p].mind = min(tree[DXA(p)].mind, tree[DXB(p)].mind);
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(tree[p].data);
		tree[p].maxd = tree[p].mind = tree[p].data;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

void query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		maxx = max(maxx, tree[p].maxd);
		minx = min(minx, tree[p].mind);
		return ;
	}
	else 
	{
		int mid = midf(nl, nr);
		if(l <= mid)
			query(l, r, nl, mid, DXA(p));
		if(mid < r)
			query(l, r, mid + 1, nr, DXB(p));
	}
}

int main()
{
	int f, t;
	while(scan_d(n) && scan_d(q))
	{
		pre(1, n, 1);
		while(q --)
		{
			scan_d(f);
			scan_d(t);
			maxx = 0;
			minx = 1000000 + 1;
			query(f, t, 1, n, 1);
			out_number(maxx - minx);
			puts("");
		}
	}
	return 0;
}

