#include <bits/stdc++.h>

using namespace std;

class ppp
{
	public:
		ppp(){memset(st,0,sizeof(st));reset();ina_();}
		~ppp(){}
		void reset(){end_ = 0;flag = true;}
		void ina_()
		{
			scanf("%d",&nn);
			max_ = nn;
			for(int i = 1;i <= nn;i ++)
			{
				scanf("%d",&num);
				pin(num);
				de(num,nn,i);

			}
		}
		void pin(int n)
		{
			end_ ++;
			st[end_] = n;
			if(st[end_] > st[end_ - 1])flag = true;
			else flag = false;
		}
		void pout()
		{
			end_ --;
			choosemax();
		}
		void choosemax()
		{
			int tmp = 0;
			for(int i = 1;i <= end_;i ++)
			if(st[i] > st[end_])
			{
				tmp = st[end_];
				st[end_] = st[i];
				st[i] = tmp;
			}
		}
		int min(int a,int b)
		{
			if(a > b)return b;
			return a;
		}
		void de(int num,int nn,int i)
		{
			flag2 = true;
			if(flag)
			while(end_ != 0 && flag2 &&(num + i >= nn + 1)&& num >= max_)
			{
				printf("%d",st[end_]);
				max_ = st[end_] - 1;
				pout();
				if(st[end_ + 1] == st[end_] + 1)num = st[end_];
				else flag2 = false;
				if(end_ != 0 && flag2)printf(" ");
			}
			printf("\n");
		}
	private:
		int num,nn,end_;
		int st[100001];
		bool flag,flag2;
		int max_;
};

int main()
{
	ppp a;
	return 0;
}
