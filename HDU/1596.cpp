#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1009;
int N;
const float eps = 1e-4;
float g[MaxN][MaxN];

void floyed()
{
	for(int k = 1;k <= N;k ++)
		for(int i = 1;i <= N;i ++)
			for(int j = 1;j <= N;j ++)
				g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
}

int main()
{
	int q,from,to;
	while(~ scanf("%d",&N))
	{
		for(int i = 1;i <= N;i ++)
			for(int j = 1;j <= N;j ++)
				scanf("%f",&g[i][j]);
		floyed();
		scanf("%d",&q);
		for(int i = 1;i <= q;i ++)
		{
			scanf("%d%d",&from,&to);
			if(fabs(g[from][to] - eps) < 1e-4)
				printf("What a pity!\n");
			else printf("%.3f\n",g[from][to]);
		}		
	}
	return 0;
}
