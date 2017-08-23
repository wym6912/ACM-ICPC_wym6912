#include <bits/stdc++.h>

using namespace std;

int a[300001];
int n;

void f(int x)
{
	printf("%d",a[n - (x / 2)]);
}

int main()
{
	scanf("%d",&n);	
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++)
	{
		if(i != 1)printf(" ");
		f(n - i);
	} 
	printf("\n");
	return 0;
}
