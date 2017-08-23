#include <bits/stdc++.h>

using namespace std;

typedef set <int> si;
si edg[40001];

int main()
{
	int T, n, tmp, from, to, m;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i ++)edg[i].clear();
		for(int i = 1;i <= n - 1;i ++)
		{
			scanf("%d%d%d", &from, &to, &tmp);
			if(tmp)
			{
				edg[from].insert(to);
				edg[to].insert(from);
			}
		}
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d",&tmp);
			if(! tmp)
			{
				scanf("%d", &from);
				if(edg[from].size() % 2)puts("Girls win!");
				else puts("Boys win!");
			}
			else 
			{
				scanf("%d%d%d", &from, &to, &tmp);
				if(tmp)
				{
					edg[from].insert(to);
					edg[to].insert(from);					
				}
				else 
				{
					edg[from].erase(to);
					edg[to].erase(from);
				}
			}
		}
	}
	return 0;
}
