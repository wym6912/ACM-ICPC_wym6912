#include <bits/stdc++.h>

using namespace std;

int data[109];

int main()
{
	int n;
	while(~ scanf("%d",&n))
	{
		bool flag = true;
		for(int i = 1;i <= n;i ++)
			scanf("%d",&data[i]);
		if(!(n % 2))
		{
			flag = false;
		}
		if(! (data[1] & 1) || !(data[n] & 1))
		{
			flag = false;
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
