#include <iostream>
#include <string.h>
#define mod 1000000007
using namespace std;
int n,m;
long long dp[16][1<<16];
void dfs(int j,int i,int state,int nex)
{
	if (j==m)
	{
		dp[i+1][nex]+=dp[i][state];
		//dp[i+1][nex]%=mod;
		return ;
	}
	//这个位置不能填
	if (((1<<j)&state)>0) dfs(j+1,i,state,nex);
	else
	{
		//竖着
		dfs(j+1,i,state,nex|(1<<j));
		//横着
		if (j+1<m && ((1<<(j+1))&state)==0)
			dfs(j+2,i,state,nex);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>m && (n || m))
	{
		if(n == 0 || m == 0)
		{
			cout << 0 << endl; 
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (int i=0;i<n;i++)
			for (int state=0;state<(1<<m);state++)
			if (dp[i][state]) 
			{
				dfs(0,i,state,0);
			}
		cout<<dp[n][0]<<endl;
	}
	return 0;
}
