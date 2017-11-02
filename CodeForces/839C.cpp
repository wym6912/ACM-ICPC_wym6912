//#define NOSTDCPP
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
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
vi g[maxn];

double dfs(int now, int father)
{
	bool flag = false;
	double cnt = 0.0;
	double ans = 0.0;
	for(int i = 0;i < g[now].size();i ++)
	{
		if(g[now][i] == father)continue;
		ans += dfs(g[now][i], now);
		cnt += 1.0;
	}
	if(cnt != 0.0)ans /= cnt, ans += 1.0;
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int f, t;
	while(~ scanf("%d", &n))
	{
		for(int i = 1;i <= n;i ++)
			g[i].clear();
		for(int i = 1;i < n;i ++)
		{
			//cin >> f >> t;
			scanf("%d%d", &f, &t);
			g[f].push_back(t);
			g[t].push_back(f);
		}
		//cout << dfs(1, 0) << endl;
		printf("%.15lf\n", dfs(1, 0));
	}
	return 0;
}

