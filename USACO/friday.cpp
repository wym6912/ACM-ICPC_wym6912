/*
ID: wym69121
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int a[8];

int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int x,st = 0;
	scanf("%d",&x);
	for(int i = 0;i < x;i ++)
	{
		for(int k = 1;k <= 12;k ++)
		{
			int s;
			switch (k)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					s = 31;break;
				case 4:
				case 6:
				case 9:
				case 11:
					s = 30;break;
				case 2:
					if((i % 4 == 0 && i % 100) || (i % 100 == 0 && (i + 1900) % 400 == 0))s = 29;
					else s = 28;
					break;
				default:
					assert(1);
			}
			st += 12;
			st %= 7;
			st ++;
			a[st] ++;
			st += s - 13;
		}
	}
	for(int i = 6;i <= 7;i ++)
		printf("%d ",a[i]);
	for(int i = 1;i <= 4;i ++)
		printf("%d ",a[i]);
	printf("%d\n",a[5]);
	return 0;
}
