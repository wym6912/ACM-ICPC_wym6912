#include <bits/stdc++.h>

using namespace std;

int data[100009];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &data[i]);
	sort(data + 1, data + 1 + n);
	if(n & 1)
	{
		printf("Outgoing #: %d\n", (n >> 1) + 1);
		printf("Introverted #: %d\n", (n >> 1));
		for(int i = 1; i <= (n >> 1); i ++)
			ans += data[n - i + 1] - data[i];
		ans += data[(n >> 1) + 1];
		printf("Diff = %d\n", ans);
	}
	else 
	{
		printf("Outgoing #: %d\n", (n >> 1));
		printf("Introverted #: %d\n", (n >> 1));
		for(int i = 1; i <= (n >> 1); i ++)
			ans += data[n - i + 1] - data[i];
		printf("Diff = %d\n", ans);
		
	}
	return 0;
}
