#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ThreeNPlusOne(int x)
{
	if(x==1)return 1;
	for(int i=1;;)
	{
		if(x%2)x=3*x+1;
		else x/=2;
		i++;
		if(x==1)return i;
	}
}

void swap(int *a,int *b)
{
	int p=*a;
	*a=*b;
	*b=p;
} 

int main()
{
	int start,end;
	while(scanf("%d %d",&start,&end)==2)
	{
		int operators_=0;
		bool flag = false; 
		if(start > end)
		{
			swap(start,end);
			flag = true;
		}
		for(int i=start;i<=end;i++)
			operators_=max(operators_,ThreeNPlusOne(i));
		if(!flag)
			printf("%d %d %d\n",start,end,operators_); 
		else printf("%d %d %d\n",end,start,operators_);
	}
	return 0;
} 