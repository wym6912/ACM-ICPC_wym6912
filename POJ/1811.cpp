#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pow_mod(ll a,ll d,ll n)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1)
			res = res * a % m;
		a = a * a % m;
		n /= 2;
	}
	return res;
}

bool check(ll a,ll n,ll d,ll r)
{
	ll x = pow_mod(a, d, n);
	ll last = x;
	for(int i = 1;i <= r;i ++)
	{
		x = x * x % n;
		if(x == 1 && last != 1 && last != n - 1)
			return true;
		last = x;
	
	}
	if(x != 1)return true;
	return false;
}

bool Miller_Rabin(ll n)
{
	if(n == 1 || !(n & 1))return false;
	if(n == 2)return true;
	ll d = n - 1, r = 0;
	while(!(d & 1))d >>= 1,r ++;
	srand(*new int);
	for(int i = 0;i < 50;i ++)
	{
		ll a = rand() % (n - 1) + 1;
		if(check(a, n, d, r))return false;
	}
	return true;
}

