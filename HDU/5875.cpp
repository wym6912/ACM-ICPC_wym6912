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

const int MOD = 1e9 + 7;
const int maxn = 100009;
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
	ll data;
}tree[maxn << 2];
ll data[maxn];
int n;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].data = min(tree[DXA(p)].data, tree[DXB(p)].data);
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(data[l]);
		tree[p].data = data[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int query(int l, int r, int nl, int nr, int p, ll k)//返回的是区间[x+1,y]内，比a[x]小的下标
{
	if(tree[p].data > k)return nr + 1;
	if(nl == nr)return nl;
	if(l <= nl && nr <= r)
	{
		int mid = midf(nl, nr);
		if(tree[DXA(p)].data <= k)
			return query(l, r, nl, mid, DXA(p), k);
		else return query(l, r, mid + 1, nr, DXB(p), k);
	}
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid)
	{
		ans = query(l, r, nl, mid, DXA(p), k);
		if(ans <= nr)return ans;
	}
	if(mid < nr)
	{
		ans = query(l, r, mid + 1, nr, DXB(p), k);
		if(ans <= nr)return ans;
	}
	return nr + 1;
}

int main()
{
	int T, m, f, t, p;
	ll tmp;
	scan_d(T);
	while(T --)
	{
		scan_d(n);
		pre(1, n, 1);
		scan_d(m);
		while(m --)
		{
			scan_d(f);
			scan_d(t);
			tmp = data[f];
			while(f < t)
			{
				p = query(f + 1, t, 1, n, 1, tmp);
				if(p <= t)
					tmp %= data[p];
				f = p;
			}
			out_number(tmp);
			puts("");
		}
	}
	return 0;
}

