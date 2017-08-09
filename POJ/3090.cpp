#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int phixxx[1001];

bool judge(int x)
{
	for(int i = 2;i <= sqrt(x);i ++)
		if(! (x % i))return false;
	return true;
}

int phi(int x)
{
	if(x == 1)return 1;
	else
	{
		if (judge(x))return x - 1;
		else
		{
			int phix = x;
			int y = (int)(sqrt(x));
			int i = 2;
			while(i <= y)
			{
				if(x % i == 0)
				{
					phix -= phix / i;
					do{x /= i;}while(x % i == 0);
				}
				i ++;
				y = (int)(sqrt(x));
			}
			if(x != 1)phix -= phix / x;
			return phix;
		}
	}
}

void xphi()
{
	for(int i = 1;i <= 1000;i ++)
		phixxx[i] = phi(i);
}

int main()
{
	int T, n, ans;
	xphi();
	while(~ scanf("%d",&T))
	{
		for(int xx = 1;xx <= T;xx ++)
		{
			scanf("%d",&n);
			ans = 0;
			for(int i = 1;i <= n;i ++)
			{
				ans += phixxx[i];
			}
			printf("%d %d %d\n", xx, n, 2 * ans + 1);
		}
	}
	return 0;
}
