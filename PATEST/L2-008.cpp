#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	getline(cin, str);
	int strsize = str.size();
	int ans = 0, tmpans;
	for(int i = 0; i < strsize; i ++)
	{
		tmpans = 0;
		for(int j = 1; i + j < strsize && i - j >= 0; j ++)
			if(str[i + j] == str[i - j])
				tmpans ++;
			else break;
		tmpans = 2 * tmpans + 1;
		ans = max(ans, tmpans);
	}
	for(int i = 0; i < strsize; i ++)
	{
		tmpans = 0;
		for(int j = 1; i + j - 1 < strsize && i - j >= 0; j ++)
			if(str[i + j - 1] == str[i - j])
				tmpans ++;
			else break;
		tmpans = 2 * tmpans;
		ans = max(ans, tmpans);
	}
	cout << ans << endl;
	return 0;
}
