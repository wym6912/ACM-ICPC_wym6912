#include <bits/stdc++.h>

using namespace std;

int Nine_Num_Digital_Root(int x)
{
	int su = 0;
	while(x != 0)
	{
		su += x % 10;
		x /= 10;
	}
	if(su >= 10) su %= 9;
	return su;
}

int main()
{
	char s[1001];
	while(scanf("%s",s)&&s[0] != '0')
	{
		int sum = 0;
		for(int i = 0;i < strlen(s);i++)
		{
			sum += s[i] - '0';
			if (sum > 9)
				sum = sum % 10 + sum / 10 ; 
		}
		printf("%d\n", sum);
	}
	return 0;
}