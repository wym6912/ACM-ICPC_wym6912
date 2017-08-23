#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
	int from, to, cost;
}edg[100001]; 

int father[1000];

int n, m;

const int inf = 1 << 20;

int find(int x){return (father[x] == x) ? x : father[x] = find(father[x]);}

bool cmp(const edge &a, const edge &b)
{
	return a.cost < b.cost;
}

int krusual(int fir)
{
	int cnt = n,ans1 = 0,ans2 = 0;
	for(int i = 1;i <= n;i ++)father[i] = i;
	for(int i = fir;i <= m;i ++)
	{
		int t1 = find(edg[i].from);
		int t2 = find(edg[i].to);
		if(t1 != t2)
		{
			cnt --;
			father[t1] = t2;
			if(cnt == 1){ans2 = edg[i].cost;break;}
			if(cnt == n - 1){ans1 = edg[i].cost;}
		}
	}
	//printf("%d\n",ans2 - ans1);
	if((ans2 && ans1) || (ans2 && ans1 && ans2 == ans1))return ans2 - ans1;
	else return inf;
}

int main()
{
	//freopen("3522.txt","w",stdout);
	while(~ scanf("%d%d",&n,&m) && (n || m))
	{
		for(int i = 1;i <= m;i ++)
			scanf("%d%d%d",&edg[i].from,&edg[i].to,&edg[i].cost);
		sort(edg + 1, edg + m + 1, cmp);
		int tmpcost = 0,ans = inf;
		if(n - m >= 2)
		{
			printf("-1\n");
			continue;
		}
		if(m == 1)
		{
			printf("0\n");
			continue;
		}
		for(int i = 1;i <= m;i ++)
			if(tmpcost < edg[i].cost)
			{
				ans = min(ans,krusual(i));
				tmpcost = edg[i].cost;
			}
		if(ans == inf)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
