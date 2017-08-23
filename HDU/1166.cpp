#include <bits/stdc++.h>

#define SIZE_MM 50000

using namespace std;

int bit[SIZE_MM + 1],n;

int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i,int x)
{
	while(i <= n)
	{
		bit[i] += x;
		i += i & -i;
	}
}

void sub(int i,int x)
{
	while(i <= n)
	{
		bit[i] -= x;
		i += i & -i;
	}
}

int main()
{
	int T,tmp,a,b;
	char rq[6];
	scanf("%d",&T);
	for(int ss = 1;ss <= T;ss ++)
	{
		memset(bit,0,sizeof(bit));
		scanf("%d\n",&n);
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&tmp);
			add(i,tmp);
		}
		printf("Case %d:\n",ss);
		scanf("%s",rq);
		while(rq[0] != 'E')
		{
			cin >> a >> b;
			if(rq[0] == 'A')
				add(a,b);
			if(rq[0] == 'S')
				sub(a,b);		
			if(rq[0] == 'Q')
				printf("%d\n",sum(b) - sum(a - 1));
			scanf("%s",rq);
		}
	}
	return 0;
}
