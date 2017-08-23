#include <bits/stdc++.h>

using namespace std;

int store[1001];
int card[5];
int f[41][41][41][41];

int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&store[i]);
	for(int j = 1;j <= m;j ++)
	{
		scanf("%d",&k);
		card[k] ++;
	}
	for(int i = 0;i <= card[1];i ++)
		for(int j = 0;j <= card[2];j ++)
			for(int k = 0;k <= card[3];k ++)
				for(int l = 0;l <= card[4];l ++)
				{
					int &ans = f[i][j][k][l];
					if(i != 0)ans = max(ans,f[i - 1][j][k][l]);
					if(j != 0)ans = max(ans,f[i][j - 1][k][l]);
					if(k != 0)ans = max(ans,f[i][j][k - 1][l]);
					if(l != 0)ans = max(ans,f[i][j][k][l - 1]);
					ans += store[i + 2 * j + 3 * k + 4 * l + 1];
				}
	printf("%d\n",f[card[1]][card[2]][card[3]][card[4]]);
	return 0;
}
