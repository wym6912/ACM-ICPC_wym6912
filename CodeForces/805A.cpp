#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a != b)
		printf("2\n");
	else
		if(a % 2)
			printf("%d\n",a);
		else printf("2\n");
	return 0;
} 
