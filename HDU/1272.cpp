//#define NOSTDCPP
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

int ss[maxn], pp;

int find(int a){return ss[a] == a ? a : ss[a] = find(ss[a]);}

set <pair <int, int> > edg;
si mpp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int from, to;
	int Case = 0;
	int size = 0, edge = 0;
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
			edge = edg.size();
			pp = mpp.size();
			//cout << pp << ' ' << edge << endl;
			if(edge + 1 != pp)flag = false;
			if(edge == 0 && pp == 0)flag = true;
			flag ? cout << "Yes" << endl : cout << "No" << endl;
			for(int i = 1;i <= maxn - 1;i ++)
				ss[i] = i;
			flag = true;
			size = 0;
			edge = 0;
			pp = 0;
			mpp.clear();
			edg.clear();
		}
		else
		{
			if(find(from) != find(to))
			{
				mpp.insert(from);
				mpp.insert(to);
				edg.insert(make_pair(from, to));
				from = find(from);
				to = find(to);
				ss[from] = to;
			}
			else flag = false;
		}
	}
}
//You should specially judge the (0,0)
