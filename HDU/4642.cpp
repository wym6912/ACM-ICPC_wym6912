#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, T, ans;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				if(i != n && j != m)
					scanf("%*d");
				else scanf("%d",&ans);
		if(ans)printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
