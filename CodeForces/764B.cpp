#include <bits/stdc++.h>

using namespace std;

class Wood
{
	public:
		Wood(){memset(num,0,sizeof(num));use();}
		~Wood(){}
		void Swap(int *a,int *b)
		{
			int p = *a;
			*a = *b;
			*b = p;
		}
		void input()
		{
			scanf("%d",&n);
			for(int i = 1;i <= n;i ++)
				scanf("%d",&num[i]);
		}
		void output()
		{
			for(int i = 1;i <= n;i ++)
			{
				printf("%d",num[i]);
				if(i != n)printf(" ");
				else printf("\n");
			}
		}
		void reverse()
		{
			for(int i = 1;i <= n / 2;i += 2)
				Swap(num + i,num + n - i + 1);
			/*if(n % 2) r1();
			else  if(n % 4)r21();
			else r22();*/
		}
		void r1()
		{
			for(int i = 1;i <= (n + 1) / 2;i += 2)
				Swap(num + i,num + n + 1 - i);
		}
		void r21()
		{
			for(int i = 1;i <= n / 2;i += 2)
				Swap(num + n / 2 - i + 1,num + n / 2 + i);			
		}
		void r22()
		{
			for(int i = 1;i <= n / 4 + 1;i += 2)
				Swap(num + n / 2 - i,num + n / 2 + i + 1);
		}
		void use(){input();reverse();output();}
	private:
		int n;
		int num[400001];
};

int main()
{
	Wood w;
	return 0;
}
