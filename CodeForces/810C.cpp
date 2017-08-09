#include <bits/stdc++.h>

using namespace std;



typedef long long LL;

const LL mod = 1e9 + 7;

LL x[300001];
LL y[300001];

int main()
{
	int n;
	LL sum = 0,sum2 = 0,tmp;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%I64d",&x[i]),
		x[i] %= mod;
	sort(x + 1,x + n + 1);
	int s = 1;
	for(int i = 1;i <= n;i ++)
	{
		tmp = x[i] * s;
		tmp %= mod;
		tmp -= x[n - i + 1] * s;
		if(tmp <= 0)
			tmp += mod;
		tmp %= mod;
		sum += tmp;
		sum %= mod;
		s = ((s % mod) * 2) % mod;
	}
	printf("%I64d\n",(sum + mod) % mod);
	return 0;
}
