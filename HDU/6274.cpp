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
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

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
const int maxn = 1097;
const int maxm = 100009;
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

struct BIT
{
	int sum[maxn];
	int lowbit(int x){return x & -x;}
	
	void update(int x, int v)
	{
		++ x;
		for(int i = x; i < maxn; i += lowbit(i))
			sum[i] += v;
	}
	
	int query(int x)
	{
		++ x;
		int ans = 0;
		for(int i = x; i; i -= lowbit(i))
			ans += sum[i];
		return ans;
	}
}tree[maxn];

int A[maxm], t[maxm], B[maxm];

bool ok(ll mid, ll ans)
{
	ll ss = 0;
	for(int i = 1; i <= 1000; ++ i)
	{
		ss += (mid / i) * t[i] - (t[i] - tree[i].query(mid % i));
		if(ss >= ans + 1000 - i) return true;
	}
	return ss >= ans;
}

int main()
{
	int T, type, x, y;
	ll s, ans, l, r, mid, rans;
	scanf("%d", &T);
	while(T --)
	{
		s = 0;
		RESET(tree);
		RESET(t);
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++ i)
		{
			scanf("%d", A + i);
			++ t[A[i]];
		}
		for(int i = 1; i <= n; ++ i)
		{
			scanf("%d", B + i);
			s += B[i] / A[i];
			tree[A[i]].update(B[i] % A[i], 1);
		}
		while(m --)
		{
			scanf("%d %d", &type, &x);
			switch(type)
			{
				case 1:
					scanf("%d", &y);
					-- t[A[x]];
					s = s - B[x] / A[x];
					tree[A[x]].update(B[x] % A[x], -1);
					A[x] = y;
					++ t[A[x]];
					s = s + B[x] / A[x];
					tree[A[x]].update(B[x] % A[x], 1);
					break;
				case 2:
					scanf("%d", &y);
					s = s - B[x] / A[x];
					tree[A[x]].update(B[x] % A[x], -1);
					B[x] = y;
					s = s + B[x] / A[x];
					tree[A[x]].update(B[x] % A[x], 1);
					break;
				case 3:
					ans = s + x;
					l = 0, r = 2e12;
					while(l <= r)
					{
						mid = midf(l, r);
						if(ok(mid, ans)) rans = mid, r = mid - 1;
						else l = mid + 1;
					}
					printf("%I64d\n", rans);
					break;
				default:
					assert(type == 1 || type == 2 || type == 3);
			}
		}
	}
	return 0;
}
/*
2

4 6
2 4 6 8
1 3 5 7
1 2 3
2 3 3
3 15
1 3 8
3 90
3 66

8 5
2 4 8 3 1 3 6 24
2 2 39 28 85 25 98 35
3 67
3 28
3 73
3 724
3 7775
*/
