#define NOSTDCPP
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
const int maxn = 500000 * 4;
const int inf = (1 << 30);
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
	ll lsum, rsum, sum, maxsum;
}node;

node tree[maxn];
int n, m;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
		tree[p].lsum = max(tree[DXA(p)].lsum, tree[DXA(p)].sum + tree[DXB(p)].lsum);
		tree[p].rsum = max(tree[DXB(p)].rsum, tree[DXB(p)].sum + tree[DXA(p)].rsum);
		tree[p].maxsum = max(max(tree[DXA(p)].maxsum, tree[DXB(p)].maxsum), 
		                  tree[DXA(p)].rsum + tree[DXB(p)].lsum);
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(tree[p].maxsum);
		tree[p].sum = tree[p].lsum = tree[p].rsum = tree[p].maxsum;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int x, int nl, int nr, ll val, int p)
{
	if(nl == nr)
	{
		tree[p].sum = tree[p].rsum = tree[p].lsum = tree[p].maxsum = val;
		return ;
	}
	int mid = midf(nl, nr);
	if(x <= mid)update(x, nl, mid, val, DXA(p));
	else if(mid < x)update(x, mid + 1, nr, val, DXB(p));
	pushup(p, nl, nr);
}

node query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p];
	}
	int mid = midf(nl, nr);
	if(mid < l)
		return query(l, r, mid + 1, nr, DXB(p));
	if(r <= mid)
		return query(l, r, nl, mid, DXA(p));
	node a, b, c;
	c = query(l, r, mid + 1, nr, DXB(p));
	b = query(l, r, nl, mid, DXA(p));
	a.maxsum = max(max(b.maxsum, c.maxsum), b.rsum + c.lsum);
	a.lsum = max(b.lsum, b.sum + c.lsum);
	a.rsum = max(c.rsum, c.sum + b.rsum);
	return a;
}

int main()
{
	ll f, t, type;
	scan_d(n);
	scan_d(m);
	pre(1, n, 1);
	while(m --)
	{
		scan_d(type);
		scan_d(f);
		scan_d(t);
		switch(type)
		{
			case 1:
				out_number(query(min(f, t), max(f, t), 1, n, 1).maxsum);
				puts("");
				break;
			case 2:
				update(f, 1, n, t, 1);
				break;
			default:
				assert(type == 1 || type == 2);
		}
	}
	return 0;
}

/*
5 3
-1 -2 -3 -4 -5
1 4 2
1 1 5
1 2 3
*/

