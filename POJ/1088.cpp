#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[1001][1001];
int map[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n, m;

int DFS(int x,int y)
{
	if(f[x][y])return f[x][y];
	for(int i = 0;i <= 3;i ++)
	{
		int xx = x + dx[i];
		int xy = y + dy[i];
		if(xx >= 1 && xx <= n && xy >= 1 && xy <= m)
			if(map[xx][xy] < map[x][y])
				f[x][y] = max(DFS(xx, xy) + 1, f[x][y]);
	}
	return f[x][y];
}

int main()
{
	while(~ scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				scanf("%d",&map[i][j]);
		int ans = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				ans = max(ans, DFS(i, j));
		printf("%d\n",ans + 1);
	}
	return 0;
}
