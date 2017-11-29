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
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

bool isusedx[10][10], isusedy[10][10], isprinted, isin[10][10];

int mp[10][10];

int pf(int x, int y)
{
	x --, y --;
	int pi = x / 3 + 1, pj = y / 3;
	return pi + pj * 3;
}

bool ok()
{
	for(int i = 1;i <= 9;i ++)
		for(int j = 1;j <= 9;j ++)
			if(! isusedx[i][j])
				return false;
	for(int i = 1;i <= 9;i ++)
		for(int j = 1;j <= 9;j ++)
			if(! isusedy[i][j])
				return false;
	for(int i = 1;i <= 9;i ++)
		for(int j = 1;j <= 9;j ++)
			if(! isin[i][j])
				return false;
	return true;
}

void print()
{
	isprinted = true;
	for(int i = 1;i <= 9;i ++)
	{
		for(int j = 1;j <= 9;j ++)
			printf("%1d", mp[i][j]);
		printf("\n");
	}
	//printf("\n");
}

bool isok(int da, int x, int y)
{
	return (isusedx[x][da] == false && isusedy[y][da] == false && isin[pf(x, y)][da] == false);
}

void dfs(int x, int y)
{
	if(isprinted)return ;
	if(x == 10 && y == 1 && ok())
	{
		print();
		return ;
	}
	int nx = x, ny = y + 1;
	if(ny > 9)
	{
		nx ++;
		ny = 1;
	}
	if(mp[x][y])
		dfs(nx, ny);
	else 
	{
		for(int i = 1;i <= 9;i ++)
			if(isok(i, x, y))
			{
				isusedx[x][i] = isusedy[y][i] = isin[pf(x, y)][i] = true;
				mp[x][y] = i;
				dfs(nx, ny);
				if(isprinted)return ;
				mp[x][y] = 0;
				isusedx[x][i] = isusedy[y][i] = isin[pf(x, y)][i] = false;
			}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		RESET(isusedx);
		RESET(isusedy);
		RESET(isin);
		isprinted = false;
		for(int i = 1;i <= 9;i ++)
			for(int j = 1;j <= 9;j ++)
			{
				scanf("%1d", &mp[i][j]);
				if(mp[i][j] )
					isusedx[i][mp[i][j]] = isusedy[j][mp[i][j]] = isin[pf(i, j)][mp[i][j]] = true;
			}
		/*
		for(int i = 1;i <= 9;i ++)
		{
			for(int j = 1;j <= 9;j ++)
				printf("%d ", isin[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
		dfs(1, 1);
	}
	return 0;
}

