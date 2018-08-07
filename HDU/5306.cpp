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

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 1000009;
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
#define cin.tie(0); cin.tie(nullptr);
#define cout.tie(0); cout.tie(nullptr);
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

struct node
{
	int data, ma, se, max_number, tag;
	ll sum;
}tree[maxn << 2];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].ma = max(tree[DXA(p)].ma, tree[DXB(p)].ma);
		/*tree[p].se & tree[p].max_number begin*/
		if(tree[DXA(p)].ma == tree[DXB(p)].ma)
		{
			tree[p].se = max(tree[DXA(p)].se, tree[DXB(p)].se);
			tree[p].max_number = tree[DXA(p)].max_number + tree[DXB(p)].max_number;
		}
		else if(tree[DXA(p)].ma > tree[DXB(p)].ma)
		{
			tree[p].se = max(tree[DXB(p)].ma, max(tree[DXA(p)].se, tree[DXB(p)].se));
			tree[p].max_number = tree[DXA(p)].max_number;
		}
		else 
		{
			tree[p].se = max(tree[DXA(p)].ma, max(tree[DXA(p)].se, tree[DXB(p)].se));
			tree[p].max_number = tree[DXB(p)].max_number;
		}
		/*tree[p].se & tree[p].max_number end*/
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
}

void pushdown(int p, int l, int r)
{
	if(~ tree[p].tag)
	{
		if(tree[DXA(p)].se < tree[p].tag && tree[p].tag < tree[DXA(p)].ma)
		{
			tree[DXA(p)].sum += (ll)tree[DXA(p)].max_number * (ll)(tree[p].tag - tree[DXA(p)].ma);
			tree[DXA(p)].ma = tree[p].tag;
			tree[DXA(p)].tag = tree[p].tag;
		}
		if(tree[DXB(p)].se < tree[p].tag && tree[p].tag < tree[DXB(p)].ma)
		{
			tree[DXB(p)].sum += (ll)tree[DXB(p)].max_number * (ll)(tree[p].tag - tree[DXB(p)].ma);
			tree[DXB(p)].ma = tree[p].tag;
			tree[DXB(p)].tag = tree[p].tag;
		}
		tree[p].tag = -1;
	}
}

void pre(int l, int r, int p)
{
	tree[p].se = -1;
	tree[p].ma = -1;
	tree[p].tag = -1;
	tree[p].sum = 0;
	if(l == r)
	{
		//scan_d(tree[p].data);
		scanf("%d", &tree[p].data);
		tree[p].se = -1;
		tree[p].sum = tree[p].ma = tree[p].data;
		tree[p].max_number = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int l, r, n, m;
int x;
void update(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(tree[p].ma <= x) return ;
		if(tree[p].se < x && x < tree[p].ma)
		{
			tree[p].sum += (ll)tree[p].max_number * (ll)(x - tree[p].ma);
			tree[p].ma = x;
			tree[p].tag = x;
			return ;
		}
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	if(mid < r)  update(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

int query_max(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].ma;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	int ans = -1;
	if(l <= mid) ans = max(ans, query_max(nl, mid, DXA(p)));
	if(mid < r)  ans = max(ans, query_max(mid + 1, nr, DXB(p)));
	pushup(p, nl, nr);
	return ans;
}

ll query_sum(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query_sum(nl, mid, DXA(p));
	if(mid < r)  ans += query_sum(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
	return ans;
}

int main()
{
	int T, type;
	//scan_d(T);
	scanf("%d", &T);
	while(T --)
	{
		//scan_d(n); scan_d(m);
		scanf("%d %d", &n, &m);
		pre(1, n, 1);
		while(m --)
		{
			//scan_d(type);
			scanf("%d", &type);
			switch(type)
			{
				case 0:
					/*
					scan_d(l);
					scan_d(r);
					scan_d(x);
					*/
					scanf("%d %d %d", &l, &r, &x);
					update(1, n, 1);
					break;
				case 1:
					/*
					scan_d(l);
					scan_d(r);
					*/
					scanf("%d %d", &l, &r);
					out_number(query_max(1, n, 1));
					puts("");
					break;
				case 2:
					/*
					scan_d(l);
					scan_d(r);
					*/
					scanf("%d %d", &l, &r);
					out_number(query_sum(1, n, 1));
					puts("");
					break;
				default: 
					assert(type == 1 || type == 2 || type == 0);
			}
			/*
			for(int i = 1; i <= n; i ++)
			{
				l = r = i;
				out_number(query_sum(1, n, 1));
				putchar(i == n ? '\n' : ' ');
			}
			*/
		}
	}
	return 0;
}

