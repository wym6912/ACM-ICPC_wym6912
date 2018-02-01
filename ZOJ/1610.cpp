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
	int lazy;
}node;

typedef struct 
{
	int l, r, c;
}ddd;

ddd q[maxn];

node tree[maxn];

int len[maxn];
int ans[maxn];

int n, maxc;

priority_queue <int, vi, greater <int> > qqq;
map <int, int> mp;

void pre(int l, int r, int p)
{
	RESET(tree);
	RESET(len);
	RESET(ans);
	maxc = 0;
}

void pushdown(int p)
{
	if(tree[p].lazy)
	{
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void update(int l, int r, int nl, int nr, int data, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = data;
		return ;
	}
	else 
	{
		pushdown(p);
		int mid = midf(nl, nr);
		if(l <= mid)update(l, r, nl, mid, data, DXA(p));
		if(mid < r) update(l, r, mid + 1, nr, data, DXB(p));
	}
}

void query(int l, int r, int p)
{
	if(tree[p].lazy)
	{
		for(int i = l; i <= r; i ++)
			ans[i] = tree[p].lazy;
		return ;
	}
	else if(l != r && ! tree[p].lazy)
	{
		int mid = midf(l, r);
		query(l, mid, DXA(p));
		query(mid + 1, r, DXB(p));
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, key, now, before;
	while(scan_d(n))
	{
		key = 1;
		pre(1, 8000, 1);
		while(! qqq.empty())qqq.pop();
		mp.clear();
		for(int i = 1; i <= n; i ++)
		{
			scan_d(q[i].l);
			scan_d(q[i].r);
			scan_d(q[i].c);
			q[i].c ++;
			q[i].r --;
			maxc = max(maxc, q[i].c);
			update(q[i].l, q[i].r, 0, 8000, q[i].c, 1);
		}	
		query(0, 8000, 1);
		c = ans[0];
		for(int i = 1; i <= 8000; i ++)
		{
			if(c != ans[i])
			{
				len[c] ++;
				c = ans[i];
			}
		}
		for(int i = 1; i <= maxc; i ++)
			if(len[i])
				out_number(i - 1), putchar(' '), out_number(len[i]), puts("");
		puts("");
	}
	return 0;
}

