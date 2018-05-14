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

const int dx[] = {0, 1,-1, 0};
const int dy[] = {1, 0, 0,-1};

int pl[100][100];
int ans[100][100];
bool isboy[100][100];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	while(scanf("%d %d", &n, &m) && (n || m))
	{
		RESET(isboy);
		RESET(ans);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				scanf("%d", &pl[i][j]), isboy[i][j] = pl[i][j] > 0 ? true : false;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				for(int k = 0; k < 4; k ++)
				{
					if(i + dx[k] > 0 && i + dx[k] <= n && j + dy[k] > 0 && j + dy[k] <= m)
						ans[i][j] += (isboy[i][j] != isboy[i + dx[k]][j + dy[k]] ? 
						abs(pl[i + dx[k]][j + dy[k]]) : -abs(pl[i + dx[k]][j + dy[k]]));
				}
				ans[0][0] = max(ans[0][0], ans[i][j]);
				//printf("%d %d %d\n", i, j, ans[i][j]);
			}
		}
		bool out = false;
		for(int i = 1; i <= m; i ++)
			for(int j = 1; j <= n; j ++)
				if(ans[0][0] == ans[j][i] && ! out)
					printf("%d %d %d\n", j, i, ans[j][i]), out = true;
	}
	return 0;
}

