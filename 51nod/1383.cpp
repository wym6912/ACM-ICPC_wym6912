#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

ll f[1000005];

ll ans(int n)
{
	if(! n)return 0;
	if(f[n])return f[n] % mod;
	if(n & 1)
		return f[n] = ans(n - 1) % mod;
	else return f[n] = (ans(n - 1) + ans(n / 2)) % mod;
}

int main()
{
	int n;
	//f[0] = 1;
	f[1] = 1;
	for(int i = 2;i <= 1000000;i ++)
	{
		if(i & 1)
			f[i] = f[i - 1] % mod;
		else f[i] = (f[i - 1] + f[i / 2]) % mod;
	} 
	while(~ scanf("%d",&n))
		printf("%I64d\n",f[n]);
	return 0;
}
