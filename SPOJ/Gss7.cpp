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
const ll TAG_MAX = 100000;
const ll inf = 0x3fffffffffffffff;
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

int n;

struct Edge
{
    int to, next;
}edge[maxn << 1];
int head[maxn], tot, top[maxn], fa[maxn], deep[maxn], num[maxn], p[maxn], fp[maxn];
int son[maxn];
int pos;

typedef struct
{
	ll lsum, rsum, sum, maxsum, tag;
}node;

node tree[maxn << 2];

ll A[maxn];

void __tag(int p, ll val, int len)
{
	tree[p].tag = val;
	tree[p].lsum = tree[p].rsum = tree[p].maxsum = val * len;
	tree[p].sum = val * len;
}

void __max_node(node &a, const node &b, const node &c)
{
    a.sum = b.sum + c.sum;
	a.maxsum = max(max(b.maxsum, c.maxsum), b.rsum + c.lsum);
	a.lsum = max(b.lsum, b.sum + c.lsum);
	a.rsum = max(c.rsum, c.sum + b.rsum);
}

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
		tree[p].lsum = max(tree[DXA(p)].lsum, tree[DXA(p)].sum + tree[DXB(p)].lsum);
		tree[p].rsum = max(tree[DXB(p)].rsum, tree[DXB(p)].sum + tree[DXA(p)].rsum);
		tree[p].maxsum = max(max(tree[DXA(p)].maxsum, tree[DXB(p)].maxsum), tree[DXA(p)].rsum + tree[DXB(p)].lsum);
	}
}

void pushdown(int p, int l, int r)
{
	if(tree[p].tag != TAG_MAX)
	{
		int mid = midf(l, r);
		__tag(DXA(p), tree[p].tag, mid - l + 1);
		__tag(DXB(p), tree[p].tag, r - mid);
		tree[p].tag = TAG_MAX;
	}
}

void pre(int l, int r, int pp)
{
	tree[pp].tag = TAG_MAX;
	//tree[pp].lsum = tree[pp].rsum = tree[pp].maxsum = -inf;
	tree[pp].sum = 0;
	if(l == r)
	{
		tree[pp].lsum = tree[pp].rsum = tree[pp].maxsum = tree[pp].sum = A[fp[l]];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(pp));
	pre(mid + 1, r, DXB(pp));
	pushup(pp, l, r);
}

int l, r;
ll val;
node query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r) return tree[p];
	int mid = midf(nl, nr);
	pushdown(p, nl, nr);
	if(mid < l) return query(mid + 1, nr, DXB(p));
	if(r <= mid) return query(nl, mid, DXA(p));
	node a, b, c;
	c = query(mid + 1, nr, DXB(p));
	b = query(nl, mid, DXA(p));
	__max_node(a, b, c);
	return a;
}

void update(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__tag(p, val, nr - nl + 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	if(mid < r)  update(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void init()
{
    tot = 0;
    RESET_(head, -1);
    pos = 1;
    RESET_(son, -1);
    RESET_(deep, -1);
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

void getpos(int u, int sp)
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
    for(int i = head[u] ; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v, v);
    }
}

void __update__(int u, int v)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        l = p[f1], r = p[u];
		update(1, n, 1);
        u = fa[f1]; f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = p[u], r = p[v];
    //cout << ">>" << l << ' ' << r << endl;
    update(1, n, 1);
}

stack <node> dq1, dq2;
node ans1, ttmp, ans2, ans3;

ll __query__(int u, int v)
{
    int f1 = top[u], f2 = top[v];
    bool rev = false;
    while(! dq1.empty()) dq1.pop();
    while(! dq2.empty()) dq2.pop();
    ll ans = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
            rev ^= true;
        }
        l = p[f1], r = p[u];
		if(! rev) dq1.push(query(1, n, 1));
		else dq2.push(query(1, n, 1));
        u = fa[f1]; f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v), rev ^= true;
    l = p[u], r = p[v];
    if(rev) dq1.push(query(1, n, 1));
    else dq2.push(query(1, n, 1));
    //cout << l << ' ' << r << endl;
    bool u1 = false, u2 = false;
    //ans1.maxsum = ans1.lsum = ans1.rsum = -inf;
    //ans1.sum = 0;
    //ans3 = ans1;
    //cout << "size = " << dq1.size() << ' ' << dq2.size() << endl;
    while(! dq1.empty())
    {
    	ttmp = dq1.top();
    	dq1.pop();
        //cout << "Lsum = " << ttmp.lsum << ", Rsum = " << ttmp.rsum << ", Maxsum = " << ttmp.maxsum << ", Sum = " << ttmp.sum << endl;
    	ans2 = ans1;
    	if(u1) __max_node(ans1, ans2, ttmp);
    	else u1 = true, ans1 = ttmp;
	}
	swap(ans1.lsum, ans1.rsum);
	//cout << "ans1: Lsum = " << ans1.lsum << ", Rsum = " << ans1.rsum << ", MaxSum = " << ans1.maxsum << ", Sum = " << ans1.sum << endl;
	//assert(u1);
	while(! dq2.empty())
    {
    	ttmp = dq2.top();
    	dq2.pop();
    	ans2 = ans3;
    	//cout << "Lsum = " << ttmp.lsum << ", Rsum = " << ttmp.rsum << ", Maxsum = " << ttmp.maxsum << ", Sum = " << ttmp.sum << endl;
    	if(u2) __max_node(ans3, ans2, ttmp);
    	else u2 = true, ans3 = ttmp;
	}
	//cout << "ans3: Lsum = " << ans3.lsum << ", Rsum = " << ans3.rsum << ", MaxSum = " << ans3.maxsum << ", Sum = " << ans3.sum << endl;
	//assert(u2);
	if(u1 && u2)
	{
	    //cout << "ans2: Lsum = " << ans2.lsum << ", Rsum = " << ans2.rsum << ", MaxSum = " << ans2.maxsum << ", Sum = " << ans2.sum << endl;
        //cout << ans1.lsum << ' ' << ans1.rsum + ans3.lsum << ' ' << ans1.maxsum << ' ' << ans3.maxsum << endl;
        __max_node(ans2, ans1, ans3);
        //cout << "ans2: Lsum = " << ans2.lsum << ", Rsum = " << ans2.rsum << ", MaxSum = " << ans2.maxsum << ", Sum = " << ans2.sum << endl;
        return ans2.maxsum;
    }
    if(u1) return ans1.maxsum;
    if(u2) return ans3.maxsum;
    assert(false);
}

int main()
{
	int f, t, q, type;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%lld", A + i);
	init();
	for(int i = 1; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	dfs1(1, -1, 0);
	getpos(1, 1);
	pre(1, n, 1);
	scanf("%d", &q);
	while(q --)
	{
		scanf("%d %d %d", &type, &l, &r);
		if(deep[l] > deep[r]) swap(l, r);
		switch(type)
		{
			case 1:
				printf("%lld\n", max(__query__(l, r), 0ll));
				break;
			case 2:
				scanf("%lld", &val);
				__update__(l, r);
				break;
			default:
				assert(type == 1 || type == 2);
		}
	}
	return 0;
}
/*
12
2354 8995 6660 9648 8119 7591 4462 1208 478 7230 815 7824
1 2
1 3
2 4
4 5
5 6
2 7
7 8
2 9
8 10
8 11
7 12
1
1 3 11

5
-1102 -899 7058 -8459 -9769
1 2
2 3
2 4
4 5
7
1 2 4
1 3 1
2 4 2 600
1 5 4
1 3 1
1 4 1
1 4 4

20
8633 3974 -1389 2846 4052 -8806 -8266 -3153 -7191 4863 8921 -8321 -6339 6107 -7701 6753 -4060 -155 9036 9418
1 2
1 3
3 4
4 5
2 6
4 7
4 8
1 9
9 10
10 11
8 12
7 13
5 14
4 15
5 16
13 17
11 18
15 19
18 20
20
1 5 3
2 8 15 3674
2 11 19 2522
2 3 18 1755
2 17 16 809
2 8 3 6923
2 12 5 1236
2 5 4 858
1 19 7
2 19 10 8903
1 6 8
2 4 6 8006
1 8 15
1 19 13
1 12 11
2 2 2 4294
1 11 20
1 14 7
2 5 16 6346
2 6 10 9009

15
-1588 -8841 1640 -4769 -4831 6793 6309 7604 8338 -8194 -7844 772 1262 -3374 2992
1 2
1 3
3 4
4 5
3 6
3 7
3 8
8 9
9 10
4 11
11 12
4 13
1 14
5 15
1
1 11 10


*/

