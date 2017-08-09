#include <bits/stdc++.h>

const int ten[] = {1,10,100,1000};
const int maxl = 1000;

struct BigNumber
{
	int d[maxl];
	BigNumber (string s)
	{
		int len = s.size();
		d[0] = (len - 1) / 4 + 1;
		int i,j,k;
		for(i = 1;i < maxl;++ i)d[i] = 0;
		for(i = len - 1;i >= 0;-- i)
		{
			j = (len - i - 1) / 4 + 1;
			k = (len - i - 1) % 4;
			d[j] += ten[k] * (s[i] - '0');
		}
		while(d[0] > 1 && d[d[0]] == 0) -- d[0];
	}
	BigNumber()
	{
		*this = BigNumber(string("0"));
	}
	string toString()
	{
		string s("");
		int i,j,temp;
		for(i = 3;i >= 1;-- i)if(d[d[0]] >= ten[i])break;
		temp = d[d[0]];
		for(j = i;j >= 0;-- j)
		{
			s += (char)(temp / ten[j] + '0');
			temp %= ten[j];
		}
		for(i = d[0] - 1;i > 0;-- i)
		{
			temp = d[i];
			for(j = 3;j >= 0;-- j)
			{
				s += (char)(temp / ten[j] + '0');
				temp %= ten[j];
			}
		}
		return s;
	}
	void out()
	{
		for(int i = d[0];i >= 1;i --)
			printf("%d",d[i]);
		printf("\n");
		return ;
	}
}zero("0"),d,temp,mid1[15];

bool operator < (const BigNumber &a,const BigNumber &b)
{
	if(a.d[0] != b.d[0])return a.d[0] < b.d[0];
	for(int i = a.d[0];i > 0;i --)
		if(a.d[i] != b.d[i])
			return a.d[i] < b.d[i];
	return false;
}

BigNumber operator + (const BigNumber &a,const BigNumber &b)
{
	BigNumber c;
	c.d[0] = max(a.d[0],b.d[0]);
	int i,x = 0;
	for(i = 1;i <= c.d[0];i ++)
	{
		x = a.d[i] + b.d[i] + x;
		c.d[i] = x % 10000;
		x /= 10000;
	}
	while(x != 0)
	{
		c.d[++ c.d[0]] = x % 10000;
		x /= 10000;
	}
	return c;
}

BigNumber operator * (const BigNumber &a,const int &k)
{
	BigNumber c;
	c.d[0] = a.d[0];
	int i, x = 0;
	for(i = 1;i <= a.d[0];i ++)
	{
		x = a.d[i] * k + x;
		c.d[i] = x % 10000;
		x /= 10000;
	}
	while(x > 0)
	{
		c.d[++ c.d[0]] = x % 10000;
		x /= 10000;
	}
	while(c.d[0] > 1 && c.d[c.d[0]] == 0) -- c.d[0];
	reutrn c;
}

bool operator == (const BigNumber &a,const BigNumber &b)
{
	int i;
	if(a.d[0] != b.d[0])return false;
	for(i = 1;i <= a.d[0]; ++ i)
		if(a.d[i] != b.d[i])
			return false;
	return true;
}

struct data
{
	int x;
	bool s;
}dd[5001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string a;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		cin >> dd[i].x;
		if(a[0] == 'w')
			dd[i].s = false;
		else dd[i].s = true;
	}
	for(int i = 1;i <= n;i ++)
	{
		
	}
}
