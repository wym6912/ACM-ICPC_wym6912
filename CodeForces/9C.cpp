#include <bits/stdc++.h>

using namespace std;

int data[100000];
int seq[2] = {0,1};

void constrct()
{
	int x = 1;
	for(int i = 1;i <= 10;i ++, x *= 10) 
		for(int j = 1;j <= (1 << 11);j ++)
		{
			data[j] += seq[(j >> i) % 2] * x;
		}
}

int main()
{
	int n,ans,tmp,tmp2;
	bool flag;
	constrct();
	while(~ scanf("%d",&n))
	{
		ans = upper_bound(data + 1,data + (1 << 11),n) - (data + 1);
		printf("%d\n",(ans + 1) / 2 - 1);
	}
	return 0;
}
