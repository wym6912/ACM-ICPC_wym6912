#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e7 + 10;
LL fac[maxn];
 
LL qpow(LL a, int b)
{
     LL ret = 1LL;
     while(b)
     {
         if(b & 1) ret = ret * a % mod;
         a = a * a % mod;
         b >>= 1;
     }
     return ret;
}
 
LL inv(LL x)
{
     return qpow(x, mod - 2);
}
 
int main(void)
{
     fac[0] = 1LL;
     for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
     LL x, y, k;
     while(~scanf("%lld %lld %lld", &x, &y, &k))
     {
         if(k > y) puts("0");
         else if(k == y) puts("1");
         else
         {
            // if(x + y >= maxn || x + k >= maxn) while(1);
             LL ans = fac[x + y] * inv(fac[x + k]) % mod * inv(fac[y - k]) % mod;
             printf("%lld\n", ans);
         }
     }
     return 0;
}
