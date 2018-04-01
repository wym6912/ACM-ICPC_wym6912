#include <bits/stdc++.h>

using namespace std;

char data[100010];
char ans[100100];

int main()
{
	int x, datalen;
	char ch;
	scanf("%d %c\n", &x, &ch);
	gets(data);
	datalen = strlen(data);
	if(x >= datalen)
	{
		int i;
		for(i = 0; i < x - datalen; i ++)
			ans[i] = ch;
		strcpy(ans + i, data);
	}
	else 
	{
		strcpy(ans, data + datalen - x);
	}
	puts(ans);
	return 0;
}
