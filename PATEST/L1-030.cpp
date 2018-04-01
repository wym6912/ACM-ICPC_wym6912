#include <bits/stdc++.h>

using namespace std;

struct node
{
	bool isboy, isused;
	char name[10];
}info[100];

int main()
{
	int n, p;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d %s", &info[i].isboy, &info[i].name);
		info[i].isused = false;
	}
	for(int i = 1;i <= (n >> 1); i ++)
	{
		printf("%s ", info[i].name);
		p = n;
		while(! (info[p].isboy ^ info[i].isboy) || info[p].isused)p --;
		info[p].isused = true;
		puts(info[p].name);
	}
	return 0;
}
