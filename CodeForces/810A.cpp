#include <bits/stdc++.h>

using namespace std;

int sc[101];

int main()
{
	int n,a;
	scanf("%d %d",&n,&a);
	int sum = 0;
	float ave = 0.0;
	for(int i = 1;i <= n;i ++)
		scanf("%d",&sc[i]),sum += sc[i];
	ave = float(float(sum) / float(n));
	for(int i = 0;;i ++)
	{
		if(fabs(ave - a) <= 0.5)
		{
			printf("%d\n",i);
			break;
		}
		else
		{
			sum += a;
			n ++;
			ave = float(float(sum) / float(n));
			
		}
	} 
	return 0;
}
