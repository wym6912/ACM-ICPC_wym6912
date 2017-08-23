#include <bits/stdc++.h>

using namespace std;

struct rating
{
	int fir,sec;
}r[1001];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d %d",&r[i].fir,&r[i].sec);
	bool flag = true;
	for(int i = 1;i <= n;i ++)
		if(r[i].fir != r[i].sec)
		{
			printf("rated\n");
			return 0;
		}
	for(int i = 1;i <= n;i ++)
		for(int j = i + 1;j <= n;j ++)
			if(r[j].fir > r[i].fir)
			{
				printf("unrated\n");
				return 0;
			}
	printf("maybe\n");
	return 0;
} 
