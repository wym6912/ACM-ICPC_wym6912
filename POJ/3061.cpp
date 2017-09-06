#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, S;
int a[100009];

int sum[100010];

void solve()
{
	//Calcuate SUM
	sum[1] = 0;
	for(int i = 1;i <= n;i ++)
		sum[i + 1] = sum[i] + a[i];
	if(sum[n + 1] < S) // SUM ²»´æÔÚ 
	{
		printf("0\n");
		return ;
	}
	int res = n;
	for(int s = 1;sum[s] + S <= sum[n + 1];s ++)
	{
		//Binary_SEARCH
		int t = lower_bound(sum + s, sum + n + 1, sum[s] + S) - sum;
		res = min(res, t - s);
	}
	printf("%d\n", res);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d%d",&n,&S);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		solve();
	}
	return 0;
}
