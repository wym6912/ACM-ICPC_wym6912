#define NOSTDCPP
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
const int maxn = 100005;
const int maxm = maxn << 1;
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

int v[maxm], prevv[maxm];
int info[maxn], dep[maxn], size[maxn];
int father[maxn], head[maxn], len[maxn], son[maxn], id[maxn];
bool vis[maxn];
int l, r, ans, cnt = 0;
int N, nedge = 0;

struct edg
{
	int f, t, cost;
}edge[maxn];

inline void insert(int x, int y)
{
	++ nedge;
	v[nedge] = y;
	prevv[nedge] = info[x];
	info[x] = nedge;
}
/*Ê÷Á´ÆÊ·Öbegin*/

void dfs1(int u, int pre, int d)
{
	dep[u] = d;
	father[u] = pre;
	son[u] = 0;
	size[u] = 1;
	for(int i = info[u]; i; i = prevv[i])
	{
		if(v[i] != pre)
		{
			dfs1(v[i], u, d + 1);
			size[u] += size[v[i]];
			if(! son[u] || size[v[i]] > size[son[u]])
				son[u] = v[i];
		}
	}
}

void getpos(int u, int sp)
{
	head[u] = sp;
	id[u] = ++ cnt;
	if(son[u]) getpos(son[u], sp);
	for(int i = info[u]; i; i = prevv[i])
	{
		if(v[i] != son[u] && v[i] != father[u])
			getpos(v[i], v[i]); 
	}
}

/*Ê÷Á´ÆÊ·Öend*/
/*Ïß¶ÎÊ÷begin*/
struct node
{
	int sum, lazy;
}tree[maxm << 1];

void pushup(int p, int l, int r)
{
	tree[p].sum = 0;
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
	tree[p].sum += tree[p].lazy * (r - l + 1);
}

void pushdown(int p, int l, int r)
{
	if(tree[p].lazy)
	{
		int mid = midf(l, r);
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[DXA(p)].sum = tree[p].lazy * (mid - l + 1);
		tree[DXB(p)].sum = tree[p].lazy * (r - mid);
		tree[p].lazy = 0;
	}
}

void pre(int l, int r, int p)
{
	tree[p].lazy = tree[p].sum = 0;
	if(l == r) return;
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int l, int nl, int nr, int p, int cnt)
{
	if(nl == nr)
	{
		tree[p].lazy = tree[p].sum = cnt;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, nl, mid, DXA(p), cnt);
	if(mid < l) update(l, mid + 1, nr, DXB(p), cnt);
	pushup(p, nl, nr);
}

int query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p].sum;
	int mid = midf(nl, nr);
	int ans = 0;
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	return ans;
}
/*Ïß¶ÎÊ÷end*/

void query_sum(int f, int t)
{
	int ans = 0;
	int f1 = head[f], f2 = head[t];
	while(f1 != f2) //ÍùÒ»ÌõÁ´ÉÏ¿¿
	{ 
		if(dep[f1] < dep[f2])swap(f, t), swap(f1, f2);
		ans += query(id[f1], id[f], 1, N, 1);
		f = father[f1], f1 = head[f];
	}
	//printf("%d %d %d\n", f, son[f], t);
	if(f != t)
	{
		if(dep[f] > dep[t])swap(f, t);
		ans += query(id[son[f]], id[t], 1, N, 1);
	}
	out_number(ans);
	puts("");
}

int main()
{
	int f, t, q, nowp;
	int x;
	scan_d(N);
	scan_d(q);
	scan_d(nowp);
	nedge = 0;
	for(int i = 1; i < N; i ++)
	{
		scan_d(edge[i].f);
		scan_d(edge[i].t);
		scan_d(edge[i].cost);
		insert(edge[i].f, edge[i].t);
		insert(edge[i].t, edge[i].f);
	}
	dfs1(1, 0, 1);
	getpos(1, 1);
	pre(1, N, 1);
	for(int i = 1; i < N; i ++)
	{
		if(dep[edge[i].f] < dep[edge[i].t])swap(edge[i].f, edge[i].t);
		update(id[edge[i].f], 1, N, 1, edge[i].cost);
	}
	while(q --)
	{
		scan_d(x);
		scan_d(f);
		switch(x)
		{
			case 1:
				scan_d(t);
				update(id[edge[f].f], 1, N, 1, t);
				break;
			case 0:
				query_sum(nowp, f);
				nowp = f;
				break;
			default:
				assert(x == 0 || x == 1);
		}
	}
	return 0;
}
/*
3 3 1

1 2 1
2 3 2

0 2
1 2 3
0 3

5 5 1

1 2 3
2 3 4
1 4 2
2 5 1

0 3
1 4 3
1 1 4
0 4
0 5
*/
