#include <bits/stdc++.h>

using namespace std;

bool map1[109][109];
int n,m;

bool isend(int k,int pos,bool right)
{
	if(right)
	{
		for(int i = pos;i <= m + 2;i ++)
			if(map1[k][i])
				return false;
		return true;
	}
	else
	{
		for(int i = pos;i > 0;i --)
			if(map1[k][i])
				return false;
		return true;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m + 2;j ++)
			scanf("%1d",&map1[i][j]);
	bool right = true;
	int pos = 0, ans = 0;
	for(int i = n;i >= 1;)
	{
		if(isend(i,pos,right))
			i --, ans ++, pos = (right) ? (m - 1) : 0;
		else 
		{
			ans ++;
			pos ++;
			if(map1[i][pos])
				map1[i][pos] = false;
		}
		if(isend(i,pos,right) && i == 1)
			break;
		cout << i << ' ' << pos << endl;
	}
	printf("%d\n",ans);
} 
