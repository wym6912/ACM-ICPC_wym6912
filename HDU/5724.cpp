#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y;
	bool num;
};

queue <point> qp;

bool mm[300][300];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n;

bool dfs(int x,int y)
{
	mm[x][y] = true;
	for(int i = 0;i <= 3;i ++)
		if(x + dx[i] <= n && x + dx[i] >= 1 && y + dy[i] >= 1 && y + dy[i] <= 20)
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
	for(int i = 1;i <= n && ! flag;i ++)
		for(int j = 1;j <= 20 && ! flag;j ++)
			if(! mm[i][j] && dfs(i, j))
				flag = true;
	if(flag)return false;
	return true;
}

int main()
{
	int T, nn, tmp;
	scanf("%d",&T);
	while(T --)
	{
		memset(mm, false, sizeof(mm));
		scanf("%d", &n);
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d", &nn);
			for(int j = 1;j <= nn;j ++)
			{
				scanf("%d",&tmp);
				mm[i][tmp] = true;
			}
		}
		if(! doit())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
