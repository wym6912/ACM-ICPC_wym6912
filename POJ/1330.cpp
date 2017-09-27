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
const int maxn = 10010;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int rmq[2 * maxn];

struct ST
{
	int mm[2 * maxn];
	int dp[2 * maxn][20];
	void init(int n)
	{
		mm[0] = -1;
		for(int i = 1;i <= n;i ++)
		{
			mm[i] = ((i & (i - 1)) == 0 ? mm[i - 1] + 1 : mm[i - 1]);
			dp[i][0] = i;
		}
		for(int j = 1;j <= mm[n];j ++)
			for(int i = 1; i + (1 << j) - 1 <= n;i ++)
				dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ?
				  dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
	}
	int query(int a, int b)
	{
		if(a > b)swap(a, b);
		int k = mm[b - a + 1];
		return rmq[dp[a][k]] <= rmq[dp[b - (1 << k) + 1][k]] ?
			dp[a][k] : dp[b - (1 << k) + 1][k];
	}
};

struct Edge
{
	int to, next;
}edge[2 * maxn];

int tot, head[maxn];

int F[maxn * 2]; // dfs sequence
int P[maxn]; //p[i] = i in F for the first time
int cnt;
ST st;

void init()
{
	tot = 0;
	RESET_(head, -1);
}

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

void dfs(int u, int pre, int dep)
{
	F[++ cnt] = u;
	rmq[cnt] = dep;
	P[u] = cnt;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if(v == pre)continue;
		dfs(v, u, dep + 1);
		F[++ cnt] = u;
		rmq[cnt] = dep;
	}
}

void LCA_init(int root, int node_num)
{
	cnt = 0;
	dfs(root, root, 0);
	st.init(2 * node_num - 1);
}

int query_LCA(int u, int v)
{
	return F[st.query(P[u], P[v])];
}

bool flag[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u, v, T, N, Case = 0;
	cin >> T;
	while(T --)
	{
  		cin >> N;
		init();
		RESET(flag);
		for(int i = 1;i < N;i ++)
        {
            cin >> u >> v;
            addedge(u, v);
            addedge(v, u);
            flag[v] = true;
        }
        int root;
        for(int i = 1;i <= N;i ++)
            if(! flag[i])
            {
                root = i;
                break;
            }
        LCA_init(root, N);
        cin >> u >> v;
        cout << query_LCA(u, v) << endl;
        }
	return 0;
}
/*
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5
*/
/*
4
3
*/
