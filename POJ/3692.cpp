#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool g[1002][1002];
int ans;
int len[10002], mc[10001], list[1001][1001];
int gg,b,q,n;
bool found;

void dfs(int size)
{
	int i, j, k;
	if(len[size] == 0)
	{
		if(size > ans)
			ans = size,
			found = true;
		return ;
	}
	for(k = 0;k < len[size] && ! found;k ++)
	{
		if(size + len[size] - k <= ans)break;
		i = list[size][k];
		if(size + mc[i] <= ans)break;
		for(j = k + 1, len[size + 1] = 0; j < len[size]; j ++)
			if(g[i][list[size][j]])
				list[size + 1][len[size + 1] ++] = list[size][j];
		dfs(size + 1);
	}
}

void max_cluster()
{
	int i, j;
	mc[n] = ans = 1;
	for(i = n - 1; i; -- i)
	{
		found = false;
		len[1] = 0;
		for(j = i + 1;j <= n;j ++)
			if(g[i][j])
				list[1][len[1] ++] = j;
		dfs(1);
		mc[i] = ans;
	}
}

int main()
{
	int xx = 0,from, to;
	while(~ scanf("%d%d%d",&gg,&b,&q) && (gg || b || q))
	{
		xx ++;
		memset(g,true,sizeof(g));
		memset(len,0,sizeof(len));
		memset(list,0,sizeof(list));
		memset(mc,0,sizeof(mc));
		ans = 0;
		n = gg + b;
		for(int i = 1;i <= gg + b;i ++)g[i][i] = false;
		g[gg][gg + 1] = g[gg + 1][gg] = false;
		for(int i = 1;i <= q;i ++)
		{
			scanf("%d%d",&from,&to);
			g[from][to + gg] = false;
			g[to + gg][from] = false;
		}
		max_cluster();
		printf("Case %d: %d\n",xx,ans);
	}
	return 0; 
} 
