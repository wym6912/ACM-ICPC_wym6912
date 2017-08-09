#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a[200001];

int main()
{
	int n,sum,pp1,pp2;
	while(~ scanf("%d%d",&n,&sum))
	{
		pp1 = 1;
		pp2 = n;
		int ans = 0;
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		int tmp = n;
		for(int i = 1;i <= tmp;i ++)
			for(int j = i + 1;j <= tmp;j ++)
			{
				if(a[i] + a[j] <= sum)
					ans ++;
				else 
				{
					tmp = j;
					break;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
