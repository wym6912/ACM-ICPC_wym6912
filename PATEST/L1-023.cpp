#include <bits/stdc++.h>

using namespace std;

char data[10009];

int g, p, l, t;

int main()
{
	scanf("%s", data);
	int ld = strlen(data);
	for(int i = 0; i < ld; i ++)
	{
		switch(data[i])
		{
			case 'G':
			case 'g':
				g ++;
				break;
			case 'P':
			case 'p':
				p ++;
				break;
			case 'L':
			case 'l':
				l ++;
				break;
			case 'T':
			case 't':
				t ++;
				break;
		}
	}
	while(g || p || l || t)
	{
		if(g)printf("G"), g --;
		if(p)printf("P"), p --;
		if(l)printf("L"), l --;
		if(t)printf("T"), t --;
	}
	printf("\n");
	return 0;
}
