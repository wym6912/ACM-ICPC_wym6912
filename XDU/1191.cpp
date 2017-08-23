#include <bits/stdc++.h>

using namespace std;

int cs[5009][28];
char l[5001][10];
int sx[5001];
bool isou[5001];

void reset()
{
	memset(cs,0,sizeof(cs));
	memset(l,'\0',sizeof(l));
	memset(sx,0,sizeof(sx));
	memset(isou,false,sizeof(isou));
}

int main()
{
	int n,poi;
	while(scanf("%d\n",&n) == 1)
	{
		poi = 0;
		reset();
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",l[i]);
			int ss = strlen(l[i]);
			for(int j = 0;j < ss;j ++)
			{
				cs[i][l[i][j] - 'a' + 1] ++;
			}
		}
		for(int i = 1;i <= n;i ++)
			if(!isou[i])
			{
				printf("%s",l[i]);
				isou[i] = true;
				for(int j = 1;j <= n;j ++)
				{
					bool flag3 = true;
					for(int k = 1;k <= 26;k ++)
						if(cs[i][k] != cs[j][k])
						{
							flag3 = false;
							break;
						}
					if(flag3 && ! isou[j])
					{
						printf(" ");
						printf("%s",l[j]);
						isou[j] = true;
					}
				}
				printf("\n");
			}
	}
	return 0;
}
