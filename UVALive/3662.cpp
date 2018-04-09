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
const int maxn = 300009;
const int INF = 0x3fffffff;

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

inline int lowbit(const int &x){return x & -x;}

struct edge
{
	int u, v, c;
	edge(int _u = 0, int _v = 0, int _c = 0) : u(_u), v(_v), c(_c) {}
	bool operator < (const edge &b) const {return c < b.c;}
}edg[maxn << 2];

struct node
{
	int key, id;
	node(int _k = 0, int _i = 0) : key(_k), id(_i) {}
	bool operator < (const node &b) const {return key < b.key;}
}tree[maxn];

int idx[maxn], idy[maxn], bak[maxn], x[maxn], y[maxn], id[maxn], father[maxn];

inline int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}

inline bool cmp1(const int &i, const int &j)
{
	return x[i] - y[i] > x[j] - y[j] || (x[i] - y[i] == x[j] - y[j] && y[i] > y[j]);
}

inline bool cmp2(const int &i, const int &j)
{
	return x[i] - y[i] < x[j] - y[j] || (x[i] - y[i] == x[j] - y[j] && y[i] > y[j]);
}

inline bool cmp3(const int &i, const int &j)
{
	return x[i] + y[i] < x[j] + y[j] || (x[i] + y[i] == x[j] + y[j] && y[i] > y[j]);
}

inline bool cmp4(const int &i, const int &j)
{
	return x[i] + y[i] < x[j] + y[j] || (x[i] + y[i] == x[j] + y[j] && y[i] < y[j]);
}

inline void disc(int x[], int idx[], int n)
{
	for(int i = 0; i <= n; i ++)
		bak[i] = x[i];
	sort(bak + 1, bak + n + 1, greater <int> ());
	int p = unique(bak + 1, bak + 1 + n) - bak - 1;
	for(int i = 1; i <= n; i ++)
		idx[i] = lower_bound(bak + 1, bak + 1 + p, x[i], greater <int> ()) - bak;
}

inline void addedge(int &N, const int &u, const int &v)
{
	edg[N ++] = edge(u, v, abs(x[u] - x[v]) + abs(y[u] - y[v]));
}

inline int getmin(const int &p)
{
	node tmp(INF);
	for(int i = p; i; i ^= lowbit(i))
	{
		if(tree[i].id != -1)
			tmp = min(tmp, tree[i]);
	}
	return tmp.key == INF ? -1 : tmp.id;
}

inline void insert(const int &n, const int &p, const node &it)
{
	for(int i = p; i <= n; i += lowbit(i))
		if(tree[i].id == -1 || it < tree[i])
			tree[i] = it;
}

inline ll mmst(int x[], int y[], int n)
{
	disc(x, idx, n);
	disc(y, idy, n);
	int N = 1;
	
	for(int i = 1; i <= n; i ++)
		id[i] = i;
	sort(id + 1, id + 1 + n, cmp1);
	for(int i = 1; i <= n; i ++)
		tree[i].id = -1;
	for(int i = 1; i <= n; i ++)
	{
		int u = id[i], v = getmin(idy[u]);
		if(v != -1)addedge(N, u, v);
		insert(n, idy[u], node(x[u] + y[u], u));
	}
	
	for(int i = 1; i <= n; i ++)
		id[i] = i;
	sort(id + 1, id + 1 + n, cmp2);
	for(int i = 1; i <= n; i ++)
		tree[i].id = -1;
	for(int i = 1; i <= n; i ++)
	{
		int u = id[i], v = getmin(idx[u]);
		if(v != -1)addedge(N, u, v);
		insert(n, idx[u], node(x[u] + y[u], u));
	}
	
	for(int i = 1; i <= n; i ++)
		id[i] = i;
	sort(id + 1, id + 1 + n, cmp3);
	for(int i = 1; i <= n; i ++)
		tree[i].id = -1;
	for(int i = 1; i <= n; i ++)
	{
		int u = id[i], v = getmin(idy[u]);
		if(v != -1)addedge(N, u, v);
		insert(n, idy[u], node(-x[u] + y[u], u));
	}
	
	for(int i = 1; i <= n; i ++)
		id[i] = i;
	sort(id + 1, id + 1 + n, cmp4);
	for(int i = 1; i <= n; i ++)
		tree[i].id = -1;
	for(int i = 1; i <= n; i ++)
	{
		int u = id[i], v = getmin(idx[u]);
		if(v != -1)addedge(N, u, v);
		insert(n, idx[u], node(x[u] - y[u], u));
	}
	
	sort(edg + 1, edg + 1 + N);
	for(int i = 1; i <= n; i ++)
		father[i] = i;
	ll ans = 0;
	for(int i = 1; i <= N; i ++)
	{
		int u = find(edg[i].u), v = find(edg[i].v);
		if(u != v)
		{
			father[u] = v;
			ans += edg[i].c;
			//k --;
		}
		//if(k == 0)return edg[i].c;
	}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, Casen = 0;
	while(scan_d(n) && n)
	{
		RESET(edg);
		RESET(tree);
		RESET(id);
		RESET(idx);
		RESET(idy);
		for(int i = 1; i <= n; i ++)
		{
			scan_d(x[i]);
			scan_d(y[i]);
		}
		printf("Case %d: Total Weight = %lld\n", ++ Casen, mmst(x, y, n));
	}
	return 0;
}

