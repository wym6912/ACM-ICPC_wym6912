#include <bits/stdc++.h>

using namespace std;

const int maxn = 109;

struct matrix
{
	int n, m;
	long long a[maxn][maxn];
	void clear()
	{
		n = 0;
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &b) const
	{
		matrix tmp;
		tmp.clear();
		tmp.n = n;
		tmp.m = b.m;
		for(int k = 0; k < m; ++ k)
			for(int i = 0; i < n; ++ i)
				for(int j = 0; j < b.m; ++ j)
					tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j]);
		return tmp;
	}
};

int main()
{
	matrix a, b;
	scanf("%d%d", &a.n, &a.m);
	for(int i = 0; i < a.n; ++ i)
		for(int j = 0; j < a.m; ++ j)
			scanf("%d", &a.a[i][j]);
	scanf("%d%d", &b.n, &b.m);
	for(int i = 0; i < b.n; ++ i)
		for(int j = 0; j < b.m; ++ j)
			scanf("%d", &b.a[i][j]);
	if(a.m != b.n)
		return printf("Error: %d != %d\n", a.m, b.n), 0;
	else 
	{
		a = a * b;
		printf("%d %d\n", a.n, a.m);
		for(int i = 0; i < a.n; i ++, puts(""))
		{
			for(int j = 0; j < a.m; j ++)
				if(j != 0)
					printf(" %d", a.a[i][j]);
				else printf("%d", a.a[i][j]);
		}
	}
}
