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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 109;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct point
{
	int x, y, stat, step;
};

struct pairs
{
	int x, y;
	int st;
};

int dx[] = { 0, 1,-1, 0};
int dy[] = {-1, 0, 0, 1};

int n, m, mpb;

char mp[maxn][maxn];
bool isu[maxn][maxn][1 << 5];
pairs ppp[5];

int findp(int x, int y)
{
	for(int i = 1;i <= mpb;i ++)
		if(ppp[i].x == x && ppp[i].y == y)
			return i;
	return 0;
}

int bfs(int fx, int fy)
{
	point temp, init;
	queue <point> qqq;
	init.x = fx;
	init.y = fy;
	init.step = 0;
	init.stat = (1 << (findp(fx, fy)));
	isu[fx][fy][init.stat] = true;
	qqq.push(init);
	int tx, ty;
	while(! qqq.empty())
	{
		init = qqq.front();
		tx = init.x;
		ty = init.y;
		if(init.stat == (1 << (mpb + 1)) - 1)return init.step;
		for(int i = 0;i <= 3;i ++)
		{
			if(tx + dx[i] > 0 && tx + dx[i] <= n
			&& ty + dy[i] > 0 && ty + dy[i] <= m)
			{
				if(mp[tx + dx[i]][ty + dy[i]] == '#')continue;
				temp.x = tx + dx[i];
				temp.y = ty + dy[i];
				temp.step = init.step + 1;
				temp.stat = init.stat | (1 << (findp(temp.x, temp.y)));
				if(! isu[temp.x][temp.y][temp.stat])
				{
					isu[temp.x][temp.y][temp.stat] = true;
					qqq.push(temp);
				}
			}
		}
		qqq.pop();
	}
	return -1;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char tmp[119];
	int x, y;
	int fx, fy;
	while(~ scanf("%d%d", &n, &m))
	{
		RESET(isu);
		if(n == 0 && m == 0)break;
		for(int i = 1;i <= n; i ++)
		{
			scanf("\n%s", tmp);
			for(int j = 0;j < m; j ++)
			{
				mp[i][j + 1] = tmp[j];
				if(mp[i][j + 1] == '@')
					fx = i, fy = j + 1;
			}
		}
		scanf("%d", &mpb);
		for(int i = 1;i <= mpb; i ++)
		{
			scanf("%d%d", &x, &y);
			ppp[i].x = x;
			ppp[i].y = y;
			ppp[i].st = i; //The Status is a demcial number!!
		}
		printf("%d\n", bfs(fx, fy));
	}
	return 0;
}

