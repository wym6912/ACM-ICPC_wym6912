#include<bits/stdc++.h>
using namespace std;

const int maxn = 3005;

typedef long long ll;


bool visited[maxn], vf[maxn];
//int first[maxn], ff[maxn];
bool graph[maxn][maxn];
int n;

bool dfs(int x, int floors, int end) // find circles
{ 
	//printf("Call Function %s : x = %d, floors = %d, end = %d\n",__FUNCTION__, x, floors, end);
	if(floors == 4 && x != end)return true;
	if(floors == 4 && x == end)return false;
	//if(! graph[end].size())return true;
	visited[x] = true;
	//first[x] = floors;
	bool ans = true;
	for(int i = 1;i <= n && ans;i ++)
		if(graph[x][i])
			ans &= dfs(i, floors + 1, end);
	return ans;
}


bool dfsf(int x, int floors, int end) // find circles
{ 
	//printf("Call Function %s : x = %d, floors = %d, end = %d\n",__FUNCTION__, x, floors, end);
	if(floors == 4 && x != end)return true;
	if(floors == 4 && x == end)return false;
	//if(! gf[end].size())return true;
	vf[x] = true;
	//ff[x] = floors;
	bool ans = true;
	for(int i = 1;i <= n && ans;i ++)
		if(! graph[x][i] && x != i)
			ans &= dfsf(i, floors + 1, end);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, tmp;
	bool flag;
	while(~ scanf("%d", &T))
	{
		while(T --)
		{
			scanf("%d",&n);
			flag = true;
			memset(visited,false,sizeof(visited));
			memset(vf,false,sizeof(vf));
			memset(graph,false,sizeof(graph));
			//for(int i = 1;i <= n;i ++)graph[i].clear(),gf[i].clear();
			for(int i = 1;i <= n - 1;i ++)
				for(int j = 1;j <= n - i;j ++)
				{
					scanf("%d",&tmp);
					if(tmp)
						graph[i + j][i] = graph[i][i + j] = true;
				}
			for(int i = 1;i <= n;i ++)
			{
				if(! dfs(i, 1, i) || ! dfsf(i ,1, i))
				{
					flag = false;
					break;
				}
			}
			//for(int i = 1;i <= n;i ++)
			//	for(int j = 0;j < gf[i].size();j ++)
			//		printf("%d%c",gf[i][j], j == gf[i].size() - 1 ? '\n' : ' ');
			/*if(flag)
				for(int i = 1;i <= n;i ++)
					if(! visited[i])
						flag = false;*/
			flag ? printf("Great Team!\n") : printf("Bad Team!\n");
		}
	}
	return 0;
}
