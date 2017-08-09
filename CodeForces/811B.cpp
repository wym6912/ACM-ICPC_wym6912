#include <bits/stdc++.h>

using namespace std;

int a[10001],tmp[10001],b[10001];

int main()
{
	int n,m,l,r,d;
	scanf("%d %d",&n,&m);
	b[0] = 0;
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= m;i ++)
	{
		memset(tmp,0,sizeof(tmp));
		scanf("%d %d %d",&l,&r,&d);
		int x = 0;
		for(int j = l;j <= r;j ++)
			if(a[j] < a[d])
				x ++;
		if(d == l + x)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
