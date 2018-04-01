#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a = 0, b = 0, strsize;
	bool hasx = false, hasd = false;
	string str;
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	strsize = str.size();
	for(int i = 0; i < strsize; i ++)
	{
		if(str[i] == '-')hasx = true, b --;
		if(i == strsize - 1 && str[i] % 2 == 0)hasd = true;
		if(str[i] == '2')a ++;
		b ++;
	}
	double ans = 100.0 * (double)((double)a / (double)b);
	if(hasx)ans *= 1.5;
	if(hasd)ans *= 2.0;
	cout << fixed << setprecision(2) << ans << "%" << endl;
	return 0;
}
