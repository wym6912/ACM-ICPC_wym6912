#include <bits/stdc++.h>

using namespace std;

char s[19], two[19], fourteen[19];
int cnt;

int main()
{
	cnt = 0;
	while(scanf("%s", s) && strcmp(s, "."))
	{
		cnt ++;
		if(cnt == 2) strcpy(two, s);
		if(cnt == 14)strcpy(fourteen, s);
	}
	if(cnt < 2)
		puts("Momo... No one is for you ...");
	else if(cnt < 14)
		printf("%s is the only one for you...\n", two);
	else 
		printf("%s and %s are inviting you to dinner...\n", two, fourteen);
	return 0;
}
