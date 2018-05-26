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

int n, m;
char data[1001][1001];
bool vis[1001][1001][5];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

struct node
{
	int x, y;
	int pre, changep;
	bool operator < (const node &b) const
	{
		return changep > b.changep;
	}
};

bool bfs(int fx, int fy, int tx, int ty)
{
	queue <node> qqq;
	node now, nxt;
	now.x = fx;
	now.y = fy;
	now.pre = -1;
	now.changep = -1;
	qqq.push(now);
	//vis[fx][fy][0] = true;
	while(! qqq.empty())
	{
		now = qqq.front();
		qqq.pop();
		if(now.x == tx && now.y == ty && now.changep <= 2)return true;
		//else if(now.x == tx && now.y == ty)return false;
		for(int i = 0; i < 4; i ++)
		{
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if(1 <= nx && nx <= n && 1 <= ny && ny <= m)
			{
				if(data[nx][ny] == '*')continue;
				nxt.x = nx;
				nxt.y = ny;
				nxt.pre = i;
				if(now.pre != nxt.pre)
					nxt.changep = now.changep + 1;
				else nxt.changep = now.changep;
				if(nxt.changep != 0 && vis[nx][ny][nxt.changep - 1])continue;
				vis[nx][ny][nxt.changep] = true;
				//cout << now.x << ' ' << now.y << ' ' << nxt.x << ' ' << nxt.y << ' ' << nxt.changep << endl;
				if(nxt.changep <= 2)
					qqq.push(nxt);
			}
		}
	}
	return false;
}

int main()
{
	int fx, fy, tx, ty;
	while(scanf("\n%d %d", &n, &m) == 2)
	{
		RESET(vis);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				scanf("\n%c", &data[i][j]);
				switch(data[i][j])
				{
					case 'S':
						fx = i;
						fy = j;
						break;
					case 'T':
						tx = i;
						ty = j;
						break;
				}
			}
		bfs(fx, fy, tx, ty) ? puts("YES") : puts("NO");
	}
	return 0;
}
/*
5 5
..S..
****.
T....
****.
.....

5 5
S....
****.
.....
.****
..T..


7 7
.S.****
...*.*.
.****..
.*.**.*
..T*...
***..*.
*******
*/
