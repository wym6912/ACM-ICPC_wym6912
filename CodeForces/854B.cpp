#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, k;
	while(~ scanf("%I64d%I64d",&n,&k))
	{
		if(k == 0 || k == n)puts("0 0");
		else
		{
			printf("1 ");
			if(k * 3 >= n)printf("%I64d\n",(n - k));
			else printf("%I64d\n",2 * k);
		}
	}
	return 0;
}
