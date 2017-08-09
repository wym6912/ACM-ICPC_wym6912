#include <bits/stdc++.h>

using namespace std;

int f[9001];
int k[1001];
int w[1001];

int main()
{
	int S,n;
	scanf("%d",&S);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d %d",&w[i],&k[i]);
	memset(f,0,sizeof(f));
	for(int i = 1;i <= n;i ++)
		for(int j = S;j >= w[i];j --)
			f[j] = max(f[j],f[j - w[i]] + k[i]);
	printf("%d\n",f[S]);
	return 0;
}
