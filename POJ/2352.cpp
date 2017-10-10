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

int n, ind[maxn], ans[maxn];

int lowbit(int x){return x & -x;}

int query(int x)
{
	int ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
	    ans += ind[i];
	return ans;
}

void update(int x, int val)
{
	for(int i = x;i <= maxn;i += lowbit(i))
		ind[i] += val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	while(cin >> n)
	{
		RESET(ans);
		RESET(ind);
		for(int i = 1;i <= n;i ++)
		{
			cin >> x >> y;
			ans[query(x + 1)] ++;
			update(x + 1, 1);
		}
		for(int i = 0;i < n;i ++)
			cout << ans[i] << endl;
	}
	return 0;
}
