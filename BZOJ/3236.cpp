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

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 1000003;
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

int blk, n, m; 

struct query
{
	int l, r, a, b, id;
	bool operator < (const query &b) const
	{
		return l / blk == b.l / blk ? r / blk < b.r / blk : l / blk < b.l / blk;
	}
}qqq[maxn];

struct ANS
{
	int a, b;
}ans[maxn];

int block[maxn], cnt[maxn], num[maxn], bel[maxn], a[maxn];

void modui()
{
	int l = 1, r = 0;
	for(register int i = 1; i <= m; ++ i)
	{
		while(l < qqq[i].l)
		{
			-- cnt[a[l]];
			-- num[bel[a[l]]];
			if(! cnt[a[l]]) -- block[bel[a[l]]];
			++ l;
		}
		while(r > qqq[i].r)
		{
			-- cnt[a[r]];
			-- num[bel[a[r]]];
			if(! cnt[a[r]]) -- block[bel[a[r]]];
			-- r;
		}
		while(l > qqq[i].l)
		{
			-- l;
			++ cnt[a[l]];
			++ num[bel[a[l]]];
			if(cnt[a[l]] == 1) ++ block[bel[a[l]]];
		}
		while(r < qqq[i].r)
		{
			++ r;
			++ cnt[a[r]];
			++ num[bel[a[r]]];
			if(cnt[a[r]] == 1) ++ block[bel[a[r]]];
		}
		
		int fi = 0, se = 0, st = qqq[i].a, ed = qqq[i].b;
		if(bel[st] == bel[ed])
		{
			for(register int j = st; j <= ed; ++ j)
				if(cnt[j]) fi += cnt[j], ++ se;
		}
		else
		{
			for(register int j = st; j <= bel[st] * blk; ++ j)
				if(cnt[j]) fi += cnt[j], ++ se;
			for(register int j = (bel[ed] - 1) * blk + 1; j <= ed; ++ j)
				if(cnt[j]) fi += cnt[j], ++ se;
			for(register int j = bel[st] + 1; j < bel[ed]; ++ j)
				if(num[j]) fi += num[j], se += block[j];
		}
		ans[qqq[i].id].a = fi;
		ans[qqq[i].id].b = se;
	}
}

int main()
{
	scan_d(n);
	scan_d(m);
	blk = (int) sqrt(1.0 * n);
	for(register int i = 1; i <= n; ++ i)
		scan_d(a[i]), 
		bel[i] = (i - 1) / blk + 1;
	for(register int i = 1; i <= m; ++ i)
	{
		scan_d(qqq[i].l);
		scan_d(qqq[i].r);
		scan_d(qqq[i].a);
		scan_d(qqq[i].b);
		qqq[i].id = i;
	}
	sort(qqq + 1, qqq + 1 + m);
	modui();
	for(register int i = 1; i <= m; ++ i)
	{
		out_number(ans[i].a);
		putchar(' ');
		out_number(ans[i].b);
		puts("");
	}
	return 0;
}
/*
3 4
1 2 2
1 2 1 3
1 2 1 1
1 3 1 3
2 3 2 3
*/

