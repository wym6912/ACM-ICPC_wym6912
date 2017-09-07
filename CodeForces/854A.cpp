#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	while(~ scanf("%d",&n))
	{
		for(int i = n / 2;i >= 1;i --)
			if((n - i != i) && gcd(n - i, i) == 1)
			{
				printf("%d %d\n", i, n - i);
				break;
			}
	}
	return 0;
}
