#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ax, ay, a1, a2, n, a, b, c, d;
	scanf("%d %d", &ax, &ay);
	ax ++, ay ++;
	a1 = ax, a2 = ay;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a + c == b)ax --;
		if(a + c == d)ay --;
		if(a + c == b && a + c == d)ax ++, ay ++;
		if(! ax)return printf("%c\n%d\n", 'A', a2 - ay), 0;
		if(! ay)return printf("%c\n%d\n", 'B', a1 - ax), 0;
	}
}
