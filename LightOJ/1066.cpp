//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define midf(x, y) ((x + y) >> 1)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 20;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct node
{
    int x, y, step;
};

int dx[] = { 0, 1, 0,-1};
int dy[] = { 1, 0,-1, 0};

int n, al;

char mapp[maxn][maxn];

bool stat[maxn][maxn];

node nodes[30];

int bfs(int fx, int fy, int tx, int ty, int aid)
{
    queue <node> qqq;
    while(! qqq.empty())qqq.pop();
    node now, info;
    now.x = fx;
    now.y = fy;
    now.step = 0;
    stat[fx][fy] = true;
    qqq.push(now);
    while(! qqq.empty())
    {
        info = qqq.front();
        if(info.x == tx && info.y == ty)return info.step;
        qqq.pop();
        for(int i = 0; i <= 3; i ++)
        {
            now.x = info.x + dx[i];
            now.y = info.y + dy[i];
            now.step = info.step + 1;
            if(now.x >= 1 && now.x <= n && now.y >= 1 && now.y <= n)
            {
                if(mapp[now.x][now.y] != '#')
                {
                    if(mapp[now.x][now.y] == '.')
                    {
                        if(stat[now.x][now.y] == false)
                            qqq.push(now), 
							stat[now.x][now.y] = true;
                    }
                    else if(mapp[now.x][now.y] == aid + 'A' || mapp[now.x][now.y] == aid + 'A' - 1)
                    {
                    	if(stat[now.x][now.y] == false)
                            qqq.push(now), 
							stat[now.x][now.y] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int f()
{
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(mapp[i][j] >= 'A' && mapp[i][j] <= 'A' + al - 1)
				nodes[mapp[i][j] - 'A' + 1].x = i, 
				nodes[mapp[i][j] - 'A' + 1].y = j;	
	for(int i = 1; i < al; i ++)
	{
		RESET(stat);
		int tmp = bfs(nodes[i].x, nodes[i].y, nodes[i + 1].x, nodes[i + 1].y, i);
		if(tmp == -1)
			return -1;
		else ans += tmp;
		mapp[nodes[i].x][nodes[i].y] = '.';
	}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("1066.txt", "w", stdout);
	int T, fx, fy, tx, ty;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; Casen ++)
    {
        printf("Case %d: ", Casen);
        al = 0;
        //RESET(nodes);
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("\n%s", mapp[i] + 1); //from (1, 1)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                if(mapp[i][j] >= 'A' && mapp[i][j] <= 'Z')
                    al = max(al, mapp[i][j] - 'A' + 1);
        if(al == 1)
        {
            printf("0\n");
            continue;
        }
        else
        {
        RESET(stat);
        int ans = f();
        if(ans != -1)printf("%d\n", ans);
        else printf("Impossible\n");
        }
    }
	return 0;
}

