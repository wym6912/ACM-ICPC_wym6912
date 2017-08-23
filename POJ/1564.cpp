#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int lib[1001],sum,place,n;
bool flag,flag2; 

int bp[1001],mm,data[1001],tmp[1001];

void print()
{
	flag = true;
	flag2 = false;
	for(int i = 1;i <= mm;i ++)
		if(tmp[i])
		{
			for(int j = 1;j <= tmp[i];j ++)
			{
				if(! flag2)
					flag2 = true;
				else printf("+");
				printf("%d",data[i]);
			}
		}
	printf("\n");
}

void print2()
{
	for(int i = 1;i <= mm;i ++)
		cout << data[i] << ' ' << tmp[i] << endl;
}

void dfs(int i,int sum2)
{
	//cout << "print " << endl;
	//print2();
	//cout << i << ' ' << sum2 << ' ' << bp[lib[i]] << endl;
	if(sum2 > sum)return ;
	if(sum2 == sum){print();return ;}
	if(i == mm + 1)return ;
	for(int j = bp[lib[i]];j >= 1;j --)
	{
		tmp[i] += j;
		sum2 += data[i] * j;
		dfs(i + 1,sum2);
	//	cout << "sum2 = " << sum2 << endl;
		sum2 -= data[i] * j;
		tmp[i] -= j;	
	}
	dfs(i + 1,sum2);
}

int main()
{
	//freopen("Gout.txt","w",stdout);
	while(~ scanf("%d %d",&sum,&n) && (n || sum))
	{
		flag = false;
		mm = 0;
		memset(bp,0,sizeof(bp));
		memset(tmp,false,sizeof(tmp));
		memset(data,0,sizeof(data)); 
		for(int i = 1;i <= n;i ++)
			scanf("%d",&lib[i]);
		for(int i = 1;i <= n;i ++)
		{
			if(!bp[lib[i]])
				data[++ mm] = lib[i];
			bp[lib[i]] ++;
		}
		printf("Sums of %d:\n",sum);
		dfs(1,0);
		if(! flag)printf("NONE\n");
	}
	return 0;
}
