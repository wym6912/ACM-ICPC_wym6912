/*
ID: wym69121
PROG: beads
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

char x[400];

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n,ans = 0,tmp,k;
	scanf("%d\n%s",&n,x);
	for(int i = 0;i < n;i ++)
		x[i + n] = x[i];
	for(int i = 0;i < 2 * n;i ++)
	{
		tmp = 0;
		if(x[i] == 'b')
		{
			k = 0;
			for(int j = i;(x[j] == 'b' || x[j] == 'w') && j < 2 * n && k < n;j ++,k ++)tmp ++;
			for(int j = i - 1;(x[j] == 'r' || x[j] == 'w') && j >= 0 && k < n;j --,k ++)tmp ++;
			ans = max(tmp,ans); 
		}
		if(x[i] == 'r')
		{
			k = 0;
			for(int j = i;(x[j] == 'r' || x[j] == 'w') && j < 2 * n && k < n;j ++,k ++)tmp ++;
			for(int j = i - 1;(x[j] == 'b' || x[j] == 'w') && j >= 0 && k < n;j --,k ++)tmp ++;
			ans = max(tmp,ans);
		}
	}
	if(ans != 0)
		printf("%d\n",ans);
	else printf("%d\n",n);
	return 0;
}

