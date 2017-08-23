#include <bits/stdc++.h>

#define debug printf("Function [%s] in line [%d]\n",__FUNCTION__,__LINE__)
#define first fi
#define second sc

typedef long long ll;

int a[1001],b[1001],c[1001]; 
bool isused[1001];
int x;

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	memset(isused,false,sizeof(isused));
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= n;i ++)	
		scanf("%d",&b[i]);
	for(int i = 1;i <= n;i ++)
		if(a[i] == b[i] && !isused[a[i]])
			c[i] = a[i],isused[a[i]] = true,x ++;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			if(a[i] == a[j] && i != j)
			{
				a[0] = a[i];
				break;
			}
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			if(b[i] == b[j] && i != j)
			{
				b[0] = b[i];
				break;
			}
	for(int i = 1;i <= n;i ++)
		if(!c[i])
		{
			if(n - x == 1)
				for(int j = 1;j <= n;j ++)
				{
					if(!isused[j])
					{
						c[i] = j;
						isused[j] = true;
						break;
					}
				}
			else
			{
				if(!isused[a[0]] && isused[b[0]])
					c[i] = a[0],isused[c[i]] = true,x ++;
				else if(isused[a[0]] && !isused[b[0]])
					c[i] = b[0],isused[c[i]] = true,x ++;
				else if(!isused[a[0]] && !isused[b[0]]) c[i] = a[0],isused[c[i]] = true,x ++;
				else if(isused[a[0]] && isused[b[0]])
					for(int j = 1;j <= n;j ++)
						if(!isused[j] && (j == b[i] || j == a[i]))
						{
							c[i] = j,isused[c[i]] = true,x ++;
							break;
						}
			}
		}
	printf("%d",c[1]);
	for(int i = 2;i <= n;i ++)
		printf(" %d",c[i]);
	printf("\n");
	return 0;
}
