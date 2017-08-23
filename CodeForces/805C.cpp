#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if(n & 1)
		printf("%d\n",n / 2);
	else 
		printf("%d\n",(n - 2) / 2);
	return 0;
}
