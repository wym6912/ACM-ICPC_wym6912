#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int ss[128];

int main()
{
	ios::sync_with_stdio(false);
	while(cin >> a >> b)
	{
	        bool flag = false;
		c.clear();
		//c.resize(100009);
		memset(ss, 0, sizeof(ss));
		int bs = b.size();
		for(int i = 0;i < bs;i ++)
			ss[b[i]] = 1;
		int as = a.size();
		for(int i = 0;i < as;i ++)
			if(! ss[a[i]]){cout << a[i] ;flag = true;}
		if(! flag)
			cout << "EMPTY";
		cout << endl;
	}
	return 0;
}
