#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int data1[16000003],data2[16000003];
int a[4005],b[4005],c[4005],d[4005];

int main()
{
	int n;
	while(~ scanf("%d",&n))
	{
		int ss = 0,ans = 0;
		for(int i = 1;i <= n;i ++)
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
			{
				data1[(i - 1) * n + j] = a[i] + b[j];
				data2[(i - 1) * n + j] = -(c[i] + d[j]);
			}
		sort(data2 + 1,data2 + n * n + 1);
		for(int i = 1;i <= n * n;i ++)
		{
			int l = 1,r = n * n,mid;
			while(l < r)
			{
				mid = (l + r) >> 1;
				if(data1[i] > data2[mid])l = mid + 1;
				else r = mid ;
			}
			while(data1[i] == data2[l] && l <= n * n)
				ans ++,l ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
