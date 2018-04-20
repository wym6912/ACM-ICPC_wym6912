#define NOSTDCPP
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
	int step;
}eight;

int father[maxm], step[maxm];

int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320}; 
int dx[] = { 0, 1,-1, 0};
int dy[] = { 1, 0, 0,-1};

int Cantor(int n, eight a)
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

bool bfs(eight e0, eight end)
{
	queue <eight> qe;
	eight ff, temp;
	e0.step = 0;
	qe.push(e0);
	int endp = Cantor(9, end);
	int fir = Cantor(9, e0);
	if(endp == fir)return printf("0\n"), true;
	visited[fir] = true;
	while(! qe.empty())
	{
		ff = qe.front();
		ff.step ++;
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
				if(ct == endp)
				{
					printf("%d\n", ff.step);
					return true;
				}
				qe.push(temp); 
			}
		qe.pop();
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	eight end, e0;
	end.num[0] = 9;
	for(int i = 1; i < 9; i ++)
		end.num[i] = i;
	//for(int i = 0; i < 9; i ++)
	//	cout << end.num[i] << ' ';
	//cout << endl;
	while(T --)
	{
		for(int i = 0; i < 9; i ++)
			scanf("%d", &e0.num[i]), e0.num[i] == 0 ? e0.num[i] = 9 : false;
		//for(int i = 0; i < 9; i ++)
		//	cout << end.num[i] << ' ';
		//cout << endl;
		RESET(visited);
		//int i = 0, p = 0;
		/*while(nn[i] != '\0')
		{
			if(nn[i] >= '1' && nn[i] <= '8')
				e0.num[p ++] = nn[i] - '0';
			else if(nn[i] == '0')
				e0.num[p ++] = 9;
			i ++;
		}*/
		if(! bfs(e0, end))puts("cannot");
	}
	return 0;
}
/*
3
1 4 2
3 0 5
6 7 8
1 4 2
3 8 5
6 7 0
1 0 2
3 4 5
6 7 8
*/
