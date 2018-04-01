#include <bits/stdc++.h>

using namespace std;

int data[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

string str[101];

bool check(string str)
{
	int ans = 0;
	for(int i = 0; i < 17; i ++)
		if(str[i] >= '0' && str[i] <= '9')
			ans += data[i] * (str[i] - '0');
		else return false;
	ans %= 11;
	if(str[17] == 'X')
		return ans == 2;
	return (ans + str[17] - '0') % 11 == 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> str[i];
		if(check(str[i]))ans ++;
	}
	if(ans == n)
	{
		cout << "All passed" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i ++)
		if(! check(str[i]))
			cout << str[i] << endl;
	return 0;
}
