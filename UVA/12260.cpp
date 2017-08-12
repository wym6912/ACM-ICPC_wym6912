#include <bits/stdc++.h>

using namespace std;

struct candies
{
	int s,t;
}c[10001];

int dp[1001][1001], cost[1001][1001];
int sum;

bool comp(const candies &a,const candies &b)
{
	return a.s != b.s ? a.s > b.s : a.t < b.t;
}

int main()
{
	int T, n;
	char name[7];
	while(~ scanf("%d",&T))
	while(T --)
	{
		memset(dp,0,sizeof(dp));
		sum = 0;
		scanf("%d\n",&n);
		scanf("%s",name);
		for(int i = 1;i <= n;i ++)
			scanf("%d%d",&c[i].s,&c[i].t),sum += c[i].s;
		sort(c + 1, c + n + 1,comp);
		int flag = 0;
		if(name[0] == 'P')flag ++;
		for(int i = 1;i <= n - flag;i ++)
			for(int j = 1;j <= (i + 1) / 2;j ++)
				if(dp[i - 1][j] > dp[i - 1][j - 1] + c[i + flag].t)
					dp[i][j] = dp[i - 1][j],
					cost[i][j] = cost[i - 1][j];
				else if (dp[i - 1][j - 1] == dp[i - 1][j - 1] + c[i + flag].t)
					dp[i][j] = dp[i - 1][j],
					cost[i][j] = min(cost[i - 1][j],cost[i - 1][j - 1] + c[i + flag].s);
				else
					dp[i][j] = dp[i - 1][j - 1] + c[i + flag].t,
					cost[i][j] = cost[i - 1][j - 1] + c[i + flag].s;
		printf("%d %d\n",sum - cost[n - flag][(n - flag + 1) / 2], dp[n - flag][(n - flag + 1) / 2]);
	}
	return 0;
}
