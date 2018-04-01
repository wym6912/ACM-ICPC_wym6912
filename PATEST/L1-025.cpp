#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	string s1, s2, s;
	getline(cin, s);
	int ssize = s.size();
	for(int i = 0; i < ssize; i ++)
		if(s[i] == ' ')
		{
			s1 = s.substr(0, i);
			s2 = s.substr(i + 1, ssize - i - 1);
			break;
		}
	int s1size = s1.size(), s2size = s2.size();
	int a = 0, b = 0;
	bool x1 = false;
	bool aa = true, bb = true;
	for(int i = 0; i < s1size; i ++)
	{
		if(i == 0)
		{
			if(s1[i] == '0')
			{
				aa = false;
				break;
			}
			else a = s1[i] - '0';
		}
		else if(s1[i] >= '0' && s1[i] <= '9')
		{
			a *= 10;
			a += s1[i] - '0';
			if(a > 1000)
			{
				aa = false;
				break;
			}
		}
		else
		{
			aa = false;
			break;
		}
	}
	for(int i = 0; i < s2size; i ++)
	{
		if(i == 0)
		{
			if(s2[i] == '0')
			{
				bb = false;
				break;
			}
			else b = s2[i] - '0';
		}
		else if(s2[i] >= '0' && s2[i] <= '9')
		{
			b *= 10;
			b += s2[i] - '0';
			if(b > 1000)
			{
				bb = false;
				break;
			}
		}
		else
		{
			bb = false;
			break;
		}
	}
	if(b < 1)bb = false;
	if(a < 1)aa = false;
	if(aa)cout << a;
	else cout << "?";
	cout << " + ";
	if(bb)cout << b;
	else cout << "?";
	cout << " = ";
	if(aa && bb)cout << a + b;
	else cout << "?";
	cout << endl;
}
