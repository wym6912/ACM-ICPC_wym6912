# include <bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	char ch;
	scanf("%d %c", &x, &ch);
	int tmp = 1, cnt = 1, ncnt = 1;
	while(tmp <= x)
	{
		cnt += 2;
		tmp += cnt * 2;
	}
	tmp -= cnt * 2;
	cnt -= 2;
	ncnt = 0;
	for(int i = cnt; i >= 1; i -= 2)
	{
		for(int j = 1; j <= ncnt;j ++)
			putchar(' ');
		for(int j = 1; j <= i; j ++)
			putchar(ch);
		ncnt ++;
		puts("");
	}
	ncnt --;
	ncnt --;
	for(int i = 3; i <= cnt; i += 2)
	{
		for(int j = 1; j <= ncnt;j ++)
			putchar(' ');
		for(int j = 1; j <= i; j ++)
			putchar(ch);
		ncnt --;
		puts("");
	}
	printf("%d\n", x - tmp);
	return 0;
}
