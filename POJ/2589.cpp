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

int father[maxn], siz[maxn];
int find(int x)
{
	if(x == father[x])return x;
	else
	{
		int m = father[x] = find(father[x]);
		siz[x] = siz[m];
		return m;
	}
}
void merge(int x, int y)
{
	x = find(father[x]);
	y = find(father[y]);
	if(siz[x] < siz[y])
	{
		siz[y] += siz[x];
		father[x] = y;
		siz[x] = siz[y];
	}
	else
	{
		siz[x] += siz[y];
		father[y] = x;
		siz[y] = siz[x];
	}
}

struct node
{
	int sum;
}tree[maxn << 2];

void pushup(int p, int l, int r)
{
	tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
}

void pre(int l, int r, int p)
{
	tree[p].sum = 0;
	if(l == r)
	{
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
}

void update(int l, int nl, int nr, int p, int d)
{
	if(nl == nr)
	{
		tree[p].sum += d;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, nl, mid, DXA(p), d);
	if(mid < l) update(l, mid + 1, nr, DXB(p), d);
	pushup(p, nl, nr);
}

int query_pl(int k, int nl, int nr, int p)
{
	//cout << p << ' ' << tree[p].sum << ' ' << k << endl;
	//assert(tree[p].sum <= k);
	if(nl == nr)return nl;
	int mid = midf(nl, nr);
	if(tree[DXB(p)].sum >= k)return query_pl(k, mid + 1, nr, DXB(p));
	else return query_pl(k - tree[DXB(p)].sum, nl, mid, DXA(p));
}

int n, m, type, f, t, fs, ts, ns, ss;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scan_d(n);
	scan_d(m);
	RESET(tree);
	update(1, 1, n, 1, n);
	//ss = n;
	for(int i = 1; i <= n; i ++)
		father[i] = i, siz[i] = 1;
	while(m --)
	{
		scan_d(type);
		switch(type)
		{
			case 0:
				scan_d(f);
				scan_d(t);
				find(f);
				find(t);
				fs = siz[f];
				ts = siz[t];
				//update(siz[f], 1, n, 1, -1);
				//update(siz[t], 1, n, 1, -1);
				if(find(f) != find(t))
				{
					merge(find(f), find(t));
					ns = siz[find(f)];
					update(fs, 1, n, 1, -1);
					update(ts, 1, n, 1, -1);
					update(ns, 1, n, 1, 1);
				}
				break;
			case 1:
				scan_d(f);
				out_number(query_pl(f, 1, n, 1));
				puts("");
		}
	}
	return 0;
}

