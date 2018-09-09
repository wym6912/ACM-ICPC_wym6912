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

struct node
{
	int data, ma, se, max_number, tag, tag_add;
	ll sum;
	bool up_t;
}tree[maxn << 2];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].ma = max(tree[DXA(p)].ma, tree[DXB(p)].ma);
		/*tree[p].se & tree[p].max_number begin*/
		if(tree[DXA(p)].ma == tree[DXB(p)].ma)
		{
			tree[p].se = max(tree[DXA(p)].se, tree[DXB(p)].se);
			tree[p].max_number = tree[DXA(p)].max_number + tree[DXB(p)].max_number;
		}
		else if(tree[DXA(p)].ma > tree[DXB(p)].ma)
		{
			tree[p].se = max(tree[DXB(p)].ma, max(tree[DXA(p)].se, tree[DXB(p)].se));
			tree[p].max_number = tree[DXA(p)].max_number;
		}
		else
		{
			tree[p].se = max(tree[DXA(p)].ma, max(tree[DXA(p)].se, tree[DXB(p)].se));
			tree[p].max_number = tree[DXB(p)].max_number;
		}
		/*tree[p].se & tree[p].max_number end*/
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
}

void pushdown(int p, int l, int r)
{
	if(! (l < r)) return ;
	int mid = midf(l, r);
	if(tree[p].tag_add)
	{
		tree[DXA(p)].tag_add += tree[p].tag_add;
		tree[DXB(p)].tag_add += tree[p].tag_add;
		tree[DXA(p)].sum += 1ll * (mid - l + 1) * tree[p].tag_add;
		tree[DXB(p)].sum += 1ll * (r - mid) * tree[p].tag_add;
		tree[DXA(p)].ma += tree[p].tag_add;
		tree[DXB(p)].ma += tree[p].tag_add;
		if(tree[DXA(p)].se != -1e9) tree[DXA(p)].se += tree[p].tag_add;
		if(tree[DXB(p)].se != -1e9) tree[DXB(p)].se += tree[p].tag_add;
		tree[p].tag_add = 0;
	}
	if(tree[p].up_t)
	{
		if(tree[DXA(p)].se < tree[p].ma && tree[p].ma < tree[DXA(p)].ma)
		{
			tree[DXA(p)].sum += 1ll * tree[DXA(p)].max_number * (tree[p].ma - tree[DXA(p)].ma);
			tree[DXA(p)].ma = tree[p].ma;
			tree[DXA(p)].up_t = true;
		}
		if(tree[DXB(p)].se < tree[p].ma && tree[p].ma < tree[DXB(p)].ma)
		{
			tree[DXB(p)].sum += 1ll * tree[DXB(p)].max_number * (tree[p].ma - tree[DXB(p)].ma);
			tree[DXB(p)].ma = tree[p].ma;
			tree[DXB(p)].up_t = true;
		}
		tree[p].up_t = false;
	}
}

void pre(int l, int r, int p)
{
	tree[p].se = -1e9;
	tree[p].up_t = false;
	tree[p].tag_add = 0;
	tree[p].tag = 0;
	tree[p].sum = 0;
	if(l == r)
	{
		//scan_d(tree[p].data);
		scanf("%d", &tree[p].data);
		tree[p].sum = tree[p].ma = tree[p].data;
		tree[p].max_number = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int l, r, n, m;
int x;
void update_mod(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		//pushdown_2(p, nl, nr);
		if(tree[p].ma <= x) return ;
		if(tree[p].se < x && x < tree[p].ma)
		{
			tree[p].sum += 1ll * tree[p].max_number * (x - tree[p].ma);
			tree[p].ma = x;
			tree[p].tag = x;
			tree[p].up_t = true;
			return ;
		}
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_mod(nl, mid, DXA(p));
	if(mid < r)  update_mod(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void update_add(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		//pushdown_3(p, nl, nr);
		tree[p].tag_add += x;
		tree[p].sum += 1ll * (nr - nl + 1) * x;
		tree[p].ma += x;
		if(tree[p].se != -1e9) tree[p].se += x;
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_add(nl, mid, DXA(p));
	if(mid < r)  update_add(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

ll query_sum(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query_sum(nl, mid, DXA(p));
	if(mid < r)  ans += query_sum(mid + 1, nr, DXB(p));
	return ans;
}

int main()
{
	int T, type;
	//scan_d(T);
	//scanf("%d", &T);
	T = 1;
	while(T --)
	{
		//scan_d(n); scan_d(m);
		scanf("%d", &n);
		pre(1, n, 1);
		scanf("%d", &m);
		while(m --)
		{
			//scan_d(type);
			scanf("%d", &type);
			switch(type)
			{
				case 1:
					scanf("%d %d %d", &l, &r, &x);
					update_mod(1, n, 1);
					break;
				case 2:
					scanf("%d %d %d", &l, &r, &x);
					update_add(1, n, 1);
					break;
				case 3:
					scanf("%d %d", &l, &r);
					out_number(query_sum(1, n, 1));
					puts("");
					break;
				default:
					assert(type == 1 || type == 2 || type == 3);
			}



		}
	}
	return 0;
}

/*
20
-379 580 -1382 1658 -984 247 -1936 1051 -2722 2717 -2520 2348 -1067 2602 -1671 418 -633 1468 -564 2646
4
2 9 11 2
1 2 16 86
2 4 14 -6
3 9 19
*/
/*
5
-1020 1000 1009 283 -102
4
2 2 4 2
1 2 5 86
2 3 5 -6
3 4 4
*/

