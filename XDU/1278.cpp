#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll; 

ll f(ll x)
{
	if(x >= 101)return x - 10;
	else return 91;
}

int main()
{
	ll x, n;
	//freopen("1278.in", "r", stdin);
	//freopen("1278.out", "w", stdout);
	scanf("%lld", &n);
	while(n --)
	{
		scanf("%lld", &x);
		printf("%lld\n", f(x));
	}
	return 0;
}
