#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y;
	bool num;
};

queue <point> qp;

bool mm[10][10];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool dfs(int x,int y)
{
	mm[x][y] = true;
	for(int i = 0;i <= 3;i ++)
		if(x + dx[i] <= 5 && x + dx[i] >= 1 && y + dy[i] >= 1 && y + dy[i] <= 5)
			if(! mm[x + dx[i]][y + dy[i]] && dfs(x + dx[i], y + dy[i]))
			{
				mm[x][y] = false;
				return false;
			}
	mm[x][y] = false;
	return true;
}

bool doit()
{
	bool flag = false;
	for(int i = 1;i <= 5 && ! flag;i ++)
		for(int j = 1;j <= 5 && ! flag;j ++)
			if(! mm[i][j] && dfs(i, j))
				flag = true;
	if(flag)return false;
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n --)
	{
		for(int i = 1;i <= 5;i ++)
			for(int j = 1;j <= 5;j ++)
				scanf("%1d",&mm[i][j]);
		if(!doit())
			printf("win\n");
		else printf("lose\n");
	}
	return 0;
}
