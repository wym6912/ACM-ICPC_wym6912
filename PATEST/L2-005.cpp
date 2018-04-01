#include <bits/stdc++.h>

using namespace std;

int data[59][10005];

int main()
{
	int n, m, x, y, f, t, same, cnt;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &data[i][0]);
		for(int j = 1; j <= data[i][0]; j ++)
			scanf("%d", &data[i][j]);
	}
	for(int i = 1; i <= n; i ++)
	{
		sort(data[i] + 1, data[i] + 1 + data[i][0]);
		data[i][0] = unique(data[i] + 1, data[i] + 1 + data[i][0]) - data[i] - 1;
	}
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d%d", &x, &y);
		f = 1, t = 1;
		same = 0, cnt = 0;
		while(f <= data[x][0] && t <= data[y][0])
		{
			while(data[x][f] != data[y][t] && f <= data[x][0] && t <= data[y][0])
			{
				++ cnt;
				if(data[x][f] != data[y][t])
					data[x][f] < data[y][t] ? ++ f : ++ t;
			}
			while(data[x][f] == data[y][t] && f <= data[x][0] && t <= data[y][0])
				++ cnt, ++ same, ++ f, ++ t;
		}
		while(f <= data[x][0])
			++ f, ++ cnt;
		while(t <= data[y][0])
			++ t, ++ cnt;
		printf("%.2f%\n", (float)((float)(same) / (float)(cnt) * 100.0));
	}
	return 0;
}
