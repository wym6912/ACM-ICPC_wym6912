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
const int maxn = 500009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct node
{
	int val, pos;
	friend bool operator < (const node &a, const node &b)
	{
		return a.val < b.val;
	}
}node[maxn];

int n, tree[maxn], idx[maxn];

int lowbit(int x){return x & -x;}

void update(int x, int val)
{
	for(int i = x;i <= maxn;i += lowbit(i))
		tree[i] += val;
}

ll query(int x)
{
	ll ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
		ans += tree[i];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n && n)
	{
		RESET(tree);
		//RESET(pos);
		for(int i = 1;i <= n;i ++)
			cin >> node[i].val, node[i].pos = i;
		sort(node + 1, node + 1 + n);
		for(int i = 1;i <= n;i ++)
			idx[node[i].pos] = i; //Discretization of nodes
		ll ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			update(idx[i], 1);
			ans += i - query(idx[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

