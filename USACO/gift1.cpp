/*
ID: wym69121
PROG: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

struct info
{
	char name[15];
	int count;
	info()
	{
		count = 0;
		memset(name,'\0',sizeof(name));
	}
}aaaa[11];

char aaa[15];

int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int n,a,b;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%s",aaaa[i].name);
	scanf("\n\t");
	for(int i = 1;i <= n;i ++)
	{
		scanf("%s",aaa);
		scanf("%d %d\n\t",&a,&b);
		if(a || b)
		{
			for(int j = 1;j <= n;j ++)
				if(!strcmp(aaa,aaaa[j].name))
					aaaa[j].count -= a,aaaa[j].count += a % b;
			for(int j = 1;j <= b;j ++)
			{
				scanf("%s",aaa);
				for(int k = 1;k <= n;k ++)
					if(!strcmp(aaa,aaaa[k].name))
						aaaa[k].count += a / b;
			}
		}
	}
	for(int i = 1;i <= n;i ++)
		printf("%s %d\n",aaaa[i].name,aaaa[i].count);
	return 0;
}
