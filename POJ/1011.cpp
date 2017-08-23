#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int sticks[1100],isused[1100];

int num,every,n;

bool DFS(int fir,int las)
{
	for(int i = n;i >= fir + 1;i --)
		if(! isused[i] && sticks[i] + sticks[fir] == every)
		{
			isused[i] = 1;
			int j;
			for(j = fir + 1;j <= i;j ++)
				if(sticks[j] != sticks[fir])
					break;
				else isused[j] = 1;
			int k,l;
			for(k = i,l = 1;l <= j - fir;k --,l ++)
				if(sticks[i] != sticks[k])
					return 0;
				else isused[k] = 1;
			if(! DFS(j + 1,k - 1))return 0;
		}
	return 1;
}

bool comp(const int & a,const int & b)
{
	return a > b;
}

int main()
{
	int sum,maxl,ans;
	while(~ scanf("%d",&n) && n)
	{
		sum = 0;
		ans = 0;
		memset(isused,false,sizeof(isused));
		for(int i = 1;i <= n;i ++)
			scanf("%d",&sticks[i]),sum += sticks[i];
		sort(sticks + 1,sticks + 1 + n,comp);
		maxl = sticks[1];
		for(int i = maxl;i <= sum;i ++)
		{
			if(sum % i == 0)
			{
				every = i;
				num = sum / i;
				if(DFS(1,n))
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
} 
