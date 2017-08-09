#include <bits/stdc++.h>

using namespace std;

int father[10001],ppp[10001];

int find(int x)
{
	if(x != father[x])
		father[x] = find(father[x]);
	return father[x];
}

void Union(int x,int y)
{
	int xx = find(x);
	int yy = find(y);
	if( xx != yy )
	father[xx] = yy;
}

void reset(int a[],int x)
{
	for(int i = 0;i <= x;i ++)
		a[i] = i;
}

void TestFunc(int a[])
{
	for(int i = 0;i <= 5;i ++)
		printf("%d ",a[i]);
	cout<<endl;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt = 1;tt <= T;tt ++)
	{
		memset(ppp,0,sizeof(ppp));
		int x0,y0;
		scanf("%d %d",&x0,&y0);
		reset(father,x0);
		int x,y;
		for(int i = 1;i <= y0;i ++)
		{
			scanf("%d %d",&x,&y);
			Union(x,y);
		}
		//cout<<father[0]<<endl;
		for(int i = 1;i <= x0;i ++)
			if(father[i] == i)
				father[0]++;
		//TestFunc(father);
		printf("%d\n",father[0]);
	}
	return 0;
} 