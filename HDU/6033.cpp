#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m,p = 0;
	while(~ scanf("%d",&m))
	{
		printf("Case #%d: %d\n",++ p,(int)floor((double)(m) * log10(2.0)));
	}
	return 0;
} 
