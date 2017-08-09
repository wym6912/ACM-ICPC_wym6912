#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int x[20001];

inline bool cmp(const int a,const int b)
{
	return a > b;
}

int main()
{
	int n,ans;
	while(~ scanf("%d %d",&n,&ans))
	{
		for(int i = 1;i <= n;i ++)
			scanf("%d",&x[i]);
		sort(x + 1,x + n + 1,cmp);
		int ans2 = 0,j = 0;
		while(ans2 < ans)
		{
			j ++;
			ans2 += x[j];
		}
		printf("%d\n",j);
	}
	return 0;
}
