#include <bits/stdc++.h>

using namespace std;

int father[10009], deg[10009];

bool visited[10009];

int n, cnt = 0;

struct node
{
	int x, y;
	int fa, ma;
	int son[6];
	int my;
}info[1009];

struct anss
{
	double area = 0.0, x = 0.0;
	double ax, ay;
	int minid = 99999, people = 0;
	bool flag = false;
	bool operator < (const anss &b) const 
	{
		return ax > b.ax ||
		 (ax == b.ax && minid < b.minid);
	}
}ans[10009];

int find(int x){return x == father[x] ? x : father[x] = find(father[x]);}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
	{
		if(x > y)father[x] = y;
		else father[y] = x;
	}
}

int main()
{
	int x;
	memset(visited, false, sizeof(visited));
	scanf("%d", &n);
	for(int i = 0; i <= 9999; i ++)
		father[i] = i, deg[i] = 1;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &info[i].my);
		visited[info[i].my] = true;
		scanf("%d%d", &info[i].fa, &info[i].ma);
		if(~ info[i].fa)
			merge(info[i].fa, info[i].my), visited[info[i].fa] = true;
		if(~ info[i].ma)
			merge(info[i].ma, info[i].my), visited[info[i].ma] = true;
		scanf("%d", &info[i].son[0]);
		for(int j = 1; j <= info[i].son[0]; j ++)
		{
			scanf("%d", &info[i].son[j]);
			merge(info[i].son[j], info[i].my);
			visited[info[i].son[j]] = true;
		}
		scanf("%d%d", &info[i].y, &info[i].x);
	}
	for(int i = 1; i <= n; i ++)
	{
		int id = find(info[i].my);
		ans[id].minid = id;
		ans[id].area += (double)info[i].x;
		ans[id].x += (double)info[i].y;
		ans[id].flag = true;
	}
	int cnt = 0;
	for(int i = 0; i <= 9999; i ++)
	{
		if(visited[i])
		{
			ans[find(i)].people ++;
			ans[find(i)].minid = min(ans[find(i)].minid, i);
		}
		if(ans[i].flag)
			cnt ++;
	}
	for(int i = 0; i <= 9999; i ++)
		if(ans[i].flag)
		{
			ans[i].ax = (1.0 * ans[i].area / (double)(ans[i].people));
			ans[i].ay = (1.0 * ans[i].x / (double)(ans[i].people));
		}
	sort(ans, ans + 10000);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i ++)
		printf("%04d %d %.3f %.3f\n", ans[i].minid, ans[i].people, 
		ans[i].ay, ans[i].ax);
	return 0;
}
/*
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
*/

