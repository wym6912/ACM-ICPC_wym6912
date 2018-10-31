//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 300009;
const ll inf = 1e18;
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

int n, m, A[maxn];
int BIT[maxn];
inline int lowbit(int &x) {return x & -x;}
inline void update_BIT(int x, int val) {for(int i = x; i <= n; i += lowbit(i)) BIT[i] += val;}
inline int query_BIT(int x){int ans = 0; for(int i = x; i; i -= lowbit(i)) ans += BIT[i]; return ans;}

#define lson(_) cmt_l[_]
#define rson(_) cmt_r[_]
int cmt_cnt, root[maxn], cmt_l[maxn * 50], cmt_r[maxn * 50], cmt_val[maxn * 50], val;
void update_cmt(int &now, int nl, int nr)
{
	if(! now) now = ++ cmt_cnt;
	++ cmt_val[now];
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(val <= mid) update_cmt(lson(now), nl, mid);
	else update_cmt(rson(now), mid + 1, nr);
}
int lp[200], rp[200], cntx, cnty;
int query_before(int x, int y, int v)
{
	int nl = 1, nr = n, mid;
	ll ans = 0;
	cntx = cnty = 0;
	-- x;
	for(register int i = x; i; i -= lowbit(i)) lp[++ cntx] = root[i];
	for(register int i = y; i; i -= lowbit(i)) rp[++ cnty] = root[i];
	while(nl != nr)
	{
		mid = midf(nl, nr);
		if(v <= mid) 
		{
			for(register int i = 1; i <= cntx; ++ i) ans -= cmt_val[rson(lp[i])];
			for(register int i = 1; i <= cnty; ++ i) ans += cmt_val[rson(rp[i])];
			for(register int i = 1; i <= cntx; ++ i) lp[i] = lson(lp[i]);
			for(register int i = 1; i <= cnty; ++ i) rp[i] = lson(rp[i]);
			nr = mid;
		}
		else
		{
			for(register int i = 1; i <= cntx; ++ i) lp[i] = rson(lp[i]);
			for(register int i = 1; i <= cnty; ++ i) rp[i] = rson(rp[i]);
			nl = mid + 1;
		}
	}
	return ans;
}

inline ll query_after(int x, int y, int v)
{
	int nl = 1, nr = n, mid;
	ll ans = 0;
	cntx = cnty = 0;
	-- x;
	for(register int i = x; i; i -= lowbit(i)) lp[++ cntx] = root[i];
	for(register int i = y; i; i -= lowbit(i)) rp[++ cnty] = root[i];
	while(nl != nr)
	{
		mid = midf(nl, nr);
		if(v > mid) 
		{
			for(register int i = 1; i <= cntx; ++ i) ans -= cmt_val[lson(lp[i])];
			for(register int i = 1; i <= cnty; ++ i) ans += cmt_val[lson(rp[i])];
			for(register int i = 1; i <= cntx; ++ i) lp[i] = rson(lp[i]);
			for(register int i = 1; i <= cnty; ++ i) rp[i] = rson(rp[i]);
			nl = mid + 1;
		}
		else
		{
			for(register int i = 1; i <= cntx; ++ i) lp[i] = lson(lp[i]);
			for(register int i = 1; i <= cnty; ++ i) rp[i] = lson(rp[i]);
			nr = mid;
		}
	}
	return ans;
}

#undef lson
#undef rson

int b1[maxn], a1[maxn], pos[maxn], tmp;

int main()
{
	ll ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%d", A + i);
		pos[A[i]] = i;
		b1[i] = query_BIT(n) - query_BIT(A[i]);
		ans += b1[i];
		update_BIT(A[i], 1);
	}
	RESET(BIT);
	for(int i = n; i; -- i)
	{
		a1[i] = query_BIT(A[i] - 1);
		update_BIT(A[i], 1);
	}
	while(m --)
	{
		printf("%lld\n", ans);
		scanf("%d", &tmp);
		tmp = pos[tmp];
		ans -= (a1[tmp] + b1[tmp] - query_before(1, tmp - 1, A[tmp]) - query_after(tmp + 1, n, A[tmp]));
		for(int i = tmp; i <= n; i += lowbit(i)) val = A[tmp], update_cmt(root[i], 1, n);
	}
	return 0;
}

/*
5 4
1 5 3 4 2
5 1 4 2
*/
