#include <bits/stdc++.h>

#define debug printf("Function [%s] in line [%d]",__FUNCTION__,__LINE__)
#define first fi
#define second sc

typedef long long ll;

char aa[2000];
int dis[27][2000];
int ispp[27];
char aaaa;

using namespace std;

int main()
{
	int n;
	scanf("%d\n",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%c",&aa[i]);
	scanf("\n");
	for(int i = 1;i <= n;i ++) 
		if(ispp[aa[i] - 'a' + 1])
		{
			ispp[aa[i] - 'a' + 1] = 0;
			dis[aa[i] - 'a' + 1][0] ++;
			dis[aa[i] - 'a' + 1][dis[aa[i] - 'a' + 1][0]] = i - ispp[aa[i] - 'a' + 1] - 1;
		}
	int m,diss;
	scanf("%d\n",&m);
	for(int i = 1;i <= m;i ++)
	{
		scanf("%c %d\n",&aaaa,&diss);
		for(int j = 1;j <= dis[aaaa - 'a' + 1][0];j ++)
			
	}
	return 0;
}
