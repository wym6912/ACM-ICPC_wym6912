#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll x[40],y[40];
bool isused[40];

struct dataline
{
	ll sq;
	int n;
	int dis;
}sq1[1 << 18 | 1],sq2[1 << 18 | 1];
ll sq22[1 << 18 | 1];

int ppp1,ppp2;

void calc(bool ss,int end) // ss = 1 is sq1, ss = 0 is sq2
{
	if(ss)
	{
		ppp1 ++;
		sq1[0].n = 0;
		for(int i = 1;i <= end;i ++)
		{
			if(isused[i])sq1[ppp1].sq += x[i],sq1[0].n ++;
		}
		sq1[ppp1].n = sq1[0].n;
	}
	else 
	{
		ppp2 ++;
		sq2[0].n = 0;
		for(int i = 1;i <= end;i ++)
		{
			if(isused[i])sq2[ppp2].sq += y[i],sq2[0].n ++;
		}
		sq2[ppp2].n = sq2[0].n;
	}
}

void dfs(int i,int end,bool ss)
{
	if(i == end + 1)calc(ss,end);
	isused[i] = true;
	dfs(i + 1,end,ss);
	isused[i] = false;
	dfs(i + 1,end,ss);
}

bool cmp(const dataline &a,const dataline &b)
{
	return a.sq > b.sq;
}

int main()
{
	int n,pp1,pp2;
	ll ans;
	while(~ scanf("%d",&n) && n)
	{
		ppp1 = ppp2 = 0;
		for(int i = 1;i <= n / 2;i ++)
			scanf("%I64d",&x[i]);
		for(int i = n / 2 + 1;i <= n;i ++)
			scanf("%I64d",&y[i]);
		dfs(1,n / 2,true);
		dfs(n / 2 + 1,n,false);
		ans = (1 << 30);
		pp1 = pp2 = 1;
		sort(sq2 + 1,sq2 + 1 + ppp2, cmp);
		for(int i = 1;i <= ppp1;i ++)
		{
			
			if(abs(sq1[i].sq + sq2[sq1[i].dis].sq) <= ans)
			{
				pp1 = i;
				pp2 = sq1[i].dis;
				ans = abs(sq1[i].sq + sq2[sq1[i].dis].sq);
			}
		}
		printf("%I64d %d\n",ans,pp1 + pp2);
	}
	return 0;
	
}
