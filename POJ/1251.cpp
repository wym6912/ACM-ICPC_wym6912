#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
	int from,to,cost;
}edg[3001];

int father[301];

bool comp(const edge &a,const edge &b)
{
	if(! (a.cost == b.cost))return a.cost < b.cost;
	return a.from < b.from;
}

int find(int x){return father[x] == x ? father[x] : father[x] = find(father[x]);}

bool unionn(int x,int y)
{
	int f1 = find(father[x]),
		f2 = find(father[y]);
	if(f1 == f2)
		return false;
	else father[f1] = f2;
	return true;
}

int main()
{
	int n,m,ed,ans,ss;
	while(~ scanf("%d",&n) && (n))
	{
		scanf("%d",&m);
		ed = 0;
		ans = 0;
		ss = 0;
		for(int i = 1;i <= n;i ++)father[i] = i;
		for(int i = 1;i <= m;i ++)
			scanf("%d %d %d",&edg[i].from,&edg[i].to,&edg[i].cost);
		sort(edg + 1,edg + 1 + m,comp);
		for(int i = 1;i <= m,ss < n - 1;i ++)
			if(unionn(edg[i].from,edg[i].to))
			{
				ans += edg[i].cost;
				ss ++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
