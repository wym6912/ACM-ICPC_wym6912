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
const int maxn = 100000 * 4;
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
	ll data;
}node;

node tree[maxn];

int n, m;

void outCase(int);

void pushup(int p)
{
	tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data;
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(tree[p].data);
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

void update(int l, int r, int nl, int nr, int data, int p)
{
	if(l <= nl && nr <= r)
	{
		if(tree[p].data == nr - nl + 1) //在这里优化了 一个 ll 型的数开方次数有限 
			return ;
	}
	if(nl == nr)//注意区间的表示 
	{
		tree[p].data = (ll)sqrt(tree[p].data * 1.0);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, data, DXA(p));
//	else pushup(DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, data, DXB(p));
//	else pushup(DXB(p));
	pushup(p);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return tree[p].data;
	else
	{
		ll ans = 0;
		int mid = midf(nl, nr);
		if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
		if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
		return ans;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Casen = 1, f, t, q;
	while(scan_d(n))
	{
		pre(1, n, 1);
		outCase(Casen ++);
		scan_d(m);
		while(m --)
		{
			scan_d(q);
			scan_d(f);
			scan_d(t);
			switch(q)
			{
				case 0:
					update(min(f, t), max(f, t), 1, n, 1, 1);
					break;
				case 1:
					out_number(query(min(f, t), max(f, t), 1, n, 1));
					puts("");
					break;
				default:
					assert(false);
			}
		}
		puts("");//PE 
	}
	return 0;
}


void outCase(int Casen)
{
	printf("Case #%d:\n", Casen);
}
