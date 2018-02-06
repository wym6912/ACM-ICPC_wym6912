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

# pragma comment(linker, "/STACK:1024000000,1024000000")

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

///dfs sequence

typedef struct
{
	int to, next;
}edge;

edge edg[maxn];
int fir[maxn], tot, n, T;
int deg[maxn];
int dfs_f[maxn], dfs_t[maxn], st;

void addedge(int f, int t)
{
	tot ++;
	edg[tot].to = t;
	edg[tot].next = fir[f];
	fir[f] = tot;
}

void dfs(int x)// NOTICE: It can only get the dfs sequence!
{
	st ++; //注意这里的写法 
	dfs_f[x] = st;
	for(int i = fir[x]; i; i = edg[i].next)
		dfs(edg[i].to);
	dfs_t[x] = st;
}
///dfs sequence

///segement tree
typedef struct
{
	int lazy;
	int task; 
}node;

node tree[maxm];

void pushdown(int p)
{
	if(~ tree[p].lazy)
	{
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[DXA(p)].task = tree[DXB(p)].task = tree[p].lazy;
		tree[p].lazy = -1;
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].task = -1;
		tree[p].lazy = -1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	tree[p].lazy = -1;
}

void update(int l, int r, int nl, int nr, int x, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = x;
		tree[p].task = x;
		return ;
	}
	pushdown(p);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, x, DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, x, DXB(p));
}

int query(int x, int nl, int nr, int p)
{
	if(nl == nr)
	{
		return tree[p].task;
	}
	pushdown(p);
	int mid = midf(nl, nr);
	if(x <= mid)return query(x, nl, mid, DXA(p));
	if(mid < x) return query(x, mid + 1, nr, DXB(p));
}

///segement tree

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scan_d(T);
	int f, t, q;
	char ch;
	for(int Casen = 1; Casen <= T; Casen ++)
	{
		scan_d(n);
		RESET(fir);
		RESET(deg);
		RESET(dfs_f);
		RESET(dfs_t);
		tot = 0;
		st = 0;
		for(int i = 1; i < n; i ++)
		{
			scan_d(f, t);
			addedge(t, f);
			deg[f] ++;
		}
		for(int i = 1; i <= n; i ++)
			if(! deg[i])
			{
				dfs(i);
				break;
		 	}
		//for(int i = 1; i <= n; i ++)
		//	cout << i << ' ' << dfs_f[i] << ' ' << dfs_t[i] << endl;
		printf("Case #%d:\n", Casen);
		scan_d(q);
		pre(1, n, 1);
		while(q --)
		{
			scan_ch(ch);
			switch(ch)
			{
				case 'T':
					scan_d(f, t);
					update(dfs_f[f], dfs_t[f], 1, n, t, 1);
					break;
				case 'C':
					scan_d(f);
					out_number(query(dfs_f[f], 1, n, 1)); //也要把它映射到数组上啊！ 
					puts("");
					break;
				default:
					assert(false);
			}
		}
	}
	return 0;
}

