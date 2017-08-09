#include <bits/stdc++.h>

#define debug printf("Function [%s] in line [%d]",__FUNCTION__,__LINE__)
#define first fi
#define second sc

typedef long long ll;

int a[201],b[201];

using namespace std;

bool comp(const int a,const int b)
{
	return a > b;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++)	
		scanf("%d",&a[i]);
	for(int i = 1;i <= k;i ++)
		scanf("%d",&b[i]);
	sort(b + 1,b + k + 1,comp);
	for(int i = 1,j = 0;i <= n;i ++)
		if(!a[i])
		{
			j ++;
			a[i] = b[j];
		}
	for(int i = 1;i <= n;i ++)
		if(a[i] <= a[i - 1])
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}
