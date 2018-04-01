# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isprime(ll x)
{
	if(x == 1)return false; 
	ll sqr = sqrt(x);
	for(int i = 2; i <= sqr; i ++)
		if(! (x % i))
			return false;
	return true;
}

int main()
{
	int n;
	ll x;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%lld", &x);
		isprime(x) ? puts("Yes") : puts("No");
	}
	return 0;
}
