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
const int maxn = 1000009;
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
	int ma, se, max_number, mi, sei, min_number;
	//ma, se, max_number = ??? ??? ????????
	//mi, sei, min_number = ??? ??? ????????
	bool upd_min, upd_max;
	int tmx, tmi;
	ll sum;
}tree[maxn << 2];

bool __update_max(int p, int l, int r, int x)
{
	if(x <= tree[p].mi) return true;
	if(x < tree[p].sei)
	{
		tree[p].sum += (ll)tree[p].min_number * (ll)(x - tree[p].mi);
		tree[p].mi = x;
		tree[p].ma = max(tree[p].ma, x);
		tree[p].se = max(tree[p].se, x);
    	if(tree[p].ma == x)
		{
			tree[p].sei = 1e9;
			tree[p].se = -1e9;
			tree[p].max_number = tree[p].min_number = r - l + 1;
		}
		//T[t].tmx=min(T[t].tmn=min(T[t].tmn,x),T[t].tmx);
		tree[p].tmi = max(tree[p].tmx = max(tree[p].tmx, x), tree[p].tmi);
		if(tree[p].tmi != -1e9) tree[p].upd_min = true;
		tree[p].upd_max = true;
		return true;
	}
	return false;
}

bool __update_min(int p, int l, int r, int x)
{
	if(x >= tree[p].ma) return true;
	if(x > tree[p].se)
	{
		tree[p].sum += (ll)tree[p].max_number * (ll)(x - tree[p].ma);
		tree[p].ma = x;
		tree[p].mi = min(tree[p].mi, x);
		tree[p].sei = min(tree[p].sei, x);
    	if(tree[p].mi == x)
		{
			tree[p].sei = 1e9;
			tree[p].se = -1e9;
			tree[p].max_number = tree[p].min_number = r - l + 1;
		}
		//T[t].tmx=min(T[t].tmn=min(T[t].tmn,x),T[t].tmx);
		tree[p].tmx = min(tree[p].tmi = min(tree[p].tmi, x), tree[p].tmx);
		if(tree[p].tmx != 1e9) tree[p].upd_max = true;
		tree[p].upd_min = true;
		return true;
	}
	return false;
}

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
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
}

void pushdown(int p, int l, int r)
{
	if(l == r) return;
	int mid = midf(l, r);
	if(tree[p].upd_min)
	{
		__update_min(DXA(p), l, mid, tree[p].tmi);
		__update_min(DXB(p), mid + 1, r, tree[p].tmi);
		tree[p].tmi = 1e9;
		tree[p].upd_min = false;
	}
	if(tree[p].upd_max)
	{
		__update_max(DXA(p), l, mid, tree[p].tmx);
		__update_max(DXB(p), mid + 1, r, tree[p].tmx);
		tree[p].tmx = -1e9;
		tree[p].upd_max = false;
	}
}

void pre(int l, int r, int p)
{
	tree[p].se = -1e9;
	tree[p].ma = -1e9;
	tree[p].mi = 1e9;
	tree[p].sei = 1e9;
	tree[p].tmx = -1e9;
	tree[p].tmi = 1e9;
	tree[p].upd_max = tree[p].upd_min = false;
	if(l == r)
	{
		//scan_d(tree[p].data);
		scanf("%d", &tree[p].mi);
		tree[p].sum = tree[p].ma = tree[p].mi;
		tree[p].max_number = tree[p].min_number = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int l, r, n, m;
int x;
void update_min(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(__update_min(p, nl, nr, x)) return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_min(nl, mid, DXA(p));
	if(mid < r)  update_min(mid + 1, nr, DXB(p));
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

ll query_sum(int nl, int nr, int p)
{
	pushdown(p, nl, nr);
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
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
	//freopen("4.in", "r", stdin);
	//freopen("4.ans", "w", stdout);
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
					/*
					scan_d(l);
					scan_d(r);
					scan_d(x);
					*/
					scanf("%d %d %d", &l, &r, &x);
					update_min(1, n, 1);
					break;
				case 2:
					scanf("%d %d %d", &l, &r, &x);
					update_max(1, n, 1);
					break;
				case 3:
					/*
					scan_d(l);
					scan_d(r);
					*/
					scanf("%d %d", &l, &r);
					out_number(query_sum(1, n, 1));
					puts("");
					/*
					for(int i = 1; i <= n; i ++)
                    {
                        l = r = i;
                        out_number(query_sum(1, n, 1));
                        putchar(i == n ? '\n' : ' ');
                    }
                    */
					break;
				default:
					assert(type == 1 || type == 2 || type == 3);
			}



		}
	}
	return 0;
}


