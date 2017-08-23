#include <bits/stdc++.h>

using namespace std;

int num[1001];

int main()
{
	int n, k, tmp;
	while(~ scanf("%d%d",&n,&k))
	{
		memset(num,0,sizeof(num));
		tmp = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&num[i]);
			num[0] += num[i];
			num[i] += tmp;
			tmp = 0;
			if(num[i] / 8 && num[i] != 8)
			{
				tmp = num[i] - 8;num[i] -= tmp;
			}
		}
		if(k > num[0] || n * 8 < k)
		{
			printf("-1\n");
			continue;
		}
		bool flag = true;
		for(int i = 1;i <= n;i ++)
		{
			k -= num[i];
			if(k <= 0)
			{
				printf("%d\n", i);
				flag = false;
				break;
			}
		}
		if(flag)printf("-1\n");
	}
	return 0;
}
