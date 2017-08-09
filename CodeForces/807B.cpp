#include <bits/stdc++.h>

using namespace std;

int ans;

bool check(int x,int p)
{
	x = (x / 50) % 475;
	for(int i = 0;i < 25;i ++)
		if((x = x * 96 + 42) % 475 + 26 == p)
			return true;
	return false;
}

void doit(int a,int b,int c)
{
	int x = a;
	while(x >= b)
	{
		if(check(x,c))
		{
			printf("%d\n",ans);
			return ;
		}
		x -= 50;
	}
	while(!check(a,c))
	{
         a += 50;
         ans ++;
         if(check(a,c)){
             cout<<ans<<endl;
             return;
         }
         a += 50;
     }
     cout << ans <<endl;
     return;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(b < c)ans ++,b += 100;
	doit(b,c,a);	
	return 0;
}
