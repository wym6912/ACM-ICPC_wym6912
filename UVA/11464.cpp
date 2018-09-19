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
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int inf = 1e9 + 7;
const int maxn = 30;
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

int A[maxn][maxn], B[maxn][maxn], n;

int chk(int x)
{
	for(int i = 1; i <= n; ++ i)
	{
		if((x >> i) & 1)
			B[1][i] = 1;
		else B[1][i] = 0;
		if(! B[1][i] && A[1][i]) return inf;
	}
	int sum;
	for(int i = 2; i <= n; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			sum = 0;
			if(j != 1) sum += B[i - 1][j - 1];
			if(j != n) sum += B[i - 1][j + 1];
			//if(i != n) sum += B[i + 1][j];
			if(i != 2) sum += B[i - 2][j];
			B[i][j] = sum & 1;
			if(! B[i][j] && A[i][j]) return inf;
		}
	}
	/*
	puts("ANS");
	for(int i = 1; i <= n; ++ i, puts(""))
		for(int j = 1; j <= n; ++ j)
			printf("%d ", B[i][j]);
			*/
	sum = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			sum += A[i][j] != B[i][j];
	return sum;
}

int main()
{
	//freopen("11464.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				scanf("%d", &A[i][j]);
		int ans = inf;
		for(int i = 2; i <= (1 << (n + 1)); ++ i, ++ i)
			ans = min(ans, chk(i));
		ans == inf ? printf("Case %d: -1\n", Casen) : printf("Case %d: %d\n", Casen, ans);
	}
	return 0;
}
/*
3
3
0 0 0
0 0 0
0 0 0
3
0 0 0
1 0 0
0 0 0
3
1 1 1
1 1 1
0 0 0
*/
