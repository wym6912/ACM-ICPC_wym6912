#include <cstdio>
#include <cstring>

using namespace std;

int nn[100], rig[100], lef[100];

int ans[20], n;

void dfs(int x)
{
	if(x == n + 1)
	{
		ans[n] ++;
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(! nn[i] && ! rig[i + x] && ! lef[i - x + n - 1])
		{
			nn[i] = 1;
			rig[i + x] = 1;
			lef[i - x + n - 1] = 1;
			dfs(x + 1);
			nn[i] = 0;
			rig[i + x] = 0;
			lef[i - x + n - 1] = 0;
		}
	}
}

int main()
{
	memset(ans, 0, sizeof(ans));
	while(~ scanf("%d", &n) && n)
	{
		if(ans[n])
			printf("%d\n",ans[n]);
		else
		{
			dfs(1);
			printf("%d\n",ans[n]);
		}
	}
	return 0;
}
