#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

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

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
		printf("%d\n",phi(x));
	return 0;
}

