#include <bits/stdc++.h>

using namespace std;

string str, buff;
string ans[100];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> str;
	getline(cin, buff);
	str += buff;
	while(str.size() % n)str += ' ';
	int i = n - 1, strsize = str.size();
	while(strsize)
	{
		ans[i] += str[-- strsize];
		i --;
		if(i == -1)i += n;
	}
	for(int i = 0; i < n; i ++)
		cout << ans[i] << endl;
	return 0;
}
