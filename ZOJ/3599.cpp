#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000000 + 9;

typedef long long ll;

ll a[maxn], b[maxn];

int main()
{
	ll n, m;
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%lld%lld",&n,&m);
		a[0] = b[0] = 1;
		int i = 0, j = 0;
		while(m > a[i])
		{
			i ++;
			a[i] = b[i - 1] + 1;
			while(a[j + 1] * n < a[i])  
                j ++;  
            if(a[j] * n < a[i])  
                b[i] = b[j] + a[i];  
            else  
                b[i] = a[i];  
        }  
        long long ans;  
        if(m == a[i])  
            ans = (long long)m - i - 1;//因为n不能取N所以要减1   
        else  
            ans = (long long)m - i;//i是a的下标，也正好是比N小的不能取的数的个数   
        printf("%lld\n", ans);  
    }  
    return 0;  
}  
