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

const int mod = 99971;
const int maxn = 400010;
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
#endif
inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n')ch = getchar();
	return true;
}

template <class T>
inline void out_number(T x)
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
	int trans;
	int sum[50], t[50];
}node;

node tree[maxn];
int n, mark[50];

/*
void transfer(int p)
{
	tree[p].trans %= 48;
	if(tree[p].trans <= 0)return ;
	while(tree[p].trans --)
		tree[p].data = tree[p].data * tree[p].data % mod * tree[p].data % mod;
}
*/

void pushup(int p, int l, int r)
{
	for(int i = 0; i < 48; i ++) 
	{
    	if(l < r) tree[p].sum[i] = (tree[DXA(p)].sum[i] + tree[DXB(p)].sum[i]) % mod;
   		else tree[p].sum[i] = tree[p].t[i];
	}
    int now = tree[p].trans;
    now %= 48;
    if(now) //¹ö¶¯Êý×é 
	{
    	for(int i = 0; i < 48; i ++) mark[i] = tree[p].sum[i];
    	for(int i = 0; i < 48; i ++) tree[p].sum[i] = mark[(i + now) % 48];
	}
}

void pushdown(int p)
{
	tree[DXA(p)].trans += tree[p].trans;
	tree[DXB(p)].trans += tree[p].trans;
	tree[p].trans = 0;
}

void pre(int l, int r, int p)
{
	tree[p].trans = 0;
	if(l == r)
	{
		scan_d(tree[p].data);
		tree[p].data %= mod;
		tree[p].sum[0] = tree[p].t[0] = tree[p].data;
		for(int i = 1; i < 48; i ++)
		{
			tree[p].sum[i] = (int)(1ll * tree[p].sum[i - 1] * tree[p].sum[i - 1] % mod * tree[p].sum[i - 1] % mod);
			tree[p].t[i] = tree[p].sum[i];
		}
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	for(int i = 0; i < 48; i ++) 
	{
        tree[p].sum[i] = (tree[DXA(p)].sum[i] + tree[DXB(p)].sum[i]) % mod;
    }
}

void update(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].trans ++;
		pushup(p, nl, nr);
		return;
	}
	pushdown(p);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, DXA(p));
	else pushup(DXA(p), nl, mid);
	if(mid < r) update(l, r, mid + 1, nr, DXB(p));
	else pushup(DXB(p), mid + 1, nr);
	pushup(p, nl, nr);
}

ll query(int l, int r, int nl, int nr, int val, int p)
{
	if(l <= nl && nr <= r)
	{
		return tree[p].sum[val % 48];
	}
	int mid = midf(nl, nr);
	ll ans = 0;
	if(l <= mid)ans = (ans + query(l, r, nl, mid, val + tree[p].trans, DXA(p))) % mod;
	if(mid < r) ans = (ans + query(l, r, mid + 1, nr, val + tree[p].trans, DXB(p))) % mod;
	return ans;
}

int main()
{
	int _, q, type, f, t;
	scan_d(_);
	while(_ --)
	{
		scan_d(n);
		scan_d(q);
		pre(1, n, 1);
		while(q --)
		{
			scan_d(type);
			scan_d(f);
			scan_d(t);
			switch(type)
			{
				case 1:
					update(f, t, 1, n, 1);
					break;
				case 2:
					out_number(query(f, t, 1, n, 0, 1) % mod);
					puts("");
					break;
				default:
					assert(type == 1 || type == 2);
			}
		}
	}
	return 0;
}
/*
1
5 10
1 2 3 4 5
2 1 5
1 1 3
1 3 5
2 1 5
2 1 1
2 2 2
2 3 3
2 4 4
2 5 5
2 1 5
*/
