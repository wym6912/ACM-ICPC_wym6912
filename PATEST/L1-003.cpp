# include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[1009];
	int data[10], strl;
	scanf("%s", str);
	strl = strlen(str);
	memset(data, 0, sizeof(data));
	for(int i = 0; i < strl; i ++)
		data[str[i] - '0'] ++;
	for(int i = 0; i < 10; i ++)
		if(data[i])
			printf("%d:%d\n", i, data[i]);
	return 0;
}
