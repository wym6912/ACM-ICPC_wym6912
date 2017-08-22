#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = (ll)1e9 + 7;

ll pow_mod(ll a,ll b)
{
	ll ans = 1;
	a = a % mod;
	while(b)
	{
		if(b & 1)
			ans = (ans * (ll) a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}

int main()
{
	int n;
	while(~ scanf("%d",&n))
	{
		if(n == 1)printf("1\n");
		else if(n % 2)printf("%lld\n", pow_mod(2, n - 1));
		else printf("%lld\n",(pow_mod(2, n - 1) + pow_mod(2, n / 2 - 1)) % mod);
	}
	return 0;
}
