#include <cstdio>
#include <iostream>

using namespace std;

bool map[6][6],isused[17];

int dx[] = {1,0,-1,0,0},
    dy[] = {0,1,0,-1,0};

int ans2;

inline bool piece(char x)
{
	return x == 'b' ? true : false;
}

bool judge()
{
	for(int i = 1;i <= 4;i ++)
		for(int j = 1;j <= 4;j ++)
			if(map[i][j] != map[1][1])
				return false;
	return true;
}

void print()
{
	int ans = 0;
	for(int i = 0;i < 16;i ++)
		if(isused[i])
			ans ++;
	ans2 = min(ans,ans2);
	//OK = true;
}

void filp(int s)
{
	//cout << s << " = " << endl;
	if(s == 16)
	{
		if(judge())
			print();
		return ;
	}
	int px = s / 4 + 1, py = s % 4 + 1;
	for(int i = 0;i <= 4;i ++)
		if(px + dx[i] >= 1 && px + dx[i] <= 4 &&
		   py + dy[i] >= 1 && py + dy[i] <= 4)
		   	map[px + dx[i]][py + dy[i]] = ! map[px + dx[i]][py + dy[i]];
	isused[s] = true;
	filp(s + 1);
	isused[s] = false;
	for(int i = 0;i <= 4;i ++)
		if(px + dx[i] >= 1 && px + dx[i] <= 4 &&
		   py + dy[i] >= 1 && py + dy[i] <= 4)
		   	map[px + dx[i]][py + dy[i]] = ! map[px + dx[i]][py + dy[i]];
	filp(s + 1);
	return ;		
}

int main()
{
	char x;
	for(int i = 1;i <= 4;i ++)
		for(int j = 1;j <= 4;j ++)
		{
			scanf("\n%c",&x);
			map[i][j] = piece(x);
		}
	//for(int i = 1;i <= 4;i ++)for(int j = 1;j <= 4;j ++)cout << map[i][j] << endl;
	ans2 = 1 << 20;
	filp(0);
	printf(ans2 == 1 << 20 ? "Impossible\n" : "%d\n", ans2);
	return 0;
}
