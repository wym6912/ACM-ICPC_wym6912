#include <bits/stdc++.h>

using namespace std;

struct Balloon
{
	int number;
	string name;
}balloon[1001];

bool comp(const Balloon &a,const Balloon &b)
{
	return a.number<b.number;
}

int main()
{
	//map <string , int> best_;
	int N,pointer=0;
	bool flag;
	string s;
	while(cin>>N&&N!=0)
	{
		for(int i=1;i <= pointer;i++)
		{
			balloon[i].name.clear();
			balloon[i].number = 0; 
		}
		pointer = 0;
		for(int i=1;i<=N;i++)
		{
			flag = false;
			cin>>s;
			for(int j = 1;j <= pointer; j++)
				if(balloon[j].name == s)
				{
					flag = true;
					balloon[j].number++;
				}
			if(!flag)
			{
				pointer++;
				balloon[pointer].name = s;
				balloon[pointer].number = 1;
			}
		}
		sort(balloon+1,balloon+N+1,comp);
		cout<<balloon[N].name<<endl;
		}
	return 0;
}