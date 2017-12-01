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
const int max_status1 = 1 << 5;
const int max_status2 = 10;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct snake
{
	int x, y, id;
	snake(int a, int b, int c){x = a, y = b, id = c;}
	snake(){}
};

struct point
{
	int x, y, step;
	int sn, sk;
	friend bool operator < (const point &a, const point &b)
	{
		return a.step < b.step;
	}
};

int dx[] = { 0, 1,-1, 0};
int dy[] = {-1, 0, 0, 1};

int n, m, snakes;
char mp[maxn][maxn];
bool iss[maxn][maxn][max_status1][max_status2];
snake sss[5];

int snake_num(int x, int y)
{
	for(int i = 0;i < snakes;i ++)
		if(x == sss[i].x && y == sss[i].y)
			return i;
	assert(false);
}

bool isok(point p, int tx, int ty)
{
	if(p.x == tx && p.y == ty)
	{
		if(p.sk == m)
		{
			return true;
		}
	}
	return false;
}

int bfs(int fx, int fy, int ttx, int tty)
{
	point temp, init;
	queue <point> qqq;
	init.x = fx;
	init.y = fy;
	init.step = 0;
	init.sn = 0;
	init.sk = 0;
	iss[fx][fy][init.sn][init.sk] = true; //  蛇为第一状态，钥匙为第二状态 
	qqq.push(init);
	int ans = (1 << 20);
	while(! qqq.empty())
	{
		init = qqq.front();
		qqq.pop();
		//cout << init.sk << ' ' << init.sn << ' ' << init.step << ' ' << init.x << ' ' << init.y << endl;
		if(mp[init.x][init.y] == 'T' && init.sk == m)
		{
		//	cout << init.sk << ' ' << init.sn << ' ' << init.step << ' ' << init.x << ' ' << init.y << endl;
			ans = min(ans, init.step);
		}
		for(int i = 0;i <= 3;i ++)
		{
			if(init.x + dx[i] > 0 && init.x + dx[i] <= n
		    && init.y + dy[i] > 0 && init.y + dy[i] <= n)
		    {
		    	int tx = init.x + dx[i];
		    	int ty = init.y + dy[i];
		    	temp.x = tx;
		    	temp.y = ty;
		    	temp.step = init.step + 1;
		    	temp.sn = init.sn;
		    	temp.sk = init.sk;
		    	if(mp[tx][ty] == '#')continue;
		    	if(mp[tx][ty] == 'S')
		    	{
		    		int snn = snake_num(tx, ty);
		    		//cout << snn << ' ' << temp.sn << ' ' << tx << ' ' << ty << endl;
		    		if((temp.sn & (1 << snn)) == 0)
					{
						temp.step ++;
						//cout << "I killed a snake ! " << snn << endl;
						temp.sn = (temp.sn + (1 << snn));
					}
				}
				if(mp[tx][ty] >= '1' && mp[tx][ty] <= '9')
				{
					int nowkey = mp[tx][ty] - '0';
					if(nowkey == temp.sk + 1)temp.sk = nowkey; //we have the key of sk
					//cout << temp.step << ' ' << nowkey << ' ' << temp.sk << ' ' << tx << ' ' << ty << endl;
				}
				if(! iss[tx][ty][temp.sn][temp.sk])
				{
					iss[tx][ty][temp.sn][temp.sk] = true;
					qqq.push(temp);
				}
			}
		}
		
	}
	if(ans != (1 << 20))return ans;
	return -1;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int fx, fy, tx, ty;
	while(~ scanf("\n%d%d", &n, &m) && (n != 0 || m != 0))
	{
		RESET(iss);
		RESET(mp);
		RESET(sss);
		snakes = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s", mp[i] + 1);
			for(int j = 1;j <= n;j ++)
			{
				if(mp[i][j] == 'S')
					sss[snakes ++] = snake(i, j, snakes); // from 0 to 4
				if(mp[i][j] == 'K')
					fx = i, fy = j;
				if(mp[i][j] == 'T')
					tx = i, ty = j;
			}
		}
		int ans = bfs(fx, fy, tx, ty);
		ans == -1 ? printf("impossible\n") : printf("%d\n", ans);
	}
	return 0;
}

