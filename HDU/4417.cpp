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

int tree[maxn];
int lowbit(int x) {return x & -x;}

void update(int x)
{
	for(int i = x; i < maxn; i += lowbit(i))
		tree[i] ++;
}

int sum(int x)
{
	int ans = 0;
	for(int i = x; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

struct qqq
{
	int l, r, x, id;
	bool operator < (const qqq &b) const
	{
		return x < b.x;
	}
}query[maxn];

struct ddd
{
	int x, id;
	bool operator < (const ddd &b) const
	{
		return x < b.x;
	}
}data[maxn];

int ans[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, T;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; Casen ++)
	{
		RESET(tree);
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &data[i].x);
			data[i].id = i;
		}
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d %d %d", &query[i].l, &query[i].r, &query[i].x);
			query[i].id = i;
		}
		sort(data + 1, data + 1 + n); // 对数组排序 
		sort(query + 1, query + 1 + m); // 对区间排序 
		for(int aski = 1, ditj = 1; aski <= m; aski ++)
		{
			while(ditj <= n && query[aski].x >= data[ditj].x)
				update(data[ditj ++].id);
			ans[query[aski].id] = sum(query[aski].r + 1) - sum(query[aski].l);
		}
		printf("Case %d:\n", Casen);
		for(int i = 1; i <= m; i ++)
			printf("%d\n", ans[i]);
	}
	return 0;
}

