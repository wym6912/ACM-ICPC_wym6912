#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#endif

using namespace std;

const int MAXN = 5010;
const int MAXM = 50010;

struct Edge 
{
	int to, next;
}edge[MAXM];

struct tmp
{
	int from, to;
}ed[MAXM];

int head[MAXN], tot;

void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

int linker[MAXN];
bool used[MAXN];
int uN,uV;

bool dfs(int u)
{
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if(! used[v])
		{
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for(int u = 1;u <= uN;u ++)
	{
		memset(used, false, sizeof(used));
		if(dfs(u))
			res ++;
	}
	return res;
}

bool xx[501][501];

int main()
{
	int ca = 0, uM;
	while(~ scanf("%d%d%d",&uN,&uV,&uM) && (uN || uV || uM))
	{
		memset(xx, false, sizeof(xx));
		ca ++;
		init();
		int f, t, aa = 0;
		while(uM --)
		{
			aa ++;
			scanf("%d%d",&ed[aa].from,&ed[aa].to);
		}
		for(int i = 1;i <= aa;i ++)
			xx[ed[i].from][ed[i].to] = true;
		for(int i = 1;i <= uN;i ++)
			for(int j = 1;j <= uV;j ++)
				if(! xx[i][j])
					addedge(i,j + uN);
		printf("Case %d: %d\n", ca, uN + uV - hungary());
	}
	return 0;
}
