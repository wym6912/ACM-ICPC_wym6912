#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int ss[maxn], used[maxn], pp;

int find(int a){return ss[a] == a ? a : ss[a] = find(ss[a]);}
bool findit(int x)
{
	for(int i = 1;i <= pp;i ++)
		if(x == used[i])
			return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int from, to;
	int Case = 0;
	int size = 0;
	bool flag = true;
	for(int i = 1;i <= maxn - 1;i ++)
		ss[i] = i;
	pp = 0;
	while(true)
	{
		cin >> from >> to;
		if(from == -1 && to == -1)
			return 0;
		else if(! from && ! to)
		{
			//for(int i = 1;i <= pp;i ++)
			//	cout << ss[used[i]] << ' ' << used[i] << endl;
			for(int i = 2;i <= pp;i ++)
				if(find(ss[used[i]]) != find(ss[used[1]]))
					flag = false;
			if(pp == 1)flag = false;
			cout << "Case " << ++ Case << " is " << (! flag ? "not " : "") << "a tree." << endl;
			for(int i = 1;i <= maxn - 1;i ++)
				ss[i] = i;
			flag = true;
			size = 0;
			pp = 0;
			RESET(used);
		}
		else
		{
			if(find(from) != find(to))
			{
				if (! findit(from))used[++ pp] = from;
				if (! findit(to))  used[++ pp] = to;
				from = find(from);
				to = find(to);
				ss[from] = to;
				//for(int i = 1;i <= 10;i ++)
				//	cout << ss[i] << ' ';
				//cout << endl;
				size = max(max(from, to), size);
			}
			else flag = false;
		}
	}
}

