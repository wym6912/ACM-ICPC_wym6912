#include <bits/stdc++.h>

using namespace std;

int f[201][201];

int main()
{
	int n;
	int x[201];
	scanf("%d",&n);
	x[0] = 0;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&x[i]);
		x[i] += x[i - 1];
	}
	memset(f,126,sizeof(f));
	for(int i = 1;i <= n;i ++)f[i][i] = 0;
	for(int i = n - 1;i >= 1;i --)
		for(int j = i + 1;j <= n;j ++)
			for(int k = i;k < j;k ++)
				f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j] + x[j] - x[i - 1]);
	printf("%d\n",f[1][n]);
	return 0;
} 
