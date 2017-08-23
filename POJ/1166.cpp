#include <cstdio>
#include <cstring>
#define clocks c 

using namespace std;

int clocks[10],spanning[10],ans = 1 << 10;

void plus(int i)
{
	clocks[i] ++;
	clocks[i] %= 4;
}

void change(int i)
{
	switch(i)
	{
		case 1:plus(1),plus(2),plus(4),plus(5);break;
		case 2:plus(1),plus(2),plus(3);break;
		case 3:plus(2),plus(3),plus(5),plus(6);break;
		case 4:plus(1),plus(4),plus(7);break;
		case 5:plus(2),plus(4),plus(5),plus(6),plus(8);break;
		case 6:plus(3),plus(6),plus(9);break;
		case 7:plus(4),plus(5),plus(7),plus(8);break;
		case 8:plus(7),plus(8),plus(9);break;
		case 9:plus(5),plus(6),plus(8),plus(9);break;
	}
}

bool check()
{
	for(int i = 1;i <= 9;i ++)
		if(clocks[i])
			return false;
	return true;
}

void print()
{
	static bool x = false;
	if(!x)x = true;
	else return;
	for(int i = 1;i <= 9;i ++)
	{
		if(spanning[i])
			for(int j = 1;j <= spanning[i] % 4;j ++)
				printf("%d ",i);
	}
	printf("\n");
}

void DFS(int i)
{
	if(check()){print();return ;}
	else if(i == 10)return ;
	else 
	{
		for(int j = 1;j <= (4 - spanning[i]) % 4;j ++)
			change(i);
		spanning[i] = 0;
		DFS(i + 1);
		while(spanning[i] <= 3)
		{
			DFS(i + 1);
			change(i);
			spanning[i] ++;
		}
		return ;
	}
}

int main()
{
	memset(spanning,0,sizeof(spanning));
	for(int i = 1;i <= 9;i ++)
		scanf("%d",&clocks[i]);
	DFS(1);
	return 0;
}
