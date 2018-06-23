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

typedef struct
{
	int x, y;
}node;

int a[4], n, m;
char data[51][51];

int dx[] = {0, 1,-1, 0};
int dy[] = {1, 0, 0,-1};

queue <node> qqq;

void bfs(int x, int y)
{
	char ok = data[x][y];
	a[data[x][y] - 'A'] ++;
	data[x][y] = '.';
	int nxtx, nxty;
	node now, nxt;
	now.x = x;
	now.y = y;
	while(! qqq.empty())qqq.pop();
	qqq.push(now);
	while(! qqq.empty())
	{
		now = qqq.front();
		x = now.x, y = now.y;
		qqq.pop();
		for(int i = 0; i <= 3; i ++)
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m)
			{
				nxtx = x + dx[i];
				nxty = y + dy[i];
				if(data[nxtx][nxty] == ok)
				{
					data[nxtx][nxty] = '.';
					nxt.x = nxtx;
					nxt.y = nxty;
					qqq.push(nxt);
				}
			}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			//cin >> data[i][j];
			scanf("\n%c", &data[i][j]);
	a[0] = a[1] = a[2] = a[3] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(data[i][j] != '.')
				bfs(i, j);
	//cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
	printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
	return 0;
}

