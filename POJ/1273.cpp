#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

const int inf = 1 << 10;
const int maxn = 20000, maxm = 500000;

struct Edge
{
	int v,f,nxt;
};

int n, src, sink;
int g[maxn + 10];
int nume;
Edge e[maxm * 2 + 10];

void addedge(int u,int v,int c)
{
	e[++ nume].v = v;
	e[nume].f = c;
	e[nume].nxt = g[u];
	g[u] = nume;
	
	e[++ nume].v = u;
	e[nume].f = 0;
	e[nume].nxt = g[v];
	g[v] = nume;
}

void init()
{
	int from, to, cost;
	memset(g,0,sizeof(g));
	nume = 1;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d %d %d",&from, &to, &cost);
		addedge(from,to,cost);
	}
	src = 1;
}

queue <int> que;
bool vis[maxn + 10];
int dist[maxn + 10];

void bfs()
{
	memset(dist,0,sizeof(dist));
	while(! que.empty())que.pop();
	vis[src] = true;
	que.push(src);
	while(! que.empty())
	{
		int u = que.front();
		que.pop();
		for(int i = g[u]; i; i = e[i].nxt)
			if(e[i].f && !vis[e[i].v])
			{
				que.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = true;
			}
	}
}

int dfs(int u,int delta)
{
	if(u == sink)return delta;
	else
	{
		int ret = 0;
		for(int i = g[u]; delta && i; i = e[i].nxt)
			if(e[i].f && dist[e[i].v] == dist[u] + 1)
			{
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i ^ 1].f += dd;
				delta -= dd;
				ret += dd;	
			}
		return ret;
	}
}

int maxflow()
{
	int ret = 0;
	while(true)
	{
		memset(vis,false,sizeof(vis));
		bfs();
		if(! vis[sink])return ret;
		ret += dfs(src, inf);
	}
}

int main()
{
	while(~ scanf("%d%d",&n,&sink))
	{
		init();
		printf("%d\n",maxflow());
	}
	return 0;
}
