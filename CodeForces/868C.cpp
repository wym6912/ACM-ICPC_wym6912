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
int maxm;
const double pi = acos(-1.0);
const double eps = 1e-6;

int my[10], prob[maxn], data[maxn];
int anss[1 << 9];

inline bool out(int x[], int size)
{
	cout << "Array :" << endl;
	for(int i = 0;i < size;i ++)
		cout << x[i] << ' ';
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	bool tmp;
	while(cin >> n >> m)
	{
		RESET(data);
		//RESET(team);
		RESET(prob);
		for(int k = 1;k <= n;k ++)
			for(int i = 1;i <= m;i ++)
			{
				cin >> tmp;
				prob[k] <<= 1;
				prob[k] |= tmp;
			}
		for(int i = 1;i <= n;i ++)
			anss[prob[i]] ++;
		//out(anss, (1 << m));
		bool flag = false;
		maxm = (1 << m) - 1;
		anss[maxm] = 1;
		for(int i = 0;i <= maxm && !flag;i ++)
			for(int j = 0;j <= maxm && ! flag;j ++)
			{
				if(i == j && anss[i] == 1)continue;
				if(! (i & j) && anss[i] && anss[j])
					flag = true;
			}
		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
