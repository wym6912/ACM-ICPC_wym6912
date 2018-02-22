//#define NOSTDCPP
//#define Cpp11
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
#include <fstream>
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
const int maxn = 50000 * 4;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

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
	ll data, lazy;
}node;

node tree[maxn];
int n;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		if(~ tree[p].lazy)
		{
			tree[p].data = tree[p].lazy * (r - l + 1);
			return ;
		}
		tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data; 
	}
}

void pushdown(int p, int nl, int nr)
{
	if(~ tree[p].lazy)
	{
		int mid = midf(nl, nr);
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[DXA(p)].data = (mid - nl + 1) * tree[p].lazy;
		tree[DXB(p)].data = (nr - mid) * tree[p].lazy;
		tree[p].lazy = -1;
	}
}

void pre(int l, int r, int p)
{
	tree[p].lazy = -1;
	if(l == r)
	{
		tree[p].data = 0;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int query(int l, int r, int nl, int nr, int p)
{
	if(~ tree[p].lazy)
		return tree[p].lazy * (min(r, nr) - max(l, nl) + 1);
	if(l <= nl && nr <= r)
		return tree[p].data;
	pushdown(p, nl, nr);
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
	return ans;
}

void update(int l, int r, int nl, int nr, int val, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = val;
		tree[p].data = val * (nr - nl + 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, val, DXA(p));
	//else pushup(DXA(p), nl, mid);
	if(mid < r) update(l, r, mid + 1, nr, val, DXB(p));
	//else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

void place(int px, int num)
{
	/////check if flowers can be put in this segment/////
	int qq = query(px, n - 1, 0, n - 1, 1);
	if(qq == n - px)
	{
		puts("Can not put any one.");
		return ;
	}
	////end./////
	int l = px, r = n - 1, mid, fmid;
	/////find the first 0/////
	int find0 = n - 1;
	while(l <= r)
	{
		mid = midf(l, r);
		fmid = query(px, mid, 0, n - 1, 1);
		if(mid - px - fmid >= 0)
		{
			find0 = min(find0, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	out_number(find0); 
	putchar(' ');
	/////find the first 0 over///// 
	/////find the last 0/////
	int findl = n + 1;
	l = find0, r = n - 1;
	num = min(num, n - px - qq);
	while(l <= r)
	{
		mid = midf(l, r);
		fmid = mid - find0 + 1 - query(find0, mid, 0, n - 1, 1);
		if(fmid == num)
		{
			findl = min(findl, mid);
			r = mid - 1;
		}
		else if(fmid > num)
		{
			r = mid - 1;
		}
		else l = mid + 1;
	}
	out_number(findl);
	puts("");
	/////find the last 0 over///// 
	update(find0, findl, 0, n - 1, 1, 1);
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, m, k, a, b;
	scan_d(T);
	while(T --)
	{
		scan_d(n);
		scan_d(m);
		pre(0, n - 1, 1);
		while(m --)
		{
			scan_d(k);
			scan_d(a);
			scan_d(b);
			switch(k)
			{
				case 1:
					place(a, b);
					break;
				case 2:
					out_number(query(a, b, 0, n - 1, 1));
					puts("");
					update(a, b, 0, n - 1, 0, 1);
					break;
				default:
					assert(false);
			}
				
		}
		puts("");
	}
	return 0;
}

