#include <bits/stdc++.h>

using namespace std;

bool cmp_0(const int a,const int b)
{
	return a < b;
}

bool cmp_1(const int a,const int b)
{
	return a > b;
}

int main()
{
	int nn[10];
	memset(nn,0,sizeof(nn));
	int a[1001],b[1001],n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%1d",&a[i]);
	for(int i = 1;i <= n;i ++)
		scanf("%1d",&b[i]);
	sort(a + 1,a + n + 1,cmp_0);
	sort(b + 1,b + n + 1,cmp_0);
	int count = 0;
	for(int i = 1;i <= n;i ++)
		nn[b[i]] ++;
	for(int i = 1;i <= n;i ++)
	{
		bool flag = false;
		for(int j = 0;a[i] + j <= 9;j ++)
			if(nn[a[i] + j])
			{
				flag = true;
				nn[a[i] + j] --;
				break;
			}
		if(!flag)
		for(int i = 0;i <= 9;i ++)
			if(nn[i])
			{
				nn[i] -- ;
				count ++;
				break;
			}
	}
	printf("%d\n",count);
	count = 0;
	memset(nn,0,sizeof(nn));
	for(int i = 1;i <= n;i ++)
		nn[b[i]] ++;
	for(int i = 1;i <= n;i ++)
	{
		bool flag = false;
		for(int j = 1;a[i] + j <= 9;j ++)
			if(nn[a[i] + j])
			{
				flag = true;
				count ++;
				nn[a[i] + j] --;
				break;
			}
		if(!flag)
		for(int i = 0;i <= 9;i ++)
			if(nn[i])
			{
				nn[i] -- ;
				break;
			}
	}
	printf("%d\n",count);
	return 0;
}
