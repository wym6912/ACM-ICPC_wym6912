#include <bits/stdc++.h>

using namespace std;

int father[10009];
bool used[10009];

int find(int x){return x == father[x] ? x : father[x] = find(father[x]);}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
	{
		father[x] = y;
		father[0] --;
	}
}

int main()
{
	int n, x, fi, se, ans1 = 0, ans2 = 0;
	scanf("%d", &n);
	for(int i = 1; i <= 10000; i ++)
		father[i] = i;
	while(n --)
	{
		scanf("%d", &x);
		x --;
		scanf("%d", &fi);
		if(! used[fi])used[fi] = true, ans1 ++, father[0] ++;
		for(int i = 1; i <= x; i ++)
		{
			scanf("%d", &se);
			if(! used[se])used[se] = true, ans1 ++, father[0] ++;
			merge(fi, se);
		}
	}
	ans2 = father[0];
	printf("%d %d\n", ans1, ans2);
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d %d", &fi, &se);
		find(fi) == find(se) ? puts("Y") : puts("N");
	}
	return 0;
}
