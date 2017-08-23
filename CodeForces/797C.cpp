#include <bits/stdc++.h>

using namespace std;

stack <char> s;
int num[30];

void outs()
{
	if(s.empty())return ;
	char tmp = s.top();
	cout << tmp ;
	s.pop();
	outs();
	s.push(tmp);
}

int main()
{
	string a,b,c;
	int now;
	cin >> a;
	for(int i = 0;i < a.size();i ++)
		num[a[i] - 'a' + 1] ++;
	while(! a.empty() || ! s.empty())
	{
		for(now = 1;now <= 26;now ++)
			if(num[now])
				break;
		now = min(now,26);
		int x = a.find(now + 'a' - 1, 0);
		if(x == a.size())x = a.size() - 1;
		for(int i = 0;i <= x;i ++)
		{
			s.push(a[i]);
		}
		a.erase(0,x + 1);
		while(! s.empty() && ! a.empty() && num[now])
		{
			/*if(! num[now])break;
			c += min(s.top(),a[0]);
			num[min(s.top(),a[0]) - 'a' + 1] --;
			if(s.top() <= a[0])s.pop();
			else a.erase(0,1);
			cout << "a = ";
			cout << a << endl;
			cout << "s = ";
			outs();
			cout << endl;
			cout << "c = " << c << endl;
			cout << "num[now] = " << num[now] << ", now = " << now << endl;*/
			int aa = 0;
			while(s.top() == a[aa] && aa < a.size())aa ++;
			if(s.top() < a[aa])
			{
				c += s.top();
				num[s.top() - 'a' + 1] --;
				s.pop();
			}
			else if(s.top() > a[aa] && a[aa])
			{
				c += a[aa];
				num[a[aa] - 'a' + 1] --;
				a.erase(aa,1);
			} 
			else 
			{
				c += s.top();
				num[s.top() - 'a' + 1] --;
				s.pop();
				c += a[0];
				num[a[0] - 'a' + 1] --;
				a.erase(0,1);
			}
			for(int i = 0;i < aa && !a.empty();i ++)
				c += a[0],a.erase(0,1);
			x = a.find(now + 'a' - 1, 0);
			if(x == a.size())x = a.size() - 1;
			for(int i = 0;i <= x;i ++)
			{	
				s.push(a[i]);
			}
			a.erase(0,x + 1);
		}
		if(a.empty())
		{
			while(! s.empty())
			{
				c += s.top();
				s.pop();
			}
		}
	}
	cout << c << endl;
	return 0;
}
