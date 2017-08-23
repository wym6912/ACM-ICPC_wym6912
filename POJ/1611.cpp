#include <cstdio>

using namespace std;

int father[30009], ans[30009];

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}

int unionn(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y)return 0;
	if(ans[x] < ans[y])
	{
		father[x] = y;
		ans[y] += ans[x];
	}
	else 
	{
		father[y] = x;
		ans[x] += ans[y];
	}
}

int main()
{
	int n, m, p, x1, x2;
	while(~ scanf("%d%d",&n,&m) && (n || m))
	{
		for(int i = 0;i < n;i ++)father[i] = i, ans[i] = 1;
		while(m --)
		{
			scanf("%d",&p);
			if(!p)continue;
			scanf("%d",&x1);
			x1 = find(x1);
			for(int i = 2;i <= p;i ++)
			{
				scanf("%d",&x2);
				unionn(x1, x2);
			}
		}
		printf("%d\n", ans[father[0]]);
	}
	return 0;
}
