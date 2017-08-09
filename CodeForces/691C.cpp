#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a,b;
	cin >> a;
	int dotpos;
	int n = a.size();
	bool flag = false;
	int xx = 0;
	for(int i = 0;i < n;i ++)
		if(a[i] == '.')
			flag = true;
	while(a[xx] == '0')a[xx] = '\0',xx ++;
	if(flag)
	{
		int yy = n - 1;
		while(a[yy] == '0' && a[yy] != '.')a[yy] = '\0',yy --;
	}
	for(int i = xx;a[i];i ++)
		b += a[i];
	if(b.empty())b = "0";
	n = b.size();
	dotpos = b.size();
	for(int i = 0;i < n;i ++)
		if(b[i] == '.')
			dotpos = i;
	a.clear();
	int i;
	for(i = 0;b[i] != '.' && i < n;i ++)
		a += b[i];
	for(i ++;b[i] && i < n;i ++)
		a += b[i];
	xx = 0;
	int ss = a.size();
	while(a[xx] == '0')a[xx] = '\0',xx ++,dotpos --;
	int yy = ss;
	while(a[yy] == '0')a[yy] = '\0',yy --,dotpos ++;
	b.clear();
	for(int i = xx;i < yy;i ++)
		b += a[i];
	a.clear();
	a = b;
	if(a.empty())a = "0";
	int ee = a.size();
	cout << a[0];
	if(a[1])
	{
		b.clear();
		for(int i = 1;i < ee;i ++)
			b += a[i];
		xx = b.size() - 1;
		while(b[xx] == '0')b[xx] = '\0',xx --;
		if(!b.empty())
		{
			if(b[0])cout << '.';
			for(int i = 0;i < b.size() && b[i];i ++)
				cout << b[i];
		}
	}
	if(dotpos - 1 != 0)
	{
		cout << "E" << dotpos - 1 << endl;
	}
	return 0;
}
