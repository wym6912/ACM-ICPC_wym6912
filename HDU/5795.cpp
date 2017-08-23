#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, T, tmp, ans;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d",&n);
		ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&tmp);
			if(tmp % 8 == 7)
				ans ^= (tmp + 1);
			else if(tmp % 8 == 0)
				ans ^= (tmp - 1);
			else ans ^= tmp;
		}
		if(ans)
			printf("First player wins.\n");
		else printf("Second player wins.\n");
		//printf("%d\n",a[0]);
	}
	return 0;
}
