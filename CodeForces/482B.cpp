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
const int maxn = 400009;
const int maxm = 100009;
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

typedef struct 
{
	ll lazytag, sum;
	bool isused; 
}node;

node tree[maxn];

void pre(int l, int r, int p)
{
	tree[p].isused = false;
	tree[p].lazytag = 0;
	tree[p].sum = 0;
	if(l == r)
	{
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
}

void pushdown(int p, int l, int r)
{
	if(tree[p].isused)
	{
		tree[DXA(p)].isused = tree[DXB(p)].isused = tree[p].isused;
		tree[DXA(p)].lazytag |= tree[p].lazytag;
		tree[DXB(p)].lazytag |= tree[p].lazytag;
		tree[DXA(p)].sum |= tree[p].lazytag;
		tree[DXB(p)].sum |= tree[p].lazytag;
		tree[p].isused = false;
		tree[p].lazytag = 0;
	}
}

void pushup(int p, int l, int r)
{
	if(l < r)
		tree[p].sum = tree[DXA(p)].sum & tree[DXB(p)].sum;
}

ll d;
bool isok;

void update(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].isused = true;
		tree[p].lazytag |= d;
		tree[p].sum |= d;
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, DXA(p));
	//else pushup(DXA(p), nl, mid);
	if(mid < r) update(l, r, mid + 1, nr, DXB(p));
	//else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

ll query(int l, int nl, int nr, int p)
{
	if(nl == nr)
	{
		return tree[p].sum;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)return query(l, nl, mid, DXA(p));
	//else pushup(DXA(p), nl, mid);
	if(mid < l) return query(l, mid + 1, nr, DXB(p));
	//else pushup(DXB(p), mid + 1, nr);
}

ll query_seg(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0x7fffffffffffffff;
	if(l <= mid)ans &= query_seg(l, r, nl, mid, DXA(p));
	//else pushup(DXA(p), nl, mid);
	if(mid < r) ans &= query_seg(l, r, mid + 1, nr, DXB(p));
	//else pushup(DXB(p), mid + 1, nr);
	return ans;
}

int n, m, l, r;

struct query_segment
{
	int l, r;
	ll d;
}qs[maxm];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(scan_d(n) && scan_d(m))
	{
		isok = true;
		pre(1, n, 1);
		for(int i = 1; i <= m; i ++)
		{
			scan_d(qs[i].l);
			scan_d(qs[i].r);
			scan_d(qs[i].d);
			d = qs[i].d;
			update(qs[i].l, qs[i].r, 1, n, 1);
		}
		for(int i = 1; i <= m; i ++)
			if(query_seg(qs[i].l, qs[i].r, 1, n, 1) != qs[i].d)
			{
				isok = false;
				break;
			}
		isok ? puts("YES") : puts("NO");
		if(isok)
		{
			for(int i = 1; i <= n; i ++)
				out_number(query(i, 1, n, 1)), putchar(' ');
			puts("");
		}
	}
	return 0;
}

