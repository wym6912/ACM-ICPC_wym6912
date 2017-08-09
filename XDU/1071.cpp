#include <bits/stdc++.h>

using namespace std;

int f(int a)
{
	return a * (a + 1) / 2;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n --)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",f(a) * f(b));
	}
	return 0;
}
