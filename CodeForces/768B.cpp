#include <bits/stdc++.h>

#define TREE_SIZE 500000
#define print cout << "Passing Line [" <<__LINE__ << "] in " << __FUNCTION__ << ",Index = " << Ind << endl;
using namespace std;

typedef long long ll;

ll query(ll l,ll r,ll datal,ll datar,ll data)
{
	if(l == r)return data;
	ll mid = (l + r) >> 1;
	ll ans = 0;
	if(datal < mid)
		ans += query(l,mid - 1,datal,datar,data >> 1);
	if(datar > mid)
		ans += query(mid + 1,r,datal,datar,data >> 1);
	if(datal <= mid && datar >= mid)
		ans += data % 2;
	return ans;
}

int main()
{
	ll tmp,a,b,l,r,now,len,add;
	while(~ scanf("%I64d%I64d%I64d",&tmp,&a,&b))
	{
		len = 1;
		now = tmp;
		add = 2;
		while(now > 1)
		{
			now >>= 1;
			len += add;
			add <<= 1;	
		}
		printf("%I64d\n",query(1,len,a,b,tmp)); 
	}
	return 0;
}
