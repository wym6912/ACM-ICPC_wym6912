#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

struct point
{
	int x,y;
}starting;

int mm[31][31];

int dx[4] = {0,1,0,-1},
    dy[4] = {1,0,-1,0}; 

void put(int n,int m)
{
	cout << endl;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
			cout << mm[i][j] ;
		cout << endl;
	}
}

int bfs(int m,int n)
{
	//put(n,m);
	queue <point> qqq;
	qqq.push(starting);
	point pp;
	int sum = 1;
	while(! qqq.empty())
	{
		pp = qqq.front();
		for(int i = 0;i <= 3;i ++)
			if(pp.x + dx[i] >= 1 && pp.x + dx[i] <= n && pp.y + dy[i] >= 1 && pp.y + dy[i] <= m)
				if(mm[pp.x + dx[i]][pp.y + dy[i]])
				{
					pp.x += dx[i];
					pp.y += dy[i];
					mm[pp.x][pp.y] = 0;
					sum ++;
					//put(n,m);
					qqq.push(pp); 
					pp = qqq.front();
				}
		qqq.pop();
	}
	return sum;
}

int main()
{
	int n,m;
	char x;
	while(~ scanf("%d %d",&n,&m) && (n || m))
	{
		memset(mm,0,sizeof(mm));
		getchar();
		for(int i = 1;i <= m;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				scanf("%c",&x);
				switch(x)
				{
					case '.':
						mm[i][j] = 1;
						break;
					case '#':
						mm[i][j] = 0;
						break;
					case '@':
						mm[i][j] = 0;
						starting.x = i;
						starting.y = j;
						break;
					default:
						assert(0);
				}
			}
			getchar();
		}
		printf("%d\n",bfs(n,m));
	}
	return 0;
}
