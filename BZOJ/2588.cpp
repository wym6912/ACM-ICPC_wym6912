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
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
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

int n, m;
int A[maxn];

struct Edge
{
    int to, next;
}edge[maxn << 1];
int head[maxn], tot, top[maxn], fa[maxn], deep[maxn], num[maxn], p[maxn], fp[maxn];
int son[maxn];
int pos;
//p 表示在主席树上的位置
 
void init()
{
    tot = 0;
    RESET_(head, -1);
    pos = 1;
    RESET_(son, -1);
}

void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}

void dfs1(int u,int pre,int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void getpos(int u,int sp)
{
    top[u] = sp;
    if(son[u] != -1)
    {
        p[u] = pos++;
        fp[p[u]] = u;
        getpos(son[u],sp);
    }
    else
    {
        p[u] = pos++;
        fp[p[u]] = u;
        return;
    }
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

struct node
{
	int l, r, sum;
}tree[maxn * 40];

vi dis;
int id(int x) {return lower_bound(dis.begin(), dis.end(), x) - dis.begin();}

int tot_tree, root[maxn], ansl[maxn], ansr[maxn], siz;

void build(int nl, int nr, int &p, int pre, int val, int place)
{
	p = ++ tot_tree;
	tree[p] = tree[pre];
	tree[p].sum += val;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(mid >= place) build(nl, mid, tree[p].l, tree[pre].l, val, place);
	else build(mid + 1, nr, tree[p].r, tree[pre].r, val, place);
}

int query(int l, int r, int nl, int nr, int place)
{
	if(nl == nr) return nl;
	int mid = midf(nl, nr), sum = tree[tree[r].l].sum - tree[tree[l].l].sum;
	if(mid >= place) return query(tree[l].l, tree[r].l, nl, mid, place);
	return query(tree[l].r, tree[r].r, mid + 1, nr, place - sum);
}

int ans(int f, int t, int k)
{
	int ff = top[f], tt = top[t];
	int ppp = 0;
	while(ff != tt)
	{
		if(deep[ff] < deep[tt]) swap(ff, tt), swap(f, t);
		ansr[ppp] = root[p[f]], ansl[ppp] = root[p[ff] - 1];
		ppp ++;
		f = fa[ff];
		ff = top[f];
	}
	if(deep[f] > deep[t]) swap(f, t);
	ansr[ppp] = root[p[t]], ansl[ppp] = root[p[f] - 1];
	ppp ++;
	int sl = 0, sr = siz - 1;
	while(sl < sr)
	{
		int sum = 0, mid = midf(sl, sr);
		for(int i = 0; i < ppp; ++ i)
			sum += tree[tree[ansr[i]].l].sum - tree[tree[ansl[i]].l].sum;
		if(sum < k)
		{
			k -= sum;
			sl = mid + 1;
			for(int i = 0; i < ppp; ++ i)
			{
				ansr[i] = tree[ansr[i]].r;
				ansl[i] = tree[ansl[i]].r;
			}
		}
		else 
		{
			sr = mid;
			for(int i = 0; i < ppp; ++ i)
			{
				ansr[i] = tree[ansr[i]].l;
				ansl[i] = tree[ansl[i]].l;
			}
		}
	}
	return dis[sl];
}

int main()
{
	int f, t, k, lastans;
	init();
	tot_tree = 0;
	scan_d(n);
	scan_d(m);
	for(int i = 1; i <= n; ++ i)
		scan_d(A[i]), dis.push_back(A[i]);
	for(int i = 1; i < n; ++ i)
	{
		scan_d(f); scan_d(t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs1(1, 0, 0);
	getpos(1, 1);
	sort(dis.begin(), dis.end());
	dis.erase(unique(dis.begin(), dis.end()), dis.end());
	siz = dis.size();
	for(int i = 1; i <= n; ++ i)
		build(0, siz - 1, root[i], root[i - 1], 1, id(A[fp[i]]));
	lastans = 0;
	while(m --)
	{
		scan_d(f); scan_d(t); scan_d(k);
		f ^= lastans;
		lastans = ans(f, t, k);
		out_number(lastans);
		puts("");
	}
	return 0;
}
/*
7 7 
4 10 2 2 5 5 4 
1 2 
2 3 
3 4 
4 5 
5 6 
6 7 
1 7 1 
1 7 2 
1 7 3 
1 7 4 
1 7 5 
1 7 6 
1 7 7 
*/

