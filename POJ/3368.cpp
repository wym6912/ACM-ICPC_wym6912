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
const int maxn = 100005 << 2;
const int maxm = 100007;
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

struct node
{
	int lsum, rsum, maxsum;
	node(int lsum = 0, int rsum = 0, int maxsum = 0) : lsum(lsum), rsum(rsum), maxsum(maxsum) {}
}tree[maxn];

const node null;

int n;
ll data[maxm];

void pushup(int l, int r, int p)
{
	int mid = midf(l, r);
	if(l < r)
	{
		tree[p].maxsum = max(tree[DXB(p)].maxsum, tree[DXA(p)].maxsum);
		tree[p].lsum = tree[DXA(p)].lsum;
		tree[p].rsum = tree[DXB(p)].rsum;
		// ×óº¢×ÓÓÒ¶ËºÍÓÒº¢×Ó×ó¶ËÏàµÈ
		if(data[mid] == data[mid + 1])
		{
			tree[p].maxsum = max(tree[p].maxsum, tree[DXA(p)].rsum + tree[DXB(p)].lsum);
		}
		// ×óº¢×Ó×ó¶ËºÍÓÒº¢×Ó×ó¶ËÏàµÈ
		if(data[l] == data[mid + 1])
		{
			tree[p].lsum += tree[DXB(p)].lsum;
		}
		// ×óº¢×ÓÓÒ¶ËºÍÓÒº¢×ÓÓÒ¶ËÏàµÈ
		if(data[mid] == data[r])
		{
			tree[p].rsum += tree[DXA(p)].rsum;
		}
	}
}

void pre(int l, int r, int p)
{
	tree[p].lsum = tree[p].rsum = tree[p].maxsum = 0;
	if(l == r)
	{
		tree[p].lsum = tree[p].rsum = tree[p].maxsum = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	//cout << p << ' ' << l << ' ' << r << ' ' << tree[p].maxsum << endl;
	pushup(l, r, p);
	//cout << p << ' ' << l << ' ' << r << ' ' << tree[p].maxsum << endl;
}

node query(int l, int r, int nl, int nr, int p)
{
	if(nr < l || r < nl)
	{
		return null;
	}
	if(l <= nl && nr <= r)
		return tree[p];
	int mid = midf(nl, nr);
	node a, b, c;
	c = query(l, r, mid + 1, nr, DXB(p));
	b = query(l, r, nl, mid, DXA(p));
	a.maxsum = max(max(b.maxsum, c.maxsum), 1);
	a.lsum = b.lsum;
	a.rsum = c.rsum;
	// ×óº¢×ÓÓÒ¶ËºÍÓÒº¢×Ó×ó¶ËÏàµÈ
	if(data[mid] == data[mid + 1])
	{
		a.maxsum = max(a.maxsum, b.rsum + c.lsum);
	}
	// ×óº¢×Ó×ó¶ËºÍÓÒº¢×Ó×ó¶ËÏàµÈ
	if(data[nl] == data[mid + 1])
	{
		a.lsum += c.lsum;
	}
	// ×óº¢×ÓÓÒ¶ËºÍÓÒº¢×ÓÓÒ¶ËÏàµÈ
	if(data[mid] == data[nr])
	{
		a.rsum += b.rsum;
	}
	return a;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q, f, t;
	while(scan_d(n) && n)
	{
		scan_d(q);
		for(int i = 1; i <= n; i ++)
			scan_d(data[i]);
		pre(1, n, 1);
		while(q --)
		{
			scan_d(f);
			scan_d(t);
			tree[0] = query(f, t, 1, n, 1);
			out_number(max(tree[0].maxsum, max(tree[0].lsum, tree[0].rsum)));
			puts("");
		}
	}
	return 0;
}
/*
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
*/
