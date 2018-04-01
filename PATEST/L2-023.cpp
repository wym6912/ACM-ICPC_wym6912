#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	int to, next;
}edge;

edge edg[500 * 499];
int fir[509], tot;
int color[509], j11[509];
bool visited[509];

int n, m, k, q;

void addedge(int f, int t)
{
	tot ++;
	edg[tot].to = t;
	edg[tot].next = fir[f];
	fir[f] = tot;
}

bool dfs(int x)
{
	bool flag = true;
	if(! visited[x])
	{
		visited[x] = true;
		for(int i = fir[x]; i; i = edg[i].next)
		{
			if(! visited[edg[i].to])
			{
				if(color[x] != color[edg[i].to])
					flag = dfs(edg[i].to);
				else return false;
			}
			if(! flag)return false;
		}
	}
	return flag;
}

bool judge()
{
	bool flag = true;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i ++)
		if(! visited[i])
		{
			flag = dfs(i);
			if(! flag)return false;
		}
	return flag;
}

int main()
{
	int f, t;
	scanf("%d%d%d", &n, &m, &k);
	tot = 0;
	for(int i = 1; i <= n; i ++)
		fir[i] = 0;
	while(m --)
	{
		scanf("%d%d", &f, &t);
		addedge(f, t);
		addedge(t, f);
	}
	scanf("%d", &q);
	while(q --)
	{
		for(int i = 1; i <= n; i ++)
			scanf("%d", &color[i]),
			j11[i] = color[i];
		sort(j11 + 1, j11 + 1 + n);
		int num = unique(j11 + 1, j11 + 1 + n) - j11 - 1;
		if(num != k)
		{
			puts("No");
			continue;
		}
		if(judge())
		{
			puts("Yes");
		}
		else puts("No");
	}
	return 0;
}
