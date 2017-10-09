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

int lowbit(int x){return x & -x;}

int n;

struct node
{
	int cnt;
	ll num;
}tree[maxn];

void update(int t, int v, int cnt)
{
	for(int i = t;i <= n;i += lowbit(i))
	{
		tree[i].num += v;
		tree[i].cnt += cnt;
	}
}

int query_cnt(int t)
{
	int ans = 0;
	for(int i = t;i > 0;i -= lowbit(i))
	{
		ans += tree[i].cnt;
	}
	return ans;
}

ll query_sum(int t)
{
	ll ans = 0;
	for(int i = t;i > 0;i -= lowbit(i))
	{
		ans += tree[i].num;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a;
	while(cin >> n)
	{
		ll ans = 0;
		RESET(tree);
		for(int i = 1;i <= n;i ++)
		{
			int a;
			cin >> a;
			update(a, a, 1);
			ll k1 = i - query_cnt(a);
			if(k1 != 0)
			{
				ll k2 = query_sum(n) - query_sum(a);
				ans += k1 * a + k2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
