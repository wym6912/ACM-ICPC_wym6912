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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 400009;
const int maxm = 100009;
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

typedef struct
{
	ll data, lazy, max_data;
}node;

node tree[maxn];
int n, m;

void pushup(int p, int l, int r)
{
	tree[p].data = 0;
	if(l < r)
	{
		tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data;
		tree[p].max_data = max(tree[DXA(p)].max_data, tree[DXB(p)].max_data);
	}
}

void pushdown(int p, int l, int r)
{
	if(tree[p].lazy)
	{
		int mid = midf(l, r);
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void pre(int l, int r, int p)
{
	tree[p].data = tree[p].lazy = 0;
	if(l == r)
	{
		scan_d(tree[p].data);
		tree[p].max_data = tree[p].data;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update_1(int l, int nl, int nr, int p, ll d) // modify
{
	if(nl == nr)
	{
		tree[p].lazy = 0;
		tree[p].max_data = tree[p].data = d; 
		return ;
	}
	//pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_1(l, nl, mid, DXA(p), d);
	//else pushup(DXA(p), nl, mid);
	if(mid < l) update_1(l, mid + 1, nr, DXB(p), d);
	//else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

void update_2(int l, int r, int nl, int nr, int p, ll d) // modulo
{
	if(tree[p].max_data < d)return ;
	if(nl == nr)
	{
		tree[p].lazy = d;
		tree[p].data %= d;
		tree[p].max_data = tree[p].data;
		return ;
	}
	//pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update_2(l, r, nl, mid, DXA(p), d);
	//else pushup(DXA(p), nl, mid);
	if(mid < r) update_2(l, r, mid + 1, nr, DXB(p), d);
	//else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].data;
	}
	//pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	//else pushup(DXA(p), nl, mid);
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	//else pushup(DXB(p), mid + 1, nr);
	//pushup(p, nl, nr);
	return ans;
}

int main()
{
	int f, t, op;
	ll arg;
	scan_d(n);
	scan_d(m);
	pre(1, n, 1);
	while(m --)
	{
		scan_d(op);
		scan_d(f);
		switch(op)
		{
			case 1:
				scan_d(t);
				out_number(query(f, t, 1, n, 1));
				puts("");
				break;
			case 2:
				scan_d(t);
				scan_d(arg);
				update_2(f, t, 1, n, 1, arg);
				break;
			case 3:
				scan_d(arg);
				update_1(f, 1, n, 1, arg);
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
