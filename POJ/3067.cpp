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
const int maxn = 1000109;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct node
{
	int f, t;
	friend bool operator < (const node &a, const node &b)
	{
		return a.f == b.f ? a.t < b.t : a.f < b.f;
	}
}node[maxn];

ll tree[maxn];

int lowbit(int x){return x & (-x);}

void update(int i)
{
    while(i > 0){
        tree[i] += 1;
        i -= lowbit(i);
    }
}

ll query(int i)
{
    ll ans = 0;
    while(i <= maxn - 1){
        ans += tree[i];
        i += lowbit(i);
    }
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, p, T;
	scanf("%d", &T);//cin >> T;
	for(int Case = 1; Case <= T;Case ++)
	{
		RESET(tree);
		scanf("%d%d%d",&n,&m,&p);//cin >> n >> m >> p;
		for(int i = 1;i <= p;i ++)
			scanf("%d%d",&node[i].f, &node[i].t);//cin >> node[i].f >> node[i].t;
		sort(node + 1, node + 1 + p);
		ll ans = 0;
		for(int i = 1;i <= p;i ++)
		{
			ans += query(node[i].t + 1);
			update(node[i].t);
		}
		printf("Test case %d: %lld\n", Case, ans);
		//cout << "Test case " << Case << ": " << ans << endl;
	}
	return 0;
}

