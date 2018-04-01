#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char str[100];
	int x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("\n%s%d%d", str, &x, &y);
		if(!(x <= 20 && x >= 15) || !(y <= 70 && y >= 50))
			puts(str);
	}
	return 0;
}
