#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>

using namespace std;

int data[1001];

int main()
{
	int n,x;
	bool flag;
	stack <int> s;
	while(~ scanf("%d",&n))
	{
		while(scanf("%d",&data[1]) && data[1])
		{
			while(! s.empty())s.pop();
			for(int i = 2;i <= n;i ++)
				scanf("%d",&data[i]);
			x = 1;
			for(int i = 1;i <= n;i ++)
			{
				s.push(i);
				while((! s.empty()) && s.top() == data[x])
				{
					x ++;
					s.pop();
				}
			}
			if(s.empty())printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}
