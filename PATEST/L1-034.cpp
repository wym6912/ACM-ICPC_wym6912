#include <bits/stdc++.h>

using namespace std;

int data[1009];

int main()
{
	int n, x, d, maxans = 0;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d", &x);
		for(int i = 1; i <= x; i ++)
			scanf("%d", &d), data[d] ++;
	}
	for(int i = 1000; i >= 1; i --)
		maxans = max(maxans, data[i]);
	for(int i = 1000; i >= 1; i --)
		if(maxans == data[i])
			return printf("%d %d\n", i, maxans), 0;
}
