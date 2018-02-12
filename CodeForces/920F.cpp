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
const int maxn = 300009 * 4;
const int maxm = 1000009;
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
	ll sum, max_d;
	int tag;
}node;

node tree[maxn];

int trans[maxm];
int n;

int nprime,prime[maxm];
bool isprime[maxm];
ll data[maxn];

void p()
{
	for(int i = 1;i < maxm; i ++){
		for(int j = 1; j * i < maxm; j ++){
			++ trans[i * j];
		}
	}
}

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
		tree[p].max_d = max(tree[DXA(p)].max_d, tree[DXB(p)].max_d);
	}
}

void pushup_2(int p)
{	
	tree[p].max_d = tree[p].sum;
}

void pushdown(int p)
{
	if(tree[p].tag)
	{
		tree[DXA(p)].tag += tree[p].tag;
		tree[DXB(p)].tag += tree[p].tag;
		tree[p].tag = 0;
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(tree[p].sum);
		pushup_2(p);
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int l, int r, int nl, int nr, int p)
{
	if(tree[p].max_d <= 2)return ;
	if(nl == nr)
	{
		tree[p].tag ++;
		while(tree[p].tag > 0)
		{
			tree[p].sum = trans[tree[p].sum];
			tree[p].tag --;
			if(tree[p].sum <= 2)break;
		}
		pushup_2(p);
		return ;
	}
	pushdown(p);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, DXA(p));
	else pushup(DXA(p), nl, mid);
	if(mid < r) update(l, r, mid + 1, nr, DXB(p));
	else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum;
	}
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
	if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q, f, t, m;
	scan_d(n);
	scan_d(m);
	p();
	pre(1, n, 1);
	while(m --)
	{
		scan_d(q);
		scan_d(f);
		scan_d(t);
		switch(q)
		{
			case 1:
				update(f, t, 1, n, 1);
				break;
			case 2:
				out_number(query(f, t, 1, n, 1));
				puts("");
				break;
			default:
				assert(q == 1 || q == 2);
		}
	}
	return 0;
}

/*
7 10
1 1 1 1 1 1 1
1 1 7
1 1 7
1 1 7
1 1 7
1 1 7
1 1 7
1 1 7
1 1 7
1 1 7
2 1 7
*/

