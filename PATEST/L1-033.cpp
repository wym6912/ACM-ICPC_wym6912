#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
	int ans = 0;
	bool d[10] = {false};
	if(x < 1000)d[0] = true;
	while(x)
	{
		d[x % 10] = true;
		x /= 10;
	}
	for(int i = 0; i < 10; i ++)
		ans += d[i];
	return ans;
}

int main()
{
	int n, q, ans = 0;
	scanf("%d %d", &n, &q);
	while(f(n) != q)
	{
		n ++, ans ++;
	}
	printf("%d %04d\n", ans, n);
	return 0;
}
