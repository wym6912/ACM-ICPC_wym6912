#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,ppp,x,sum;
	while(~ scanf("%d",&n))
	{
		//ppp = 1;
		sum = 0;
		while(~ scanf("%1d",&x))
			sum += x;
		ppp = n - sum;
		sum = 0;
		while(ppp > 0){ppp /= 10;sum ++;}
		printf("%d\n",sum);
	}
	return 0;
}
