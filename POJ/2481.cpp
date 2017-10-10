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

struct node
{
	int f, t, ind;
	friend bool operator < (const node &a, const node &b)
	{
		return a.t == b.t ? a.f < b.f : a.t > b.t;
	}
}node[maxn];

int ind[maxn], ans[maxn], anss[maxn], n;

int lowbit (int x){return x & -x;}

void update(int x, int val)
{
	for(int i = x;i <= n;i += lowbit(i))
		ind[i] += val;
}

int query(int x)
{
	int ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
		ans += ind[i];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n && n)
	{
		RESET(ind);
		RESET(anss);
		RESET(ans);
		for(int i = 1;i <= n;i ++)
			cin >> node[i].f >> node[i].t, node[i].ind = i;
		sort(node + 1, node + 1 + n);
		for(int i = 1;i <= n;i ++)
			ans[node[i].ind] = i;
		for(int i = 1;i <= n;i ++)
		{
			if(node[i].f == node[i - 1].f && node[i].t == node[i - 1].t)anss[node[i].ind] = anss[node[i - 1].ind];
			else
			{
				anss[node[i].ind] = query(node[i].f + 1);
			}
			update(node[i].f + 1, 1);
		}
		for(int i = 1;i <= n;i ++)
			cout << anss[i] << (i == n ? "" : " ");
		cout << endl;
	}
	return 0;
}
