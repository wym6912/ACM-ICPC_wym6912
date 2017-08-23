#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int a,b;
	while(~ scanf("%d%d", &a, &b))
	{
		if(a < b)swap(a,b);
		int k = a - b;
		a =(int)(((1 + sqrt(5)) / 2.0) * k);
		if(a == b)
			printf("0\n");
		else printf("1\n");
	}
	return 0;
}
