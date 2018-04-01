#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	float q, x, s;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%f%f", &x, &q);
		s = (x - 100) * 0.9 * 2.0;
		if(abs(q - s) < s * 0.1)
			puts("You are wan mei!");
		else if(q - s >= s * 0.1)
			puts("You are tai pang le!");
		else puts("You are tai shou le!");
	}
	return 0;
}
