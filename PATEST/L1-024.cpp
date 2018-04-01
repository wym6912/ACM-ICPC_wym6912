#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", (x + 2) % 7 ? (x + 2) % 7 : 7);
	return 0; 
}
