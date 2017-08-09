#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main()
{
	int a2,b,c;
	scanf("%d %d %d",&b,&a2,&c);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	printf("%d\n",lower_bound(a + 1,a + n + 1,c) - upper_bound(a + 1,a + n + 1,a2));
	return 0; 
}
