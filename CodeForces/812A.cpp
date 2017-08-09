#include <bits/stdc++.h>

using namespace std;

bool a[5][5];
bool p[5];

int main()
{
	for(int i = 1;i <= 4;i ++)
		for(int j = 1;j <= 4;j ++)
			scanf("%d",&a[i][j]);
	for(int i = 1;i <= 4;i ++)
		if(a[i][4] && (a[i][1] == a[i][4] || a[i][2] == a[i][4] || a[i][3] == a[i][4]))
		{
			printf("YES\n");
			return 0;
		}
	for(int i = 1;i <= 4;i ++)
	{
		if(a[i][1])
			p[((i - 1 + 4) % 4) ? (i - 1 + 4) % 4 : 4] = true;
		if(a[i][2])
			p[((i - 2 + 4) % 4) ? (i - 2 + 4) % 4 : 4] = true;
		if(a[i][3])
			p[((i + 1) % 4) ? (i + 1) % 4 : 4] = true;
	}
	for(int i = 1;i <= 4;i ++)
	{
		if(a[i][4])
			if(p[i])
			{
				printf("YES\n");
				return 0;
			}
	}
	printf("NO\n");
	return 0;
} 
