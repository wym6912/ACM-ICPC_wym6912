#include <bits/stdc++.h>

#define INF 1 << 15

using namespace std;

int n;
int graph[101][101];
int a,b;

void reset()
{
	memset(graph,127,sizeof(graph));
}

void init()
{
	int from,to,cost;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d %d %d",&from,&to,&cost);
		graph[from][to] = cost;
		graph[to][from] = cost;
	}
	scanf("%d %d",&a,&b);
}

void Dijkstra()
{
	int dis[101];
	int sd = 0;
	int ax = a;
	bool flag[101];
	for(int i = 1;i <= 100;i ++)
	{
		flag[i] = false;
		dis[i] = graph[a][i];
	}
	flag[a] = true;
	dis[a] = 0;
	for(int i = 1;i <= 99;i ++)
	{
		sd = INF;
		for(int j = 1;j <= 100;j ++)
			if(!flag[j] && sd > dis[j])
			{
				sd = dis[j];
				ax = j;
			}
		flag[ax] = true;
		for(int j = 1;j <= 100;j ++)
			if(!flag[j] && dis[ax] + graph[ax][j] < dis[j])
			{
				dis[j] = dis[ax] + graph[ax][j];
			}
	}
	printf("%d\n",dis[b] * 2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		reset();
		init();
		Dijkstra();
	}
    return 0;
}
