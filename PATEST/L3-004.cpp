#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0, 1, 0,-1, 0, 0};
int dy[] = { 1, 0,-1, 0, 0, 0};
int dz[] = { 0, 0, 0, 0, 1,-1};

bool data[61][1287][130];

struct node
{
	int x, y, z;
};

int n, m, k, q, tmpans, ans = 0;

int bfs(int x, int y, int z)
{
	queue <node> qqq;
	int ans = 1;
	node nn, qq;
	nn.x = x;
	nn.y = y;
	nn.z = z;
	data[x][y][z] = false;
	qqq.push(nn);
	while(! qqq.empty())
	{
		nn = qqq.front();
		qqq.pop();
		for(int i = 0; i < 6; i ++)
		{
			qq.x = nn.x + dx[i];
			qq.y = nn.y + dy[i];
			qq.z = nn.z + dz[i];
			if(qq.x > 0 && qq.x <= k && qq.y > 0 && qq.y <= n && qq.z > 0 && qq.z <= m)
				if(data[qq.x][qq.y][qq.z])
				{
					data[qq.x][qq.y][qq.z] = false;
					ans ++;
					qqq.push(qq);
				}
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int l = 1; l <= k; l ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				scanf("%d", &data[l][i][j]);
	for(int l = 1; l <= k; l ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				tmpans = 0;
				if(data[l][i][j])
					tmpans = bfs(l, i, j);
				if(tmpans >= q)
					ans += tmpans;
			}
	printf("%d\n", ans);
	return 0;
}
/*
3 4 5 2 
1 1 1 1 
1 1 1 1 
1 1 1 1 
0 0 1 1 
0 0 1 1 
0 0 1 1 
1 0 1 1 
0 1 0 0 
0 0 0 0 
1 0 1 1 
0 0 0 0 
0 0 0 0 
0 0 0 1 
0 0 0 1 
1 0 0 0 

*/
