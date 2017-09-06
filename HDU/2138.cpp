#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int S = 8;

//Calculate ret = (a * b) % c
ll mult_mod(ll a, ll b, ll c)
{
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c)ret -= c;
		}
		tmp <<= 1;
		if(tmp > c)tmp -= c;
		b >>= 1;
	}
	return ret;
}

//Calculate ret = (a ^ n) % mod
ll pow_mod(ll a, ll n, ll mod)
{
	ll ret = 1;
	ll tmp = a % mod;
	while(n)
	{
		if(n & 1)
			ret = mult_mod(ret, tmp, mod);
		tmp = mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}

//a^(n - 1) == 1 (mod n) 判断 
//合数返回 true，不一定是合数返回 false 
bool check(ll a, ll n, ll x,ll t)
{
	ll ret = pow_mod(a, x, n);
	ll last = ret;
	for(int i = 1;i <= t;i ++)
	{
		ret = mult_mod(ret, ret, n);
		if(ret == 1 && last != 1 && last != n - 1)return true;
		last = ret;
	}
	if(ret != 1)return true;
	return false;
}

//Miller_Rabin
//true 是素数 
bool Miller_Rabin(ll n)
{
	if(n < 2)return false;
	if(n == 2)return true;
	if(!(n & 1))return false;
	ll x = n - 1;
	ll t = 0;
	while(!(x & 1)){x >>= 1;t ++;}
	srand(*new int);
	for(int i = 0;i < S;i ++)
	{
		ll a = rand() % (n - 1) + 1;
		if(check(a, n, x, t))
			return false;
	}
	return true;
}

int main()
{
	int n;
	ll data;
	while(~ scanf("%d",&n))
	{
		int ans = 0;
		while(n --)
		{
			scanf("%I64d", &data);
			ans += Miller_Rabin(data) ? 1 : 0;
		}
		printf("%d\n", ans);
	}
} 
