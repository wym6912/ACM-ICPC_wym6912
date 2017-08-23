#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long sum,n;
	while(cin >> n)
	{
		sum = (1 + (n + 1) * n / 2);
		cout << sum << endl;
	}
	return 0;
}
