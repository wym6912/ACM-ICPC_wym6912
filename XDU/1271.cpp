#include <bits/stdc++.h>

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 109;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct status
{
	int x, y;
	int step;
	int tempstate;
};

int n, m, type;
int mp[maxn][maxn];
bool isvisited[maxn][maxn];

int dx[] = { 1, 0,-1, 0};
int dy[] = { 0, 1, 0,-1};

int bfs(int fx, int fy, int ex, int ey)
{
	if(mp[fx][fy] == 0 || mp[ex][ey] == 0)return -1;
	queue <status> qqq;
	status init, temp;
	init.x = fx, init.y = fy, init.step = 0, init.tempstate = mp[fx][fy];
	qqq.push(init);
	while(! qqq.empty())
	{
		init = qqq.front();
		if(init.x == ex && init.y == ey)return init.step;
		for(int i = 0;i <= 3;i ++)
		{
			int px = init.x + dx[i], py = init.y + dy[i];
			if(px > 0 && px <= n && py > 0 && py <= m)
			{
				if(mp[px][py] == 0)continue; 
				if(mp[px][py] != init.tempstate % type + 1)continue;
				if(! isvisited[px][py])
				{
					temp.x = px;
					temp.y = py;
					temp.step = init.step + 1;
					temp.tempstate = mp[px][py];
					qqq.push(temp);
					isvisited[px][py] = true;
					
				}
			}
		}
		qqq.pop();
	}
	return -1;
}

int main()
{
	int fx, fy, ex, ey;
	while(~ scanf("%d%d%d", &n, &m, &type)) 
	{
		RESET(isvisited);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				scanf("%1d", &mp[i][j]); 
		scanf("%d%d%d%d", &fx, &fy, &ex, &ey); 
		printf("%d\n", bfs(fx, fy, ex, ey));
	}
	return 0;
}

