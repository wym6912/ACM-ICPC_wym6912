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
const int maxn = 2009;
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

const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

struct node
{
	int x, y, fl, fr;
	node(int x = 0, int y = 0, int fl = 0, int fr = 0) : x(x), y(y), fl(fl), fr(fr){}
	bool operator < (const node &b) const
	{
		return fl == b.fl ? fr > b.fr : fl > b.fl;
	}
};

int n, m, fx, fy, pl, pr;
char data[maxn][maxn];
bool v[maxn][maxn];

int bfs(int fx, int fy)
{
	if(data[fx][fy] == '*') return 0;
	priority_queue <node> qqq;
	node init = node(fx, fy), temp;
	int ans = 1;
	qqq.push(init);
	v[fx][fy] = true;
	while(! qqq.empty())
	{
		init = qqq.top();
		qqq.pop();
		for(register int i = 0, x = init.x, y = init.y; i < 4; ++ i)
		{
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m)
			{
				temp.x = x + dx[i];
				temp.y = y + dy[i];
				temp.fl = init.fl + (dy[i] == -1);
				temp.fr = init.fr + (dy[i] == 1);
				if(temp.fl > pl || temp.fr > pr) continue;
				if(data[temp.x][temp.y] == '.' && ! v[temp.x][temp.y])
				{
					v[temp.x][temp.y] = true;
					qqq.push(temp);
					++ ans;
				}
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &fx, &fy);
	scanf("%d %d", &pl, &pr);
	RESET(v);
	for(register int i = 1; i <= n; ++ i)
		for(register int j = 1; j <= m; ++ j)
			scanf("\n%c", &data[i][j]);
	printf("%d\n", bfs(fx, fy));
	return 0;
}
/*
10 10
10 4
10 9
...*******
.*.*******
.*.*******
.*.*******
.*.*******
.*.*......
.*.*.*****
.*........
.********.
..........
*/

