#include <bits/stdc++.h>

using namespace std;

double data[100];
double ans[10009];

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			scanf("%lf", &data[j]);
		sort(data + 1, data + 1 + m);
		ans[i] = 0.0;
		for(int j = 2; j <= m - 1; j ++)
			ans[i] += data[j];
		ans[i] = ans[i] / (double)(m - 2);
	}
	sort(ans + 1, ans + 1 + n);
	for(int i = q; i; i --)
	{
		printf("%.3f", ans[n - i + 1]);
		(i - 1) ? putchar(' ') : puts("");
	}
	return 0;
}
