#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int x, y;
	char str[15];
	bool operator < (const node &b) const
	{
		return x < b.x;
	}
}node;

node data[1009];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s%d%d", data[i].str, &data[i].x, &data[i].y);
	}
	sort(data + 1, data + 1 + n);
	int x, q;
	scanf("%d", &q);
	while(q --)
	{
		scanf("%d", &x);
		printf("%s %d\n", data[x].str, data[x].y);
	}
}
