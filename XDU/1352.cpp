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

typedef struct
{
	int info;
	int lazy; // 表示要消耗多少票
}node;

node tree[maxn];
int minx;

void pushup(int p, int l, int r)
{
	tree[p].info = 0;
	if(l < r)
		tree[p].info = min(tree[DXA(p)].info, tree[DXB(p)].info);
	tree[p].info += tree[p].lazy;
}

void pre(int nl, int nr, int num, int p)
{
	if(nl == nr)
	{
		tree[p].info = num;
		tree[p].lazy = num;
		return ;
	}
	tree[p].lazy = 0;
	int mid = midf(nl, nr);
	pre(nl, mid, num, DXA(p));
	pre(mid + 1, nr, num, DXB(p));
	tree[p].info = num;
}

void query(int l, int r, int nl, int nr, int lz, int p)
{
	if(l <= nl && nr <= r)
	{
		//lz += tree[p].lazy;
		minx = min(tree[p].info + lz, minx);
		//cout << minx << ' ' << tree[p].lazy << ' ' << nl << ' ' << nr << endl;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)query(l, r, nl, mid, lz + tree[p].lazy, DXA(p));
	if(mid < r)query(l, r, mid + 1, nr, lz + tree[p].lazy, DXB(p));
}

void update(int l, int r, int nl, int nr, int c, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy += c;
		pushup(p, nl, nr);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, c, DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, c, DXB(p));
	pushup(p, nl, nr);
}

int n, m, q;

int main()
{
	scan_d(n, m, q);
	int f, t, rq;
	pre(1, n, m, 1);
	while(q --)
	{
		scan_d(f, t, rq);
		bool flag = true;
		minx = maxm;
		query(min(f, t), max(t, f) - 1, 1, n, 0, 1);
		flag = (minx >= rq);
		if(! flag)puts("NO");
		else
		{
			puts("YES");
			update(min(f, t), max(t, f) - 1, 1, n, -rq, 1);
		}
	}
	return 0;
}

