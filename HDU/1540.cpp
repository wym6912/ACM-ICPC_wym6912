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
	int size;
}node;

node tree[maxn];
bool used[maxn];

int n, o, d;

stack <int> st;

void pushup(int p)
{
	tree[p].size = tree[DXA(p)].size + tree[DXB(p)].size;
}

void reset(int l, int r, int p)
{
	RESET(tree);
	while(! st.empty())st.pop();
	RESET_(used, true);
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		if(l)tree[p].size = 1;
		else tree[p].size = 0;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

void update(int q, int nl, int nr, bool isreset, int p)
{
	if(nl == q && nr == q && ! isreset)
	{
		tree[p].size = 0;
		used[q] = false;
		return ;
	}
	if(nl == q && nr == q && isreset)
	{
		tree[p].size = 1;
		used[q] = true;
		return ;
	}
	int mid = midf(nl, nr);
	if(q <= mid)update(q, nl, mid, isreset, DXA(p));
	if(q > mid) update(q, mid + 1, nr, isreset, DXB(p));
	pushup(p);
}

int query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p].size;
	int ans = 0;
	int mid = midf(nl, nr);
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	return ans;
}

int query_ans(int d)
{
	int l = 0, r = d, a = 1, b = n, mid;
	while(l <= r)
	{
		mid = midf(l, r);
		if(query(mid + 1, d, 0, n, 1) == d - mid)
		{
			a = mid + 1;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	l = d - 1, r = n;
	while(l <= r)
	{
		mid = midf(l, r);
		if(query(d, mid, 0, n, 1) == mid - d + 1)
		{
			b = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	//cout << a << ' ' << b << endl;
	return b - a + 1;
}

int query_2(int q, int nl, int nr, int p)
{
	if(nl == nr)
	{
		return nl;
	}
 	int mid = midf(nl, nr);
 	if(q <= tree[DXA(p)].size)
 		return query_2(q, nl, mid, DXA(p));
 	else return query_2(q, mid + 1, nr, DXB(p));
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char ch;
	int a, b;
	while(scan_d(n) && scan_d(o))
	{
		reset(1, n, 1);
		pre(0, n, 1);
		while(o --)
		{
			scan_ch(ch);
			switch(ch)
			{
				case 'D':
					scan_d(d);
					st.push(d);
					update(d, 0, n, false, 1);
					break;
				case 'Q':
					scan_d(d);
					if(used[d])
					{
						out_number(query_ans(d));
					}
					else 
						out_number(0);
					puts("");
					break;
				case 'R':
					if(! st.empty())
					{
						d = st.top();
						st.pop();
						update(d, 0, n, true, 1);
					}
					break;
				default:
					assert(ch == 'D' || ch == 'Q' || ch == 'R');
			}
		}
	}
	return 0;
}