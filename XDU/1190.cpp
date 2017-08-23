#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,p,sum;
	while(scanf("%lld %lld",&n,&p) == 2)
	{
		sum = 0;
		for(long long i = 1;i <= p;i ++)
		{
			sum += (i % p) * (i % p);
			sum %= p;
		}
		sum += ((n / p) * sum) % p;
		for(long long i = p * (n / p);i <= n;i ++)
		{
			sum += (i % p) * (i % p);
			sum %= p;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
