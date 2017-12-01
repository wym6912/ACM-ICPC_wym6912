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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 362880;
const double pi = acos(-1.0);
const double eps = 1e-6;

bool visited[maxm];

typedef struct
{
	int num[9];
}eight;

int father[maxm], step[maxm];

int fac[] = {1,1,2,6,24,120,720,5040,40320}; 
int dx[] = { 0, 1,-1, 0};
int dy[] = { 1, 0, 0,-1};

int Cantor(int n,eight a)
{
    int i, j, t, sum;
    sum = 0;
    for(i = 0; i < n; i ++)
    {
        t = 0;
        for(j = i + 1; j < n; ++ j)
            if(a.num[i] > a.num[j])
                ++ t;
        sum += t * fac[n - i - 1];
    }
    return sum;
}
 
void CantorReverse(int n, int CantorValue, eight e)
{
    int i, j, t, vst[10] = {0};
    for (i = 0; i < n; i ++)
    {
        t = CantorValue / fac[n - i - 1];
        for (j = 1;j < n;j ++)
            if (! vst[j])
            {
                if (t == 0) break;
                -- t;
            }
        e.num[i] = j;
        vst[j] = 1;
        CantorValue %= fac[n - i - 1];
    }
}

void o(int CantorValue)
{
	//cout << "We have reached here." << endl;
	char path[1009];
	int cnt = 0;
	int cx = CantorValue;
	while(father[cx] != -1)
	{
		path[cnt ++] = step[cx];
		cx = father[cx];
	//	cout << cx << endl;
	}
	for(int i = 0; i < cnt; i ++)
	{
		switch(path[i])
		{
			case 0:
				cout << 'l';
				break;
			case 1:
				cout << 'u';
				break;
			case 2:
				cout << 'd';
				break;
			case 3:
				cout << 'r';
				break;
			default:
				assert(false);
		}
	}
	cout << endl;
}

void bfs(eight e0)
{
	queue <eight> qe;
	eight ff, temp;
	qe.push(e0);
	visited[0] = true;
	father[0] = -1;
	while(! qe.empty())
	{
		ff = qe.front();
		int nine_place = 0, px, py, ctf;
		for(int i = 0;i < 9;i ++)
			if(ff.num[i] == 9)
				nine_place = i;
		px = nine_place / 3, py = nine_place % 3;
		ctf = Cantor(9, ff);
		for(int i = 0;i < 4;i ++)
			if(px + dx[i] >= 0 && px + dx[i] < 3 
			&& py + dy[i] >= 0 && py + dy[i] < 3)
			{
				temp = ff;
				swap(temp.num[nine_place], temp.num[(px + dx[i]) * 3 + (py + dy[i])]);
				int ct = Cantor(9, temp);
				if(visited[ct])continue;
				visited[ct] = true;
				step[ct] = i;
				father[ct] = ctf;
				qe.push(temp); 
			}
		qe.pop();
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	RESET(visited);
	RESET(father);
	RESET(step);
	eight end;
	for(int i = 0;i < 9;i ++)
		end.num[i] = i + 1;
	char nn[109];
	bfs(end);
	while(cin.getline(nn, 109))
	{
		eight e0;
		int i = 0, p = 0;
		while(nn[i] != '\0')
		{
			if(nn[i] >= '1' && nn[i] <= '8')
				e0.num[p ++] = nn[i] - '0';
			else if(nn[i] == 'x')
				e0.num[p ++] = 9;
			i ++;
		}
		if(Cantor(9, e0) == 0)cout << "lr" << endl;
		else if(visited[Cantor(9, e0)])
		{
			o(Cantor(9, e0));
		}
		else cout << "unsolvable" << endl;
	}
	return 0;
}
