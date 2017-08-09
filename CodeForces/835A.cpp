#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,v1,v2,t1,t2,ans1,ans2;
	while(~ scanf("%d%d%d%d%d",&a,&v1,&v2,&t1,&t2))
	{
		//if(a >= 3)
		{
			ans1 = a * v1 + t1 * 2;
		    ans2 = a * v2 + t2 * 2;
		}
		/*if(a == 1) 
		{
			ans1 = a * v1 + t1;
			ans2 = a * v2 + t2;
		}
		if(a == 2)
		{
			ans1 = a * v1 + t1;
			ans2 = a * v2 + t2;
			ans1 = max(ans1,a * t1);
			ans2 = max(ans2,a * t1);
		}*/
		if(ans1 > ans2)printf("Second\n");
		else if(ans1 < ans2)printf("First\n");
		else printf("Friendship\n");
	}
	return 0;
}
