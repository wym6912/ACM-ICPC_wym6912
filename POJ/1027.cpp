#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char map[20][11];

int main()
{
	int n;
	while(~ scanf("%d\n",&n))
	{
		for(int oo = 1;oo <= n;oo ++)
		{
			for(int i = 1;i <= 10;i ++)
				gets(map[i]);
			for(int i = 1;i <= 10;i ++)
				for(int j = 1;j <= 15;j ++)
					bfs(i,j);
		}
	}
}
