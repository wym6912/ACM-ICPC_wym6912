#include <bits/stdc++.h>

using namespace std;

string a;

int main()
{
	ios::sync_with_stdio(false);
	int cm , ci, n;
	while(cin >> n)
	{
		while(n --)
		{
			cin >> a;
			cm = 0;
			ci = 0;
			for(int i = 0;i < a.size();i ++)
			{
				if(a[i] == 'M')cm ++;
				if(a[i] == 'U')ci += 3;
				if(a[i] == 'I')ci ++;
			}
			if(cm == 1 && a[0] == 'M' && (ci == 1 || (ci % 2 == 0 && ci % 3)))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
