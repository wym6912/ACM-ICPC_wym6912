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

typedef struct
{
	int to, next;
}vertex;

int from[maxn], n, m;
vertex ee[maxn];
char data[maxn];
int deg[maxn];

int dp[maxn][27];

int edges;

void addedge(int f, int t)
{
	ee[++ edges].to = t;
	ee[edges].next = from[f];
	from[f] = edges;
}

void toposort()
{
	queue <int> qqq;
	for(int i = 1; i <= n; i ++)
		if(! deg[i])
		{
			qqq.push(i);
			dp[i][data[i] - 'a' + 1] ++;
		}
	int cnt = 0;
	while(! qqq.empty())
	{
		int fi = qqq.front();
		qqq.pop();
		cnt ++;
		for(int i = from[fi]; i; i = ee[i].next)
		{
			deg[ee[i].to] --;
			if(! deg[ee[i].to])qqq.push(ee[i].to);
			for(int j = 1; j <= 26; j ++)
				dp[ee[i].to][j] = max(dp[ee[i].to][j], dp[fi][j] + (data[ee[i].to] - 'a' + 1 == j));
		}
	}
	if(cnt < n)
	{
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= 26; j ++)
			ans = max(ans, dp[i][j]);
	cout << ans << endl;
	return ;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int f, t;
	while(cin >> n >> m)
	{
		cin >> data + 1;
		RESET(from);
		RESET(deg);
		edges = 0;
		while(m --)
		{
			cin >> f >> t;
			addedge(f, t);
			deg[t] ++;
		}
		toposort();
	}
	return 0;
}

