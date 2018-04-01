#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x = 0, y = 0, n, p;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d", &p);
		p % 2 ? x ++ : y ++;
	}
	printf("%d %d\n", x, y);
	return 0;
} 
