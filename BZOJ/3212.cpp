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

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)
# pragma comment(linker, "/STACK:1024000000,1024000000")

# ifdef Linux_System
# define getchar getchar_unlocked
# define putchar putchar_unlocked
# endif

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100000 * 4;
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

inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n' || ch == '\r')ch = getchar();
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
	ll data, tag;
	int l, r;
}node;

node tree[maxn];

int n, q;

void pushup(int p, int l, int r)
{
	tree[p].data = 0;
	if(r > l)
	{
		tree[p].data += tree[DXA(p)].data + tree[DXB(p)].data;
	}
	tree[p].data += tree[p].tag * (r - l + 1);
	//自己已经更新 
}

void pre(int l, int r, int p)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		scan_d(tree[p].tag);
		pushup(p, l, r);//注意在计算的位置 
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

ll query(int l, int r, int nl, int nr, int p, ll tags)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].data + (tags) * (nr - nl + 1);
		//因为 tree[p].data 就是自己的 tag * 自己的长度了 
	}
	else
	{
		ll ans = 0ll;
		int mid = midf(nl, nr);
		if(l <= mid)
			ans += query(l, r, nl, mid, DXA(p), tags + tree[p].tag);
		if(mid < r)
			ans += query(l, r, mid + 1, nr, DXB(p), tags + tree[p].tag);
		return ans;
	}
}

void update(int l, int r, int nl, int nr, ll d, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].tag += d; //注意只累加了一个
	}
	else 
	{
		int mid = midf(nl, nr);
		if(l <= mid)
			update(l, r, nl, mid, d, DXA(p));
		if(mid < r)
			update(l, r, mid + 1, nr, d, DXB(p));
	} 
	pushup(p, nl, nr);
}

int main()
{
	scan_d(n);
	scan_d(q);
	RESET(tree);
	ll x;
	pre(1, n, 1);
	//for(int i = 1; i <= n; i ++)
	//{
	//	scan_d(x);
	//	update(i, i, 1, n, x, 1);
	//}
	char ch;
	int f, t;
	while(q --)
	{
		//getchar();
		//ch = getchar();
		scan_ch(ch);
		assert(ch == 'Q' || ch == 'C');
		if(ch == 'Q')
		{
			scan_d(f);
			scan_d(t);
			out_number(query(f, t, 1, n, 1, 0));
			puts("");
		}
		if(ch == 'C')
		{
			scan_d(f);
			scan_d(t);
			scan_d(x);
			update(f, t, 1, n, x, 1);
		}
	}
	return 0;
}

