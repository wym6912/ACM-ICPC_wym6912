#include <bits/stdc++.h>

using namespace std;

int father[109];

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y)father[x] = y;
}

typedef struct
{
	int to, next;
}node;

node edge[101 * 101];
int fir[101];
int id;

void addedge(int f, int t)
{
	++ id;
	edge[id].to = t;
	edge[id].next = fir[f];
	fir[f] = id;
}

int main()
{
	int n, m, q;
	int f, t, x;
	scanf("%d%d%d", &n, &m, &q);
	id = 0;
	for(int i = 1; i <= n; i ++)
		father[i] = i, fir[i] = 0;
	while(m --)
	{
		scanf("%d%d%d", &f, &t, &x);
		if(x == 1)
		{
			merge(f, t);
		}
		else if(x == -1)
		{
			addedge(f, t);
			addedge(t, f);
		}
	}
	while(q --)
	{
		scanf("%d%d", &f, &t);
		bool isenemy = false, isfriend = false;
		for(int i = fir[f]; i; i = edge[i].next)
			if(edge[i].to == t)
				isenemy = true;
		if(find(f) == find(t))
			isfriend = true;
		if(isfriend && ! isenemy)
			puts("No problem");
		if(! isfriend && ! isenemy)
			puts("OK");
		if(isfriend && isenemy)
			puts("OK but...");
		if(! isfriend && isenemy)
			puts("No way");
	}
	return 0;
}
