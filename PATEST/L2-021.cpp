#include <bits/stdc++.h>

using namespace std;

typedef struct info
{
	char name[10];
	int cnt;
	int type;
	bool operator < (const info &b) const
	{
		return type == b.type ? cnt < b.cnt : type > b.type;
	}
}info;

info data[109];
int a[1009];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s%d", data[i].name, &data[i].cnt);
		for(int j = 1; j <= data[i].cnt; j ++)
			scanf("%d", &a[j]);
		sort(a + 1, a + 1 + data[i].cnt);
		data[i].type = unique(a + 1, a + 1 + data[i].cnt) - a;
	}
	sort(data + 1, data + 1 + n);
	for(int i = 1; i <= min(3, n); i ++)
	{
		printf("%s", data[i].name);
		if(i != 3)printf(" ");
		else puts("");
	}
	if(n < 3)
	{
		for(int i = n + 1; i <= 3; i ++)
		{
			printf("-");
			if(i != 3)printf(" ");
			else puts("");
		}
	}
	return 0;
}
