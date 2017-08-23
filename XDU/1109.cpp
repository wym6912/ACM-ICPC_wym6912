#include <bits/stdc++.h>

using namespace std;

int mod = 10007;

int ma[1000001];

int main()
{
	int n;
	int ams = 4;
	ma[1] = 1;
	ma[2] = 2;
	ma[3] = 4;
	while( ~ scanf("%d",&n))
	{
		for(int i = ams;i <= n;i ++)
		{
			ma[i] = (ma[i - 1] + ma[i - 2] + ma[i - 3]) % mod;
			ams ++;
		}
		printf("%d\n",ma[n]);
	}
	return 0;
}
