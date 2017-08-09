#include <bits/stdc++.h>

using namespace std;

char lista[8] = "\0aabb";

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		putchar(lista[(i - 1) % 4 + 1]);
	printf("\n");
	return 0;
}
