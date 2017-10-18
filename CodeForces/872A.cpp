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

#define RESET(_) memset(_, 0, sizeof(_))
#define RESET_(_, val) memset(_, val, sizeof(_))
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int x[10], y[10];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> m)
	{
		for(int i = 1;i <= n;i ++)
			cin >> x[i];
		for(int i = 1;i <= m;i ++)
			cin >> y[i];
		sort(x + 1, x + 1 + n);
		sort(y + 1, y + 1 + m);
		int ans = min(x[1] * 10 + y[1], y[1] * 10 + x[1]);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				if(x[i] == y[j])
					ans = min(ans, x[i]);
		cout << ans << endl;
	}
	return 0;
}
