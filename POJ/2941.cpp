#include <cstdio>

using namespace std;

int a[1001][1001];

int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		bool flag = true;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				scanf("%d",&a[i][j]);
		for(int i = 1;flag && i <= n - 1;i ++)
			for(int j = 1;flag && j <= n - 1;j ++)
				if(a[i][j] + a[i + 1][j + 1] != a[i + 1][j] + a[i][j + 1])
					flag = false;
		if(flag)printf("homogeneous\n");
		else printf("not homogeneous\n");
	}
	return 0;
}
