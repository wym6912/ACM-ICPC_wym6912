#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int a[101],b[101];
	while(scanf("%d",&n) != EOF)
	{
		if(n == 0)break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&b[i]);
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		int ansa = 0,ansb = 0;
		for(int i = 1;i <= n;i ++)
			if(a[i] > b[i])ansa += 2;
			else if(a[i] == b[i]) ansa ++,ansb ++;
			else ansb += 2;
		cout << ansa << " vs " << ansb << endl;
	}
	return 0;
 } 