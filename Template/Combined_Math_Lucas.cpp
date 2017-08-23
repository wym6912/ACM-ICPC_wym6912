#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 10007;

ll f[10009];
void init() 
{       //f[n] = n!
    f[0] = 1;
    for (int i=1; i<= mod; ++i) f[i] = f[i-1] * i % mod;
} 
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
  
ll Lucas(ll n, ll k)        //C (n, k) % p
{
    ll ret = 1;
    while (n && k) 
	{
        ll nn = n % mod, kk = k % mod;
        if (nn < kk) return 0;  
        ret = ret * f[nn] * pow_mod (f[kk] * f[nn-kk] % mod, mod - 2) % mod;
        n /= mod, k /= mod;
     }
     return ret;
}
int main(void)
{
    init ();
    ll n, m;
    while(~ scanf("%lld%lld",&n,&m))
    printf ("%lld\n", Lucas (m, n));
    return 0;
}
