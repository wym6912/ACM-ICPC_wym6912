#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long ans = 0, mul = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		mul *= i;
		ans += mul;
	}
	printf("%lld\n", ans);
	return 0;
}
