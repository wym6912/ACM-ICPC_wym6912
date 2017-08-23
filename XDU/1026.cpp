#include <bits/stdc++.h>
 
using namespace std;
 
int pow_mod(int a, int b, int mod)
{
    if(! b)return 1;
    int ans = pow_mod(a, b >> 1, mod);
    ans = ans * ans % mod;
    if(b & 1)
        ans = ans * a % mod;
    return ans;
}
 
int main()
{
    int a, b, mod;
    while(~ scanf("%d%d%d",&a,&b,&mod))
        printf("%d\n",pow_mod(a, b, mod));
    return 0;
}
/**************************************************************
    Problem: 1026
    User: 16020120071
    Language: C++
    Result: ÕýÈ·
    Time:2 ms
    Memory:1700 kb
****************************************************************/
