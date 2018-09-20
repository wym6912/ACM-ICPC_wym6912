//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 500009;
const int maxm = 300009;
const int inf = 1e9 + 20;
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

template <class T>
inline void out_number(T x)
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

int dsu[maxn], dsu_size[maxn];
int find_dsu(int x) {return x == dsu[x] ? x : dsu[x] = find_dsu(dsu[x]);}
void merge(int x, int y)
{
	x = find_dsu(x), y = find_dsu(y);
	dsu[x] = y;
	dsu_size[y] += dsu_size[x];
}


struct node
{
	int l, r, val;
}tree[maxn * 50];

int l, root[maxn], cnt;
void update(int pre, int &now, int nl, int nr, int val)
{
	now = ++ cnt;
	tree[now] = tree[pre];
	++ tree[now].val;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(val <= mid) update(tree[pre].l, tree[now].l, nl, mid, val);
	else update(tree[pre].r, tree[now].r, mid + 1, nr, val);
}
# define lson(_) tree[_].l
# define rson(_) tree[_].r
int kth(int x, int y, int lca, int falca, int nl, int nr, int k)
{
	if(nl == nr) return nl;
	int mid = midf(nl, nr);
	int ans = tree[lson(x)].val + tree[lson(y)].val - tree[lson(lca)].val - tree[lson(falca)].val;
	if(k <= ans) 
		return kth(lson(x), lson(y), lson(lca), lson(falca), nl, mid, k);
	else 
		return kth(rson(x), rson(y), rson(lca), rson(falca), mid + 1, nr, k - ans);
}

struct edge
{
	int to, next;
}edg[maxn << 1];
int fir[maxn], edges;

void addedge(int f, int t)
{
	++ edges;
	edg[edges].to = t;
	edg[edges].next = fir[f];
	fir[f] = edges;
}

int deep[maxn], fa[maxn][22], weight[maxn];

void dfs(int x)
{
	for(int i = 1; i <= 19; ++ i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	deep[x] = deep[fa[x][0]] + 1;
	update(root[fa[x][0]], root[x], 0, inf, weight[x]);
	for(int i = fir[x]; i; i = edg[i].next)
		if(edg[i].to != fa[x][0])
			fa[edg[i].to][0] = x, dfs(edg[i].to);
}

int LCA(int x, int y)
{
	if(deep[x] < deep[y]) swap(x, y);
	for(int i = 19; ~i; -- i) if(deep[fa[x][i]] >= deep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i = 19; ~i; -- i) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int n, m, t;

int main()
{
	int ff, tt, ans, k, lca, rf, rt;
	char str[2];
	scanf("%d", &n);
	scanf("%d %d %d", &n, &m, &t);
	edges = cnt = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", weight + i), dsu[i] = i, dsu_size[i] = 1;
	for(int i = 1; i <= m; ++ i)
	{
		scanf("%d %d", &ff, &tt);
		addedge(ff, tt);
		addedge(tt, ff);
		merge(ff, tt);
	}
	for(int i = 1; i <= n; ++ i) if(! fa[i][0]) dfs(i);
	ans = 0;
	while(t --)
	{
		scanf("\n%s %d %d", str, &ff, &tt);
		ff ^= ans, tt ^= ans;
		switch(str[0])
		{
			case 'Q':
				scanf("%d", &k);
				k ^= ans;
				lca = LCA(ff, tt);
				ans = kth(root[ff], root[tt], root[lca], root[fa[lca][0]], 0, inf, k);
				printf("%d\n", ans);
				break;
			case 'L':
				rf = find_dsu(ff);
				rt = find_dsu(tt);
				if(dsu_size[rf] > dsu_size[rt]) swap(ff, tt);
				addedge(ff, tt);
				addedge(tt, ff);
				merge(ff, tt);
				fa[ff][0] = tt;
				dfs(ff);
				break;
			default:
				assert(str[0] == 'Q' || str[0] == 'L');
		}
	}
	return 0;
}
/*
1 
8 4 8
1 1 2 2 3 3 4 4
4 7
1 8
2 4
2 1
Q 8 7 3
Q 3 5 1
Q 10 0 0 
L 5 4
L 3 2
L 0 7 
Q 9 2 5 
Q 6 1 6 
*/
