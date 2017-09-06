#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
const int MAXM = 50010;

struct Edge 
{
	int to, next;
}edge[MAXM];

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
	for(int u = 0;u < uN;u ++)
	{
		memset(used, false, sizeof(used));
		if(dfs(u))
			res ++;
	}
	return res;
}

int main()
{
	while(~ scanf("%d%d",&uN,&uV))
	{
		//uV += uN;
		init();
		int xx, f, t;
		scanf("%d",&xx);
		while(xx --)
		{
			scanf("%d%d",&f,&t);
			addedge(f, uN + t - 1);
		}
		printf("%d\n", hungary());
	}
}

/**************************************************************
    Problem: 1048
    User: 16020120071
    Language: C++
    Result: ÕýÈ· 
    Time:116 ms
    Memory:2136 kb
****************************************************************/
