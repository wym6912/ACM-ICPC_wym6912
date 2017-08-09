#include <bits/stdc++.h>

using namespace std;

int father[30001];

struct edges
{
	int from,to,cost;
}edge[100001];

int edg2;

void reset(int n,int m)
{
	edg2 = n;
	for(int i = 1;i <= n;i ++)
		father[i] = i;
	for(int i = 1;i <= m;i ++)
	{
		edge[i].cost = 0;
		edge[i].from = 0;
		edge[i].to = 0;
	}
}

int find(int x)
{
	return father[x] == x ? x : father[x] = find(father[x]);
}

bool unionn(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)return false;
	else 
	{
		edg2 --;
		father[fx] = fy;
		return true;
	}	
}

bool comp(const edges & a,const edges &b)
{
	return a.cost > b.cost;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a,b,c,boys,girls,costs,e;
	long long ans;
	while(n -- )
	{
		ans = 0;
		scanf("%d %d %d %d",&boys,&girls,&costs,&e);
		ans += (long long)(costs * (boys + girls));
		reset(boys + girls,e);
		for(int i = 1;i <= e;i ++)
		{
			scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost);
			edge[i].to += boys;
			edge[i].from ++;
			edge[i].to ++;
		}
		sort(edge + 1,edge + e + 1,comp);
		for(int i = 1;i <= e;i ++)
		{
			if((find(edge[i].from) != find(edge[i].to)) && edg2 != 1)
			{
				unionn(edge[i].from,edge[i].to);
				ans -= edge[i].cost;
			}
		}
		printf("%d\n",ans);
	}
}
