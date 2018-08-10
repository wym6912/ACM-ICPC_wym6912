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
typedef unsigned int ui;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int maxn = 500009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;
const ll inf = (1ll << 61);

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
	ll mi, sei, min_number;
	//mi, sei, min_number = ??? ??? ????????
	ll tmx, cover, add;
}tree[maxn << 2];

bool __update_max(int p, int l, int r, ll x)
{
	if(x <= tree[p].mi) return true;
	if(x < tree[p].sei)
	{
		tree[p].mi = x;
		tree[p].tmx = max(x, tree[p].tmx);
		return true;
	}
	return false;
}

bool __update_add(int p, int l, int r, ll x)
{
	if(tree[p].sei != inf) tree[p].sei += x;
	if(tree[p].cover != inf) tree[p].cover += x; // cover 优先级高于 add 
	else tree[p].add += x;
	tree[p].mi += x;
	if(tree[p].tmx != -inf) tree[p].tmx += x;
	return true;
}
 
bool __update_cover(int p, int l, int r, ll x)
{//将剩下两个标记清除 
	tree[p].cover = x;
	tree[p].mi = x;
	tree[p].sei = inf;
	tree[p].min_number = r - l + 1;
	tree[p].add = 0;
	tree[p].tmx = -inf;
	return true;
}

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].mi = min(tree[DXA(p)].mi, tree[DXB(p)].mi);
		/*tree[p].sei & tree[p].min_number begin*/
		if(tree[DXA(p)].mi == tree[DXB(p)].mi)
		{
			tree[p].sei = min(tree[DXA(p)].sei, tree[DXB(p)].sei);
			tree[p].min_number = tree[DXA(p)].min_number + tree[DXB(p)].min_number;
		}
		else if(tree[DXA(p)].mi < tree[DXB(p)].mi)
		{
			tree[p].sei = min(tree[DXB(p)].mi, min(tree[DXA(p)].sei, tree[DXB(p)].sei));
			tree[p].min_number = tree[DXA(p)].min_number;
		}
		else
		{
			tree[p].sei = min(tree[DXA(p)].mi, min(tree[DXA(p)].sei, tree[DXB(p)].sei));
			tree[p].min_number = tree[DXB(p)].min_number;
		}
		/*tree[p].sei & tree[p].min_number end*/
	}
}

void pushdown(int p, int l, int r)
{
	if(l == r) return;
	int mid = midf(l, r);
	if(tree[p].add)
	{
		__update_add(DXA(p), l, mid, tree[p].add);
		__update_add(DXB(p), mid + 1, r, tree[p].add);
		tree[p].add = 0;
	}
	if(tree[p].cover != inf)
	{
		__update_cover(DXA(p), l, mid, tree[p].cover);
		__update_cover(DXB(p), mid + 1, r, tree[p].cover);
		tree[p].cover = inf;
	}
	if(tree[p].tmx != -inf)
	{
		__update_max(DXA(p), l, mid, tree[p].tmx);
		__update_max(DXB(p), mid + 1, r, tree[p].tmx);
		tree[p].tmx = -inf;
	}
}

void pre(int l, int r, int p)
{
	tree[p].sei = inf;
	tree[p].tmx = -inf;
	tree[p].add = 0;
	tree[p].cover = inf;
	if(l == r)
	{
		//scan_d(tree[p].data);
		scanf("%lld", &tree[p].mi);
		tree[p].sei = inf;
		tree[p].min_number = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int l, r, n, m;
ll x;

void update_paint(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__update_cover(p, nl, nr, x);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_paint(nl, mid, DXA(p));
	if(mid < r)  update_paint(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void update_add(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__update_add(p, nl, nr, x);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_add(nl, mid, DXA(p));
	if(mid < r)  update_add(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void update_max(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(__update_max(p, nl, nr, x)) return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_max(nl, mid, DXA(p));
	if(mid < r)  update_max(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

ll query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(tree[p].mi == 0)
			return tree[p].min_number;
		else return 0;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query(nl, mid, DXA(p));
	if(mid < r)  ans += query(mid + 1, nr, DXB(p));
	return ans;
}

ll query_2(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].mi;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid) ans += query_2(nl, mid, DXA(p));
	if(mid < r)  ans += query_2(mid + 1, nr, DXB(p));
	return ans;
}


int main()
{
	int n, m, type;
	scanf("%d %d", &n, &m);
	pre(1, n, 1);
	/*
	for(int p = 1; p <= 13; p ++)
	{
		printf("Tree: mi = %lld, min_number = %lld, add = %lld, cover = %lld, sei = %lld\n", 
		tree[p].mi, tree[p].min_number, tree[p].add, tree[p].cover, tree[p].sei);
	}
	*/
	while(m --)
	{
		scanf("%d %d %d", &type, &l, &r);
		switch(type)
		{
			case 1:
				scanf("%lld", &x);
				update_paint(1, n, 1);
				break;
			case 2:
				scanf("%lld", &x);
				update_add(1, n, 1);
				x = 0;
				update_max(1, n, 1);
				/*
				for(int i = 1; i <= n; i ++)
				{
					l = r = i;
					printf("%lld%c", query_2(1, n, 1), i == n ? '\n' : ' ');
				}
				*/
				break;
			case 3:
				printf("%lld\n", query(1, n, 1));
				break;
			default:
				assert(type == 1 || type == 2 || type == 3);
		}
		/*
		for(int p = 1; p <= 13; p ++)
		{
			printf("Tree: mi = %lld, min_number = %lld, add = %lld, cover = %lld, sei = %lld\n", 
			tree[p].mi, tree[p].min_number, tree[p].add, tree[p].cover, tree[p].sei);
		}
		*/
	}
	return 0;
}

