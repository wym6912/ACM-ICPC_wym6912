#include <bits/stdc++.h>

using namespace std;

int h[200001];

int main()
{
	int n,l;
	long long mina,x;
	while(scanf("%d %d",&n,&l) == 2)
	{
		mina = 1 << 30;
		x = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&h[i]);
			x += (long long)h[i];
			if(i > l) 
				x -= (long long)h[i - l];
			if(i >= l)
				mina = min(x,mina);
		}
		printf("%lld\n",mina);
	}
}
