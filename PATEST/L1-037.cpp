#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d/", a);
	if(b < 0)printf("(%d)=", b);
	else printf("%d=", b);
	if(b == 0)puts("Error");
	else printf("%.2f\n", (float)a / (float)b);
	return 0;
}
