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
int A[maxn], root[maxn], cnt, nxt[maxn], last[maxn];
struct node
{
	int l, r, val;
}tree[maxn * 50];

#define lson(_) (tree[_].l)
#define rson(_) (tree[_].r)
int v;
void update(int pre, int &now, int nl, int nr)
{
	now = ++ cnt;
	tree[now] = tree[pre];
	++ tree[now].val;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(v <= mid) update(lson(pre), lson(now), nl, mid);
	else update(rson(pre), rson(now), mid + 1, nr);
}

int query(int x, int y, int nl, int nr)
{
	if(nl == nr) return 0;
	int mid = midf(nl, nr);
	if(v <= mid) return tree[rson(y)].val - tree[rson(x)].val + query(lson(x), lson(y), nl, mid);
	else return query(rson(x), rson(y), mid + 1, nr);
}
#undef lson
#undef rson

int T, ans, f, t, l, r, mid, now;
int ff(int x)
{
	v = x;
	return query(root[f - 1], root[x], 1, n + 1);	
}

int main()
{
	scanf("%d", &T);
	//scan_d(T);
	for(register int kssn = 1; kssn <= T; ++ kssn)
	{
		scanf("%d %d", &n, &m);
		//scan_d(n);
		//scan_d(m);
		ans = cnt = 0;
		for(register int i = 1; i <= n; ++ i) scan_d(A[i]);
		for(register int i = 0; i <= 200000; ++ i) last[i] = n + 1;
		for(register int i = n; i >= 1; -- i) 
		{
			nxt[i] = last[A[i]];
			last[A[i]] = i;
		}
		for(register int i = 1; i <= n; ++ i)
		{
			v = nxt[i];
			update(root[i - 1], root[i], 1, n + 1);
		}
		printf("Case #%d:", kssn);
		while(m --)
		{
			scanf("%d %d", &f, &t);
			//scan_d(f);
			//scan_d(t);
			f = (f + ans) % n + 1, t = (t + ans) % n + 1;
			if(f > t) swap(f, t);
			l = f, r = t;
			now = ff(t);
			now = (now + 1) >> 1;
			while(l <= r)
			{
				mid = midf(l, r);
				if(ff(mid) >= now) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			printf(" %d", ans);
		}
		puts("");
	}
	return 0;
}

