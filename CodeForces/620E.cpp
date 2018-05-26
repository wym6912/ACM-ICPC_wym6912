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
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 400009 << 2;
const int maxm = 400009;
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

int n;

typedef struct
{
	int to, next;
}edge;

edge edg[maxn];
int edgen, fir[maxm], p;

void addedge(int f, int t)
{
	edgen ++;
	edg[edgen].to = t;
	edg[edgen].next = fir[f];
	fir[f] = edgen;
}

int dfs_l[maxm], dfs_r[maxm];
bool visited[maxm];
ll data_dfs[maxm];
ll data[maxm];

void dfs_s(int x, ll dd)
{
	if(visited[x])return;
	visited[x] = true;
	++ p;
	dfs_l[x] = p;
	for(int i = fir[x]; i; i = edg[i].next)
		dfs_s(edg[i].to, data[edg[i].to]);
		//注意这里，已经把父亲结点的值记录下来了 
	dfs_r[x] = p;
	data_dfs[dfs_l[x]] = dd; //注意是取 [l, r] 中的 l 
}

typedef struct
{
	ll sum, lazy;
}node;

node tree[maxn];

void pushup(int p, int l, int r)
{
	//tree[p].sum = 0;
	tree[p].sum = tree[DXA(p)].sum | tree[DXB(p)].sum;
	//tree[p].sum |= tree[p].lazy;
}

void pushdown(int p, int l, int r)
{
	if(tree[p].lazy)
	{
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[DXA(p)].sum = tree[DXB(p)].sum = tree[p].sum = tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void pre(int l, int r, int p)
{
	tree[p].lazy = 0;
	if(l == r)
	{
		tree[p].lazy = tree[p].sum = data_dfs[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int l, int r, int nl, int nr, ll val, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = val;
		tree[p].sum = val;// 更新子树
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, val, DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, val, DXB(p));
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
	if(l <= mid)ans |= query(l, r, nl, mid, DXA(p));
	if(mid < r) ans |= query(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, f, t, m, aa;
	ll x, ans;
	edgen = 0;
	p = 0;
	RESET(fir);
	RESET(visited);
	scan_d(n);
	scan_d(m);
	for(int i = 1; i <= n; i ++)scan_d(data[i]), data[i] = (1ll << data[i]);
	//for(int i = 1; i <= n; i ++)cout << data[i] << ' ';cout << endl;
	for(int i = 1; i < n; i ++)
	{
		scan_d(f);
		scan_d(t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs_s(1, data[1]);
	RESET(tree);
	pre(1, p, 1);
	//for(int i = 1; i <= n * 2; i ++)
	//	cout << i << ' ' << tree[i].lazy << ' ' << tree[i].sum << endl;
	while(m --)
	{
		scan_d(f);
		switch(f)
		{
			case 2:
				scan_d(t);
				ans = query(dfs_l[t], dfs_r[t], 1, p, 1);
				aa = 0;
				while(ans)
				{
					if(ans & 1)aa ++;
					ans >>= 1;
				}
				out_number(aa);
				puts("");
				break;
			case 1:
				scan_d(t);//place
				scan_d(x);//value
				x = 1ll << x;
				//cout << "X = " << x << ", Data[t] = " << data[t] << endl;
				update(dfs_l[t], dfs_r[t], 1, p, x, 1);
				//for(int i = 1; i <= n * 2; i ++)
				//	cout << i << ' ' << tree[i].lazy << ' ' << tree[i].sum << endl;
				//data[t] = x;
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
/*
7 10
1 1 1 1 1 1 1
1 2
1 3
1 4
3 5
3 6
3 7
1 3 2
2 1
1 4 3
2 1
1 2 5
2 1
1 6 4
2 1
2 2
2 3
*/
