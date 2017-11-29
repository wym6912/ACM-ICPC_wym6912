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
const int maxn = 300009;
const int maxm = 22;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = { 0, 1,-1, 0};
int dy[] = {-1, 0, 0, 1};

struct point
{
	int x, y, keys, step;
};

int walls[maxm][maxm][maxm][maxm], keys[maxm][maxm];

bool stat[maxm][maxm][1 << 11];

int n, m, p;

int bfs(int fx, int fy)
{
	point temp, init;
	queue <point> qqq;
	init.x = fx;
	init.y = fy;
	init.keys = keys[fx][fy];
	init.step = 0;
	qqq.push(init);
	while(! qqq.empty())
	{
		init = qqq.front();
		//cout << init.x << ' ' << init.y << ' ' << init.keys << ' ' << init.step << endl;
		if(init.x == n && init.y == m)return init.step;
		for(int i = 0; i <= 3; i ++)
		{
			if(init.x + dx[i] > 0 && init.x + dx[i] <= n 
			&& init.y + dy[i] > 0 && init.y + dy[i] <= m)
			{
				temp.x = init.x + dx[i];
				temp.y = init.y + dy[i];
				temp.keys = init.keys | keys[temp.x][temp.y];
				temp.step = init.step + 1;
				if(walls[init.x][init.y][temp.x][temp.y] == -1)
					continue;
				if(walls[init.x][init.y][temp.x][temp.y] == 0 //I'm stuck here!!!这里可以直接通过的！！ 
				||(temp.keys >> walls[init.x][init.y][temp.x][temp.y]) & 1)
					if(! stat[temp.x][temp.y][temp.keys]) //必须优化掉这里，会爆空间的（重复走这个状态） 
					{
						qqq.push(temp);
						stat[temp.x][temp.y][temp.keys] = true;
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
	while(cin >> n >> m >> p)
	{
		RESET(walls);
		RESET(keys);
		RESET(stat);
		int doors, fx, fy, tx, ty, type, key;
		cin >> doors;
		for(int i = 1;i <= doors;i ++)
		{
			cin >> fx >> fy >> tx >> ty >> type;
			if(type)walls[fx][fy][tx][ty] = walls[tx][ty][fx][fy] = type; //Save the type number, not the ans
			else walls[fx][fy][tx][ty] = walls[tx][ty][fx][fy] = -1;
		} 
		cin >> key;
		for(int i = 1;i <= key;i ++)
		{
			cin >> fx >> fy >> type;
			keys[fx][fy] |= (1 << type);  // save the binary code of keys
		}
		cout << bfs(1, 1) << endl;
	}
	return 0;
}
 
