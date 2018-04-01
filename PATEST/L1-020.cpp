#include <bits/stdc++.h>

using namespace std;

bool isok[100000];

int main()
{
	int n, q, x;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d", &q);
		for(int i = 1; i <= q; i ++)
			scanf("%d", &x), q == 1 ? false : isok[x] = true;
	}
	bool f = false;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d", &q);
		! isok[q] ? (f ? putchar(' ') : false), (printf("%05d", q), isok[q] = true, f = true): false; 
	}
	f ? puts("") : puts("No one is handsome");
	return 0;
}
