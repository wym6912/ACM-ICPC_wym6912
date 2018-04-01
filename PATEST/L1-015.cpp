#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char ch;
	scanf("%d %c", &n, &ch);
	for(int i = 1; i <= (n + 1) >> 1; i ++)
	{
		for(int j = 1; j <= n; j ++)
			putchar(ch);
		puts("");
	}
	return 0;
}
