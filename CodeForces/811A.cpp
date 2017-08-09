#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	int c1 = 0,c2 = 0;
	scanf("%d %d",&a,&b);
	for(int i = 1;a >= i;i += 2)
		a -= i,c1 ++;
	for(int i = 2;b >= i;i += 2)
		b -= i,c2 ++;
	if(c1 > c2)printf("Valera\n");
	else printf("Vladik\n");
	return 0; 
}
