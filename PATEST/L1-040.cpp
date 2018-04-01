#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char ch;
	float x;
	scanf("%d", &n);
	while(n --)
	{
		scanf("\n%c %f", &ch, &x);
		switch (ch)
		{
			case 'M':
				printf("%.2f\n", x / 1.09);
				break;
			case 'F':
				printf("%.2f\n", x * 1.09);
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
