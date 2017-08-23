#include <bits/stdc++.h>

using namespace std;

int main()
{
	int fib[48],query_place;
	fib[1] = fib[2] = 1;
	for(int i = 3;i <= 48;i ++)
		fib[i] = fib[i - 1] + fib[i - 2];
	while(~ scanf("%d",&fib[0]) && fib[0])
	{
		query_place = find(fib + 1, fib + 1 + 48, fib[0]) -  fib;
		if(fib[0] == fib[query_place])
			printf("Second win\n");
		else printf("First win\n");
	}
	return 0;
}
