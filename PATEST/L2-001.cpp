#include <bits/stdc++.h>

using namespace std;

const int maxn = 509;

int fa[maxn], deg[maxn][maxn], d[maxn], cost[maxn], w[maxn], ans[maxn];
bool vi[maxn];

int main()
{
	int n, m, s, dd, f, t, c;
	scanf("%d%d%d%d", &n, &m, &s, &dd);
	memset(deg, 63, sizeof(deg));
	memset(w, 0, sizeof(w));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i ++)
		scanf("%d", &cost[i]);
	for(int i = 1; i <= m; i ++)
	{
		scanf("%d%d%d", &f, &t, &c);
		f ++, t ++;
		deg[f][t] = deg[t][f] = c;
	}
	/////Process Dijkstra/////
	memset(d, 63, sizeof(d));
	memset(fa, -1, sizeof(fa));
	memset(vi, false, sizeof(vi));
	for(int i = 1; i <= n; i ++)
		if(i == s + 1)
		{
			d[i] = 0;
			ans[i] = cost[i];
			w[i] = 1;
			break;
		}
	for(int i = 1; i <= n; i ++)
	{
		int x, m = deg[0][0];
		for(int j = 1; j <= n; j ++)
			if(! vi[j] && d[j] <= m)
				m = d[x = j];
		vi[x] = true;
		for(int j = 1; j <= n; j ++)
			if(d[j] > d[x] + deg[x][j] && deg[x][j] != deg[0][0])
			{
				d[j] = d[x] + deg[x][j];
				ans[j] = max(ans[j], ans[x] + cost[j]);
				fa[j] = x;
				w[j] = w[x];
			}
			else if(d[j] == d[x] + deg[x][j] && deg[x][j] != deg[0][0])
			{
				w[j] += w[x];
				if(ans[j] < ans[x] + cost[j])
				{
					ans[j] = max(ans[j], ans[x] + cost[j]);
					fa[j] = x;
					d[j] = d[x] + deg[x][j];
				}
			}
	}
	/////Dijkstra end./////
	printf("%d %d\n", w[dd + 1], ans[dd + 1]);
	bool fir = true;
	stack <int> ways;
	dd ++;
	while(~ fa[dd])
	{
		ways.push(dd);
		dd = fa[dd];
	}
	ways.push(dd);
	while(! ways.empty())
	{
		if(ways.size() == 1)printf("%d\n", ways.top() - 1);
		else printf("%d ", ways.top() - 1);
		ways.pop();
	}
	return 0;
}
