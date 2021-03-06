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

ll tree[maxn];

ll n, m, w;

int lowbit(int x){return x & -x;}

void update(int p, ll x)
{
	for(int i = p; i < maxn; i += lowbit(i))
		tree[i] += x;
}

ll query(int p)
{
	ll ans = 0;
	for(int i = p; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

struct shoes
{
	int m, w;
	friend bool operator < (const shoes &a, const shoes &b)
	{
		return a.m == b.m ? a.w < b.w : a.m < b.m;
	}
};

shoes sh[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(scan_d(n) && scan_d(m) && scan_d(w))
	{
		RESET(tree);
		for(int i = 1; i <= n; i ++)
			scan_d(sh[i].m);
		for(int i = 1; i <= n; i ++)
			scan_d(sh[i].w);
		sort(sh + 1, sh + 1 + n);
		int l = 1, r = n;
		ll ans = 0;
		for(; r; r --)
		{
			for(; l <= n && sh[l].m + sh[r].m <= m; l ++)
			{
				update(sh[l].w, 1);
			}
			if(w - sh[r].w > 0)ans += query(w - sh[r].w);
		}
		for(int i = 1; i <= n; i ++)
			if(sh[i].m * 2 <= m && sh[i].w * 2 <= w)
				ans --;
		ans >>= 1;
		out_number(ans);
		puts("");
	}
	return 0;
}

