#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,z;
	while(scanf("%lld %lld %lld",&x,&y,&z) == 3)
	{
		if(x == 0 && y == 0 && z == 0)
			printf("inf\n");
		else if(y != 0 && x == 0)
			printf("1\n");
		else if(z != 0 && x == 0 && y == 0)
			printf("0\n");
		else
		{
			if(y * y - 4 * x * z > 0)
				printf("2\n");
			if(y * y - 4 * x * z == 0)
				printf("1\n");
			if(y * y - 4 * x * z < 0)
				printf("0\n");
		}
	}
	return 0 ;
}
