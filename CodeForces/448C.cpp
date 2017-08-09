#include <bits/stdc++.h>

using namespace std;

int data[5001],n;

void out(int l,int r)
{
	cout << "Call " << __FUNCTION__ << "(): l = " << l << ", r = " << r << endl;
	for(int i = l;i <= r;i ++)
		cout << data[i] << ' ';
	cout << endl;
}

bool iszero(int l,int r)
{
	for(int i = l;i <= r;i ++)
		if(data[i])
			return false;
	return true;
}

int doit(int l,int r)
{
	//cout << "Call " << __FUNCTION__ << "(): l = " << l << ", r = " << r << endl;
	int ans = 0;
	int rr = r,lr = l;
	if(l > r)return 0;
	if(l == r){data[l] = 0;return 1;}
	else 
	{
		int mind = 1 << 30;
		while(! data[l] && l <= rr)l ++;
		while(! data[r] && r >= lr)r --;
		for(int i = l;i <= r;i ++)
			mind = min(mind,data[i]);
		for(int i = l;i <= r;i ++)
			data[i] -= mind;
		ans = mind;
		while(! data[l] && l <= rr)l ++;
		while(! data[r] && r >= lr)r --;
		for(int i = l;i <= r;i ++)
		{
			if(! data[i])
			{
				ans += doit(l,i - 1);
				while(! data[i])i ++;
				l = i;
				i --;
				//out(l,r);
				if(l > r)assert(false);
			}
			else if(i == r)
			{
				while(! data[l])l ++;
				ans += doit(l,r);
			}
		}
		assert(ans >= 0);
	}
	return min(rr - lr + 1,ans);
}

int main()
{
	int ans,mind;
	while(~ scanf("%d",&n))
	{
		mind = 1 << 30;
		ans = 0;
		memset(data,0,sizeof(data));
		for(int i = 1;i <= n;i ++)
			scanf("%d",&data[i]),mind = min(data[i],mind);
		for(int i = 1;i <= n;i ++)
			data[i] -= mind;
		ans += mind;
		int l = 1,r = n;
		while(! data[l] && l <= n)l ++;
		while(! data[r] && r >= 1)r --;
		if(l <= r)
			ans += doit(l,r);
		printf("%d\n",min(ans,n));
	}
	return 0;
}
