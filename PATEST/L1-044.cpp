#include <bits/stdc++.h>

using namespace std;

char data[][10] = {"ChuiZi", "JianDao", "Bu"};

int main()
{
	int n, da = 0;
	char str[100];
	scanf("%d", &n);
	n ++;
	while(scanf("%s", str) && str[0] != 'E')
	{
		da ++;
		switch(str[0])
		{
			case 'C':
				if(da % n == 0)
					puts(str);
				else puts(data[2]);
				break;
			case 'J':
				if(da % n == 0)
					puts(str);
				else puts(data[0]);
				break;
			case 'B':
				if(da % n == 0)
					puts(str);
				else puts(data[1]);
				break;
		}
	}
	return 0;
}
