#include <bits/stdc++.h>

using namespace std;

bool ss[3];

void swap(int a,int b)
{
	bool c;
	c = ss[a];
	ss[a] = ss[b];
	ss[b] = c;
}

void swap2()
{
	swap(0,2);
	swap(2,1);
}

int main()
{	
	int a,b;
	cin>>a>>b;
	ss[b] = true;
	if(a%2){swap(0,1);a--;}
	for(int i = 2;i <= a % 6;i += 2)
		{swap2();}
	for(int i = 0;i <= 2;i ++)
		if(ss[i])
		{
			printf("%d\n",i);
			return 0;
		}
}
