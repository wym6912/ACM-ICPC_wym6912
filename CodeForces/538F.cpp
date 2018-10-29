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
const int maxn = 200009;
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

int n, m;
int A[maxn], root[maxn], cnt;
struct node
{
	int l, r, val;
}tree[maxn * 50];

#define lson(_) (tree[_].l)
#define rson(_) (tree[_].r)
int l, r, val;
void update(int pre, int &now, int nl, int nr)
{
	now = ++ cnt;
	tree[now] = tree[pre];
	++ tree[now].val;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(val <= mid) update(lson(pre), lson(now), nl, mid);
	else update(rson(pre), rson(now), mid + 1, nr);
}

int query(int nl, int nr, int x, int y)
{
	if(nl == nr) return 0;
	int mid = midf(nl, nr), pp = tree[lson(y)].val - tree[lson(x)].val;
	if(val <= mid) return query(nl, mid, lson(x), lson(y));
	else return pp + query(mid + 1, nr, rson(x), rson(y));
}
#undef lson
#undef rson

vi v;

int main()
{
	v.clear();
	scanf("%d", &n);
	for(register int i = 1; i <= n; ++ i) scanf("%d", A + i), v.push_back(A[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(register int i = 1; i <= n; ++ i) 
		A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
	for(register int i = 1; i <= n; ++ i)
	{
		val = A[i];
		update(root[i - 1], root[i], 1, n);
	}
	ll ans = 0;
	for(register int k = 1; k < n; ++ k)
	{
		ans = 0;
		for(int i = 1, j = 1; j <= n; ++ i, j += k)
		{
			l = j, r = min(j + k, n), val = A[i];
			ans += query(1, n, root[l], root[r]);
		}
		printf("%lld ", ans);
	}
	puts("");
	return 0;
}

