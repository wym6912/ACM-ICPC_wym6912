#include <bits/stdc++.h>

using namespace std;

int f[201][201];

void out(int n)
{
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
			cout << setw(10) << f[i][j] << ' ' ;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n;
	int x[201];
	scanf("%d",&n);
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&x[i]);
		if(i != n)
			x[i + n] = x[i];
	}
	for(int i = 1;i <= n;i ++)f[i][i] = 0;
	memset(f,0,sizeof(f));
	for (int len = 2; len <= n; len ++)
		for (int l = 0; l + len - 1 < 2 * n - 1; l ++)
		{
			int r = l + len - 1;
			f[l][r] = 0;
			for (int k = l; k < r; k++)
				f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + x[l] * x[k + 1] * x[r + 1]);
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, f[i][i + n - 1]);
	printf("%d\n",ans);
	return 0;
} 
