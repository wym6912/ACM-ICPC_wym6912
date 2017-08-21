#include <bits/stdc++.h>

using namespace std;

char a[52][52];

struct ax
{
	int x,y;
}aaa[3000];

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

void outmap()
{
	for(int i = 1;i <= 4;i ++)
		puts(a[i]);
	cout << endl;
}

int BFS(ax ac,int end)
{
	if(a[ac.x][ac.y] == '0')return 0;
	queue <ax> qqq;
	bool flag = true;
	qqq.push(ac);
	int sq = 1;
	a[ac.x][ac.y] = '0';
	while(!qqq.empty())
	{
		int bx = qqq.front().x;
		int by = qqq.front().y;
		for(int i = 0;i <= 3;i ++)
				if(a[bx + dx[i]][by + dy[i]] == '*')
				{
					ac.x = bx + dx[i];
					ac.y = by + dy[i];
					qqq.push(ac);
					sq ++;
					a[bx + dx[i]][by + dy[i]] = '0';
				}
				else if(a[bx + dx[i]][by + dy[i]] == '#')
					continue;
				else if(a[bx + dx[i]][by + dy[i]] == '\0' || a[bx + dx[i]][by + dy[i]] == '\n')
					flag = false;
		
		qqq.pop();
	}
	if(flag)return sq;
	else return 0;
}

int search(int k,int s)
{
	int sq = 0;
	for(int i = 1;i < k;i ++)
	{
		sq += BFS(aaa[i],s);
	}
	return sq;
}

int main()
{
	int i = 1,k = 1;
	memset(a,'\0',sizeof(a));
	while(gets(a[i]) != NULL)
	{
		for(int j = 0;j <= strlen(a[i - 1]);j ++)
			if(a[i][j] == '*')
			{
				aaa[k].x = i;
				aaa[k].y = j;
				k ++;
			}
		i ++;
	}
	printf("%d\n",search(k,i));
	return 0;

