#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char a[101],b[101];
	scanf("%s %s",&a,&b);
	int sum = 0;
	for(int i = 0;i < strlen(a);i ++)
		for(int j = 0;j < strlen(b);j ++)
			sum+=(a[i]-'0')*(b[j]-'0');
	printf("%d\n",sum);
	return 0;
} 