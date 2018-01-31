#define NOSTDCPP
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
	ll lazy;
	ll data;
}tree;

tree node[maxn];

int n, s, q;
ll cc;

void pushup(int p)
{
	node[p].data = node[DXA(p)].data | node[DXB(p)].data;
	if(node[p].lazy)
		node[p].data |= (1 << node[p].lazy);
}

void pushdown(int p)
{
	if(node[p].lazy) //注意有可能没打标记 
	{
		node[DXA(p)].lazy = node[DXB(p)].lazy = node[p].lazy;
		node[DXA(p)].data = node[DXB(p)].data = (1 << node[p].lazy);
		node[p].lazy = 0;
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		node[p].lazy = 1;
		node[p].data = 1 << 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

void update(int l, int r, int nl, int nr, ll c, int p)
{
	if(l <= nl && nr <= r)
	{
		node[p].lazy = c;
		node[p].data = (1 << c);
		return ;
	}
	else 
	{
		pushdown(p);
		int mid = midf(nl, nr);
		if(l <= mid)
			update(l, r, nl, mid, c, DXA(p));
		if(mid < r)
			update(l, r, mid + 1, nr, c, DXB(p));
	}
	pushup(p);
}

void query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		cc = cc | node[p].data;
		return;
	}
	else
	{
		pushdown(p);
		int mid = midf(nl, nr);
		if(l <= mid)
			query(l, r, nl, mid, DXA(p));
		if(mid < r)
			query(l, r, mid + 1, nr, DXB(p));
	}
}

int main()
{
	char ch;
	int x, y, c;
    while(scan_d(n) && scan_d(s) && scan_d(q))
    {
        pre(1, n, 1);
        while(q --)
        {
        	scan_ch(ch);
        	assert(ch == 'C' || ch == 'P');
            if(ch == 'C')
            {
                scan_d(x);
                scan_d(y);
                scan_d(c);
                if(x > y)
					swap(x, y);
                update(x, y, 1, n, c, 1);
            }
            else
            {
                int ans = 0;
                scan_d(x);
                scan_d(y);
                if(x > y)
					swap(x, y);
                cc = 0;
                query(x, y, 1, n, 1);
                for(int i = 1; i <= s; i ++)
                {
                    if(cc & (1 << i))
                        ans ++;
                }
                out_number(ans);
                puts("");
            }
        }
    }
    return 0;
}
/*
2 2 4
C 1 1 2
P 1 2
C 2 2 2
P 1 2

10 4 5
C 2 1 3
C 9 10 2
C 5 5 4
P 1 5
P 2 2

12 5 10
C 3 2 4
C 5 4 2
P 6 5
C 1 2 2
C 2 3 2
C 4 4 1
P 2 3
P 7 7
C 8 12 5
P 1 12

6 7 4
C 1 6 2
P 1 5
C 4 2 7
P 6 1
*/
