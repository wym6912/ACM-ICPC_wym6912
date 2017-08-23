#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll q = 2147483647;
const ll a = 3;

ll pow_mod(ll a,ll i,ll n)
{
	if(i == 0)return 1 % n;
	ll temp = pow_mod(a,i >> 1, n);
	temp = temp * temp % n;
	if(i & 1)temp = (ll)temp * a % n;
	return temp;
}

ll discrete_log(ll x,ll n,ll m)
{
	//if(n >= m)return -1;
	//x %= m,n %= m;
	map <ll, int> rec;
	int s = (int)(sqrt(double(m)));
	while((ll)s * s <= m)s ++;
	ll cur = 1;
	for(int i = 0;i < s;i ++)
	{
		rec[cur] = i;
		cur = cur * x % m;
	}
	ll mul = cur;
	cur = 1;
	for(int i = 0;i < s;i ++)
	{
		ll more = (ll)n * pow_mod(cur, m - 2, m) % m;
		if(rec.count(more))return i * s + rec[more];
		cur = cur * mul % m;
	}
	return -1;
}

int main()
{
	ll xa, ya, xb, yb;
	while(~ scanf("%lld%lld",&ya,&yb))
	{
		xa = discrete_log(a, ya, q);
		xb = discrete_log(a, yb, q);
		if(xa == -1 || xb == -1)printf("No Solution\n");
		else printf("%lld\n",pow_mod(pow_mod(a, xa, q), xb, q));
	}
	return 0;
}
