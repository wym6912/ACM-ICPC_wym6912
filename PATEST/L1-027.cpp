#include <bits/stdc++.h>

using namespace std;

int num[10] = {0};
int arr[10], arrp;

int main()
{
	char data[19];
	scanf("%s", data);
	for(int i = 0; i < strlen(data); i ++)
		num[data[i] - '0'] ++;
	printf("int[] arr = new int[]{");
	for(int i = 9; i >= 0; i --)
		if(num[i])
		{
			arr[arrp] = i;
			arrp ++;
		}
	for(int i = 0; i < arrp; i ++)
	{
		printf("%d", arr[i]);
		if(i != arrp - 1)printf(",");
		else printf("};\n");
	}
	printf("int[] index = new int[]{");
	int idx;
	for(int i = 0; i < strlen(data); i ++)
	{
		for(int j = 0; j < arrp; j ++)
			if(arr[j] == data[i] - '0')
				idx = j;
		printf("%d", idx);
		if(i != strlen(data) - 1)printf(",");
		else printf("};\n");
	}
	return 0;
}
