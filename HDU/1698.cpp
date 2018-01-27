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

typedef struct 
{
	int lazy, data;
}node;

node tree[maxn];

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

void pushup(int p, int l, int r)
{
	tree[p].data = 0;
	if(r > l)tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data;
	//tree[p].data += tree[p].lazy * (r - l + 1);
}

void pushdown(int p, int l)
{
	if(tree[p].lazy)
	{
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy, 
		tree[DXA(p)].data = (l - (l >> 1)) * tree[p].lazy;  
        tree[DXB(p)].data = (l >> 1) * tree[p].lazy;  
		tree[p].lazy = 0;
	}
}

void update(int l, int r, int nl, int nr, int d, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = d;
		tree[p].data = tree[p].lazy * (nr - nl + 1);
		return ;
	}
	else 
	{
		pushdown(p, nr - nl + 1);
		int mid = midf(nl, nr);
		if(l <= mid)update(l, r, nl, mid, d, DXA(p));
		if(mid < r)update(l, r, mid + 1, nr, d, DXB(p));
	}
	pushup(p, nl, nr);
}

int query(int l, int r, int nl, int nr, int p)
{
	if(tree[p].lazy)
		return tree[p].lazy * (min(nr, r) - max(nl, l) + 1);
	else if(l <= nl && nr <= r)
		return tree[p].data;
	else
	{
		int mid = midf(nl, nr);
		int ans = 0;
		if(l <= mid)ans += query(l, r, nl, mid, DXA(p));
		if(mid < r) ans += query(l, r, mid + 1, nr, DXB(p));
		return ans;
	}
}

int main() {  
    int T, n, m, a, b, c;  
    int ans = 0;
    scan_d(T);
    for(int Casen = 1; Casen <= T; Casen ++) {  
        scan_d(n);
		scan_d(m);
        RESET(tree);
        update(1, n, 1, n, 1, 1);
        while(m --)
		{ 
			scan_d(a);
			scan_d(b);
			scan_d(c);
            update(a, b, 1, n, c, 1);
        }  
        printf("Case %d: The total value of the hook is %d.\n",
			    Casen, query(1, n, 1, n, 1));  
    }  
    return 0;  
}  

