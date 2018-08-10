//#define NOSTDCPP
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
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100003 << 2;
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
	ll data, ma, mi, tag;
}node;

node tree[maxn];

int n, m;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data + tree[p].tag * (r - l + 1);
		tree[p].ma = max(tree[DXA(p)].ma, tree[DXB(p)].ma), tree[p].ma += tree[p].tag;
		tree[p].mi = min(tree[DXA(p)].mi, tree[DXB(p)].mi), tree[p].mi += tree[p].tag;
	}
}

void pre(int l, int r, int p)
{
	tree[p].ma = -1;
	tree[p].mi = 1e17;
	tree[p].tag = 0;
	if(l == r)
	{
		scan_d(tree[p].data);
		tree[p].ma = tree[p].mi = tree[p].data;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void __add(int p, int l, int r, ll x)
{
	tree[p].tag += x;
	tree[p].ma += x;
	tree[p].mi += x;
	tree[p].data += x * (r - l + 1);
}

int l, r;
ll x;

void update_add(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		__add(p, nl, nr, x);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update_add(nl, mid, DXA(p));
	if(mid < r)  update_add(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void update_sqrt(int nl, int nr, int p, ll tag)
{
	if(l <= nl && nr <= r) //判断要不要往下更新 这里保证复杂度为 O(n log n log log n) 
	{
		ll c1, c2;
		c1 = (ll) sqrt(tree[p].mi + tag) + 1;
		c2 = (ll) sqrt(tree[p].ma + tag);
		ll cha;
		if(tree[p].ma == tree[p].mi) // [nl, nr]所有值都相同 直接暴力更新 把开根转换成减法 
		{
			cha = tree[p].mi + tag - (ll) sqrt(tree[p].mi + tag);
			__add(p, nl, nr, -cha);
			return ;
		}
		else if(tree[p].ma - tree[p].mi == 1 && c1 == c2)
		{
			cha = tree[p].mi + tag - (ll) sqrt(tree[p].mi + tag);
			__add(p, nl, nr, -cha);
			return ;
		}
	}
	int mid = midf(nl, nr);
	if(l <= mid) update_sqrt(nl, mid, DXA(p), tree[p].tag + tag);
	if(mid < r)  update_sqrt(mid + 1, nr, DXB(p), tree[p].tag + tag);
	pushup(p, nl, nr);
}

ll query(int nl, int nr, int p, ll tag)
{
	if(l <= nl && nr <= r)
		return tree[p].data + tag * (nr - nl + 1);
	else
	{
		ll ans = 0;
		int mid = midf(nl, nr);
		if(l <= mid) ans += query(nl, mid, DXA(p), tag + tree[p].tag);
		if(mid < r)  ans += query(mid + 1, nr, DXB(p), tag + tree[p].tag);
		return ans;
	}
}

int main()
{
    //freopen("ex_data2.in", "r", stdin);
    //freopen("ex_data2.ans", "w", stdout);
	int q;
	scan_d(n);
	scan_d(m);
	pre(1, n, 1);
	/*
	for(int i = 1; i <= n; i ++)
	{
		l = r = i;
		printf("%d%c", query(1, n, 1, 0), (i == n ? '\n' : ' '));
	}
	*/
	while(m --)
	{
		scan_d(q);
		scan_d(l);
		scan_d(r);
		switch(q)
		{
			case 1:
				scan_d(x);
				update_add(1, n, 1);
				/*
				for(int i = 1; i <= n; i ++)
				{
					l = r = i;
					printf("%d%c", query(1, n, 1, 0), (i == n ? '\n' : ' '));
				}
				*/
				break;
			case 2:
				update_sqrt(1, n, 1, 0);
				/*
				for(int i = 1; i <= n; i ++)
				{
					l = r = i;
					printf("%d%c", query(1, n, 1, 0), (i == n ? '\n' : ' '));
				}
				*/
				break;
			case 3:
				out_number(query(1, n, 1, 0));
				puts("");
				/*
				for(int i = 1; i <= n; i ++)
				{
					l = r = i;
					printf("%d%c", query(1, n, 1, 0), (i == n ? '\n' : ' '));
				}
				*/
				break;
			default:
				assert(false);
		}
	}
	return 0;
}

/*
5 5
1 2 3 4 5
1 3 5 2
2 1 4
3 2 4
2 3 5
3 1 5
*/

