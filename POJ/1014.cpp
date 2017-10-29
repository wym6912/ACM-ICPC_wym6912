#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

bool f[100010];
int e[7];

int main()
{
	bool flag;
	int sum;
	for(int q = 1;;q ++)
	{
		sum = 0;
		flag = false;
		for(int i = 1;i <= 6;i ++)
		{
			scanf("%d",&e[i]);
			if(e[i])
				flag = true,
				sum += e[i] * i;
		}
		if(!flag)return 0;
		printf("Collection #%d:\n",q);
		if(sum & 1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum >>= 1;
		memset(f,false,sizeof(f));
		f[0] = true; 
		for(int i = 1;i <= 6;i ++)
		{
			for(int j = 0;(1 << j) < e[i];j ++)
			{
				int temp;
				e[i] -= (1 << j);
				temp = (1 << j) * i;
				for(int k = sum - 1;k >= 0;k --)
					if(f[k] && k + temp <= sum)
						f[k + temp] = true;
				if(f[sum])
					break;
			}
			if(e[i])
			{
				int temp = e[i] * i;
				for(int k = sum - 1;k >= 0;k --)
					if(f[k] && k + temp <= sum)
						f[k + temp] = true;
				if(f[sum])
					break;
			}
		}
		if(f[sum])printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
}
