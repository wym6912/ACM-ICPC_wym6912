#include<stdio.h>
#include<math.h>
#define MAXN 16

int ans[MAXN+10], vis[MAXN+10], p[MAXN*2+10];
int n;

int is_prime(int x)
{
	int a;
	int i;
	if(x==1) return 0;
	a = sqrt(x);
	for(i=2; i<=a; i++)
		if(x%i==0)
			return 0;
	return 1;
}

void dfs(int t)
{
	int i;
	if(t>n)
	{
		if(p[ans[1]+ans[n]])
		{
			for(i=1; i<=n; i++)
			printf("%d ", ans[i]);
			printf("\n");
		} 
	}
	else
	{
		for(i=2; i<=n; i++)
			if(vis[i]==0 && p[ans[t-1]+i])
			{
				vis[i] = 1;
				ans[t] = i;
				dfs(t+1);
				vis[i] = 0;
			}
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i=3; i<=n*2; i++)
		p[i] = is_prime(i);
	vis[1]=1;
	ans[1]=1;
	dfs(2);
	return 0;
}
