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
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

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
const int maxn = 200009 << 1;
const int maxm = 200009;
const ll inf = 1e18;
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

struct node
{
	int l, r, sum;
}tree[maxn * 25];

int data, tree_tot, root[maxm];
void update(int pre, int &now, int nl, int nr)
{
	now = ++ tree_tot;
	tree[now] = tree[pre];
	++ tree[now].sum;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(data <= mid) update(tree[pre].l, tree[now].l, nl, mid);
	else update(tree[pre].r, tree[now].r, mid + 1, nr);
}

int query(int x, int y, int lca, int falca, int nl, int nr)
{
	if(nl == nr) return nl;
	int sum1 = tree[tree[y].l].sum - tree[tree[x].l].sum, 
		sum2 = tree[tree[falca].l].sum - tree[tree[lca].l].sum, mid = midf(nl, nr);
	if(sum1 == 0 && sum2 == 0) return nl;
	if(sum1 + sum2 <= mid - nl) return query(tree[x].l, tree[y].l, tree[lca].l, tree[falca].l, nl, mid);
	else return query(tree[x].r, tree[y].r, tree[lca].r, tree[falca].r, mid + 1, nr);
}

struct eddy
{
	int to, next;
}edg_2[maxn];
int fir[maxm], eddy_tot;
int deep[maxm], ffather[maxm], son[maxm], size[maxm], head[maxm];
int id[maxm], pid[maxm], id_tot;
int A[maxm];
int n, m, u, v, ans, lca;

void addedge(int f, int t)
{
	edg_2[++ eddy_tot].to = t;
	edg_2[eddy_tot].next = fir[f];
	fir[f] = eddy_tot;
}

void dfs1(int u, int pre, int d)
{
	deep[u] = d;
	ffather[u] = pre;
	son[u] = 0;
	size[u] = 1;
	data = A[u];
	update(root[id[pre]], root[id_tot], 1, n + 1);
	for(int i = fir[u]; i; i = edg_2[i].next)
	{
		if(edg_2[i].to != pre)
		{
			dfs1(edg_2[i].to, u, d + 1);
			size[u] += size[edg_2[i].to];
			if(! son[u] || size[edg_2[i].to] > size[son[u]])
				son[u] = edg_2[i].to;
		}
	}
}

void getpos(int u, int sp, int pre)
{
	head[u] = sp;
	id[u] = ++ id_tot;
	pid[id_tot] = u;
	data = A[u];
	update(root[id[pre]], root[id_tot], 1, n + 1);
	if(son[u]) getpos(son[u], sp, u);
	for(int i = fir[u]; i; i = edg_2[i].next)
	{
		if(edg_2[i].to != son[u] && edg_2[i].to != ffather[u])
			getpos(edg_2[i].to, edg_2[i].to, u); 
	}
}

int LCA(int u, int v)
{
    int f1 = head[u], f2 = head[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        u = ffather[f1]; f1 = head[u];
    }
    if(u == v) return u;
    if(deep[u] > deep[v]) swap(u, v);
    return u;
}

int main()
{
	scanf("%d", &n);
	eddy_tot = tree_tot = 0;
	for(register int i = 1, f, t; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	for(register int i = 1; i <= n; ++ i) scanf("%d", A + i), ++ A[i];
	dfs1(1, -1, 1);
	getpos(1, 1, 0);
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d %d", &u, &v);
		lca = LCA(u, v);
		//if(deep[u] < deep[v]) swap(u, v);
		//cout << lca << endl;
		ans = query(root[id[lca]], root[id[u]], root[id[ffather[lca]]], root[id[v]], 1, n + 1) - 1;
		printf("%d\n", ans);
	}
	return 0;
}
/*
5
1 2
2 4
2 5
1 3
0 1 4 2 3
5
1 1
1 2
2 3
1 4
4 5
*/

