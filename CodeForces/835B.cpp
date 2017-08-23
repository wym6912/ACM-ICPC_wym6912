#include <bits/stdc++.h>

using namespace std;

int x[11];

int main()
{
	int n,i,sum,len,e,ans,tmp;
	while(~ scanf("%d",&n))
	{
		len = 1;
		sum = 0;
		ans = 0;
		memset(x,0,sizeof(x));
		while(~ scanf("%1d",&tmp))
			sum += tmp, x[tmp] ++;
		if(sum >= n)
		{
			printf("0\n");
			continue;
		}
		for(int i = 0;i <= 9;i ++)
			if(sum >= n)break;
			else 
			{
				tmp = 0;
				while(sum < n && tmp < x[i])
				{
					sum += 9 - i;
					ans ++;
					tmp ++;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
