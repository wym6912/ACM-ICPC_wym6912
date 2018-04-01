#include <bits/stdc++.h>

using namespace std;

string a, b;

bool bhasch[200];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	getline(cin, a);
	getline(cin, b);
	int bsize = b.size(), asize = a.size();
	for(int i = 0; i < bsize; i ++)
		bhasch[b[i]] = true;
	for(int i = 0; i < asize; i ++)
		if(! bhasch[a[i]])
			cout << a[i];
	cout << endl;
	return 0;
}
