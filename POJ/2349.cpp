#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct edge
{
	int from, to;
	double cost;
}edg[500005];

int father[1001];

inline double sqr(double x)
{
	return x * x;
}

inline double dis(double ax, double ay, double bx,double by)
{
	return sqrt(sqr(ax - bx) + sqr(ay - by));
}

double x[1001],y[1001];
int M,p,s;

bool cmp(const edge &a, const edge &b)
{
	return a.cost < b.cost;
}

int find(int x)
{
	return (father[x] == x) ? x : (father[x] = find(father[x]));
}

double kruscal()
{
	sort(edg + 1, edg + M, cmp);
	int cnt = p;
	double ans = 0.0;
	for(int i = 1;i <= p;i ++)father[i] = i;
	for(int i = 1;i < M;i ++)
	{
		int t1 = find(edg[i].from);
		int t2 = find(edg[i].to);
		if(t1 != t2)
		{
			father[t1] = t2;
			ans = edg[i].cost;
			cnt --;
			if(cnt == s) break;
		}
	}
	return ans;
}

int main()
{
	int T;
	while(~ scanf("%d",&T))
	{
		while(T --)
		{
			M = 1;
			scanf("%d%d",&s,&p);
			for(int i = 1;i <= p;i ++)
				scanf("%lf%lf",&x[i],&y[i]);
			for(int i = 1;i <= p;i ++)
				for(int j = i + 1;j <= p;j ++)
				{
					edg[M].from = i;
					edg[M].to = j;
					edg[M].cost = dis(x[i],y[i],x[j],y[j]);
					M ++;
				}
			printf("%.2lf\n",kruscal());
		}
	}
	return 0;
}
