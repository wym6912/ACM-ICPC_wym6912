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
# define pb push_back

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 50000 + 10;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int father[maxn];
int rank[maxn];

int n, m;

int findfa(int x){return x == father[x] ? x : findfa(father[x]);}

void mergex(int x, int y)
{
	x = findfa(x);
	y = findfa(y);
	if(rank[x] < rank[y]) //按秩合并的复杂度是 O(nlogn) 
		father[y] = x;
	else 
	{
		father[x] = y;
		if(father[x] == father[y])rank[y] ++;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Casen = 0, f, t, ans;
	while(cin >> n >> m && (n && m))
	{
		ans = n;
		for(int i = 1; i <= n; i ++)
			father[i] = i, rank[i] = 0;
		for(int i = 1; i <= m; i ++)
		{
			cin >> f >> t;
			if(findfa(f) != findfa(t))
				ans --, mergex(f, t);
		}
		cout << "Case " << ++ Casen << ": " << ans << endl;
	}
	return 0;
}

