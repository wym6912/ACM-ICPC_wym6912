#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,n;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		printf("%lld\n",(long long)(2*n*n-n+1));
	}
	return 0;
} 