#include <bits/stdc++.h>

using namespace std;

const int N = 300005; 

char a[N],b[N],c[N];

int main()
{
	scanf("%s\n%s",a,b);
	int x = strlen(a);
	sort(a,a + x);
	sort(b,b + x);
	int tmpb = x - 1,tmpa = 0;
	int begin = 0,end = x - 1;
	int lima = (x + 1) / 2 - 1,limb = x - (x - lima) + 1;
	for(int i = 1;i <= x;i ++)
	{
		if(i & 1)  //处理 a 数组，要么放到头，要么放到尾 
		{
			if(a[tmpa] < b[tmpb])
				c[begin ++] = a[tmpa ++];
			else c[end --] = a[lima --];
		}
		else      //b 同理 
		{			
			if(a[tmpa] < b[tmpb])
				c[begin ++] = b[tmpb --];
			else c[end --] = b[limb ++];
		}
	}
	cout << c << endl;
	return 0;
}
