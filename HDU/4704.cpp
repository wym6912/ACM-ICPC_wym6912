#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define MAXN 1000100
#define MOD 1000000007
#define LL long long
using namespace std;
char s[MAXN];
LL fun(LL a,LL b)//数据大，全程longlong吧
{
	LL ans=1;
	while(b)
	{
		if(b%2)
		ans=ans*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return ans;
}
int main()
{
	int i;
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		LL num=0;
		for(i=0;i<len;i++)
		{
			num=(num*10+s[i]-'0')%(MOD-1);
		}
	    LL ans=fun(2,num-1);
	    printf("%lld\n",ans);
	}
	return 0;
}
