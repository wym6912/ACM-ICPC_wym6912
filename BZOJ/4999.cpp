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
const int maxn = 100009;
const int maxm = 300009;
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

int n, m;
struct edge
{
	int to, next;
}edg[maxm];
int fir[maxn], nedge;

inline void addedge(int f, int t)
{
	edg[++ nedge].to = t;
	edg[nedge].next = fir[f];
	fir[f] = nedge;
}

int deep[maxn], father[maxn], son[maxn], size[maxn], head[maxn], id[maxn], cnt_HLD;

void dfs1(int u, int fa, int d)
{
	deep[u] = d;
	father[u] = fa;
	son[u] = 0;
	size[u] = 1;
	for(int i = fir[u]; i; i = edg[i].next)
	{
		int v = edg[i].to;
		if(v != fa)
		{
			dfs1(v, u, d + 1);
			size[u] += size[v];
			if(! son[u] || size[v] > size[son[u]])
				son[u] = v;
		}
	}
}

void getpos(int u, int sp)
{
	head[u] = sp;
	id[u] = ++ cnt_HLD;
	if(son[u]) getpos(son[u], sp);
	for(int i = fir[u]; i; i = edg[i].next)
	{
		int v = edg[i].to;
		if(v != son[u] && v != father[u])
			getpos(v, v);
	}
}

inline void init_HLD()
{
	cnt_HLD = 0;
	RESET(fir);
	RESET(son);
	RESET(father);
	RESET_(deep, -1);
	RESET(size);
	RESET(head);
}

struct node
{
	int l, r, sum;
}tree[maxm * 50];
int CMT_cnt, root[maxm];

inline void init_CMT()
{
	CMT_cnt = 0;
	RESET(root);
}

int l, r, v;
void update(int nl, int nr, int &p)
{
	if(! p) p = ++ CMT_cnt;
	tree[p].sum += v;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, tree[p].l);
	else update(mid + 1, nr, tree[p].r);
}

int query(int nl, int nr, int p)
{
	if(! p) return 0;
	if(l <= nl && nr <= r) return tree[p].sum;
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans += query(nl, mid, tree[p].l);
	if(mid < r)  ans += query(mid + 1, nr, tree[p].r);
	return ans;
}

inline int __ans__(int u, int v, int d)
{
    int f1 = head[u], f2 = head[v], ans = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        l = id[f1], r = id[u];
        ans += query(1, n, root[d]);
        u = father[f1]; f1 = head[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = id[u], r = id[v];
    ans += query(1, n, root[d]);
    return ans;
}

map <int, int> mp;
int A[maxn], MAP_cnt;

int main()
{
	int f, t, d;
	char ch;
	scanf("%d %d", &n, &m);
	MAP_cnt = 0;
	for(int i = 1; i <= n; ++ i) 
	{
		scanf("%d", A + i);
		if(! mp[A[i]]) mp[A[i]] = ++ MAP_cnt;
	}
	for(int i = 1; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs1(1, -1, 0);
	getpos(1, 1);
	v = 1;
	for(int i = 1; i <= n; ++ i)
	{
		l = id[i];
		update(1, n, root[mp[A[i]]]);
	}
	while(m --)
	{
		scanf("\n%c %d %d", &ch, &f, &t);
		switch(ch)
		{
			case 'C':
				if(! mp[t]) mp[t] = ++ MAP_cnt;
				l = id[f];
				v = -1;
				update(1, n, root[mp[A[f]]]);
				v = 1;
				update(1, n, root[mp[t]]);
				A[f] = t;
				break;
			case 'Q':
				scanf("%d", &d);
				if(! mp[d]) puts("0");
				else printf("%d\n", __ans__(f, t, mp[d]));
				break;
			default:
				assert(ch == 'C' || ch == 'Q');
		}
		//if(CMT_cnt >= maxm){while(true); puts("GG");}
	}
	return 0;
}
/*
5 6
10 20 30 40 50
1 2
1 3
3 4
3 5
Q 2 3 40
C 1 40
Q 2 3 40
Q 4 5 30
C 3 10
Q 4 5 30
*/

