#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
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
const int maxn = 29;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, ans;
char mp[maxn][maxn];
bool row[maxn], col[maxn];

bool ok(int i, int j)
{
	if(i < 0 || j < 0 || j >= n || i >= n || mp[i][j] == '.')
		return false;
	if(row[i] || col[j])
		return false;
	return true;
}

void dfs(int x, int y, int num)
{
	if(num == m)
	{
		ans ++;
		return ;
	}
	else
	{
		for(int i = x;i < n;i ++)
			for(int j = 0;j < n;j ++)
				if(ok(i, j))
				{
					row[i] = col[j] = true;
					dfs(i, j, num + 1);
					row[i] = col[j] = false;
				}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(~ scanf("%d%d", &n, &m) && (n != -1 && m != -1))
	{
		RESET(col);
		RESET(row);
		ans = 0;
		for(int i = 0;i < n;i ++)
			scanf("\n%s", mp[i]);
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

