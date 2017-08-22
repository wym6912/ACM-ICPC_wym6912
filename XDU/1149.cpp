#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = int (1e9 + 7);

ll f[2000002], inv[2000002];

ll pow_mod(ll a, ll x)
{
    ll ret = 1;
    while (x)
    {
        if (x & 1)  ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}
  
ll C(ll n, ll k)        //C (n, k) % p
{
	ll ret = (n < k) ? 0 : (((f[n] % mod) * inv[n - k] % mod) * inv[k] % mod) % mod;
    return ret;
}

void init() 
{       //f[n] = n!,inv[n] = 1 / n!
    f[0] = 1;
    for (int i = 1; i <= 2000000; ++ i) f[i] = f[i - 1] * i % mod;
    inv[2000000] = pow_mod(f[2000000], mod - 2);
	for(int i = 2000000;i >= 1;i --)
		inv[i - 1] = inv[i] * (i) % mod;
} 

int main(void)
{
    init ();
    ll n, m, k, tmp;
    while(~ scanf("%lld%lld%lld",&n,&m,&k))
    {
    	if(n * k < m)
    	{
    		printf("0\n");
    		continue;
    	}
    	if(k > m)k = m;
    	ll ans = C(n + m - 1, m), sign = -1;
    	for(ll i = 1;i <= n;i ++, sign = -sign)
    	{
    		ll tmp = m - i * (k + 1);
    		if(tmp < 0)break;
    		ans = ((ans % mod) + (sign * C(n, i) * C(n + tmp - 1, tmp) % mod) % mod) % mod;
    	}
    	printf("%lld\n", (ans + mod) % mod);
	}
    return 0;
}

/**************************************************************
    Problem: 1149
    User: 16020120071
    Language: C++
    Result: ÕýÈ·
    Time:82 ms
    Memory:32956 kb
****************************************************************/
