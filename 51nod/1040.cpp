#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long ll;

bool judge(ll x)
{
	ll qx = (ll)sqrt(x);
	for(ll i = 2;i <= qx;i ++)
		if(!(x % i))
			return false;
	return true;
}

ll phi(ll x)
{
	if(x == 1)return 1;
	else
	{
		if (judge(x))return x - 1;
		else
		{
			ll phix = x;
			ll y = (ll)(sqrt(x));
			ll i = 2;
			while(i <= y)
			{
				if(x % i == 0)
				{
					phix -= phix / i;
					do{x /= i;}while(x % i == 0);
				}
				i ++;
				y = (ll)(sqrt(x));
			}
			if(x != 1)phix -= phix / x;
			return phix;
		}
	}
}
int main()
{
	ll x, ans;
	while(~ scanf("%d",&x))
	{
		ans = 0;
		for(ll i = 1;i * i <= x;i ++)
		{
			if(x % i)continue;
			ll t = x / i;
			ans += i * phi(t);
			if(i != t)ans += t * phi(x / t);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
