#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cassert>

#endif

using namespace std;

int movex[9]={0,-1, 0, 1,-1, 1,-1, 0, 1};
int movey[9]={0,-1,-1,-1, 0, 0, 1, 1, 1};
int map0[109][109];
int n,m;
//vector < vector<int> > map0;
	
void bfs(int x,int y)
{
	queue <int> qx,qy;
	qx.push(x);
	qy.push(y);
	while(!qx.empty()&&!qy.empty())
	{
		x=qx.front();
		y=qy.front();
		for(int i=1;i<=8;i++)
				if(map0[x+movex[i]][y+movey[i]])
				{
					map0[x+movex[i]][y+movey[i]]=!map0[x+movex[i]][y+movey[i]];
					qx.push(x+movex[i]);
					qy.push(y+movey[i]);	
				}
		qx.pop();
		qy.pop();
	}
	return ;
}

void dfs(int x,int y)
{
	stack <int> sx,sy;
	sx.push(x);
	sy.push(y);
	while(!sx.empty())
	{
		x=sx.top();
		y=sy.top();
		for(int i=1;i<=8;i++)
			if(map0[x+movex[i]][y+movey[i]] && x+movex[i]<=n && x+movex[i]>0 && y+movey[i] <=m && y+movey[i]>0)
			{
				map0[x+movex[i]][y+movey[i]]=!map0[x+movex[i]][y+movey[i]];
				sx.push(x+movex[i]);
				sy.push(y+movey[i]);
			}
	}
}

int main()
{
	while(~ scanf("%d %d",&n,&m))
	{
	char x;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
			{
				scanf("%c",&x);
				if(x=='W')map0[i][j]=1;
				else if(x=='.')map0[i][j]=0;
				else assert(false);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map0[i][j])
			{
				bfs(i,j);
				//dfs(i,j);
				sum ++;
			}	
	printf("%d\n",sum);
	getchar();
	}
	return 0;
}
