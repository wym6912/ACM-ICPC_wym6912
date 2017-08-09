#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll num[100001],ans[100001],tmp[100001];
int n;
ll cost;

bool count(int x)
{
	ll sum = 0;
	for(ll i = 1;i <= n;i ++)
		tmp[i] = num[i] + i * x;
	sort(tmp + 1,tmp + 1 + n);
	for(int i = 1;i <= x;i ++)
		sum += tmp[i];
	ans[x] = sum;
	if(cost < sum)
		return false;
	return true;
}

int main()
{
	//freopen("812c_.in","r",stdin);
	scanf("%d%I64d",&n,&cost);
	for(int i = 1;i <= n;i ++)
		scanf("%I64d",&num[i]);
	int l = 0,r = n,p;
	int aa;
	while(l <= r)
	{
		p = (l + r) >> 1;
		if(count(p))  
		{
			aa = p;
			l = p + 1;
		}
		else
		{
			r = p - 1;
		}
	}
	count(l);
	printf("%d %I64d\n",aa,ans[aa]);
	return 0;
} 
