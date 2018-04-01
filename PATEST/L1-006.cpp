#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, l, fi, tmpl, tmpfi, nx;
	scanf("%d", &x);
	l = tmpl = 1;
	tmpfi = fi = x;
	for(int i = 2; i <= sqrt(x); i ++)
	{
		if(x % i == 0)
		{
			int tmp = x / i;
			tmpl = 1;
			tmpfi = i;
			while(true)
			{
				tmpfi ++;
				if(tmp % tmpfi == 0)
				{
					tmp /= tmpfi;
					tmpl ++;
				}
				else break;
			}
			tmpfi = i;
		}
		if(l < tmpl || (l == tmpl && tmpfi < fi))
		{
			l = tmpl;
			fi = tmpfi;
		}
	}
	printf("%d\n", l);
	for(int i = 1; i <= l; i ++)
	{
		if(i != 1)putchar('*');
		printf("%d", fi + i - 1);
	}
	puts("");
	return 0;
}
