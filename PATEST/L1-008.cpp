#include <bits/stdc++.h>

using namespace std;

int main()
{
	int f, t, ans = 0, j = 1;
	scanf("%d%d", &f, &t);
	for(int i = f; i <= t; i ++, j ++)
	{
		printf("%5d", i);
		ans += i;
		j % 5 ?  : putchar('\n');
	}
	if((j - 1) % 5)printf("\n");
	printf("Sum = %d\n", ans);
	return 0;
}
