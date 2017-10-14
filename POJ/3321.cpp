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
const int maxn = 2000001;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
int idx;
int to[maxn], Next[maxn], head[maxn],
	q[maxn], fa[maxn], size[maxn],
	dfs[maxn], zz[maxn], re[maxn];

void add(int x, int y)
{
	to[++ idx] = y;
	Next[idx] = head[x];
	head[x] = idx;
	to[++ idx] = x;
	Next[idx] = head[y];
	head[y] = idx;
	return ;
}

void bfs()
{
	int l = 0, r = 0;
	q[r ++] = 1;
	while(l != r)
	{
		int x = q[l ++];
		size[x] = 1;
		for(int i = head[x];i ;i = Next[i])
			if(to[i] != fa[x])
			{
				fa[to[i]] = x;
				q[r ++] = to[i];
			}
	}
	for(int i = n - 1;i >= 0;i --)
		size[fa[q[i]]] += size[q[i]];
	return ;
}

ll trees[maxn];
bool change[maxn];

int lowbit(int i){return i & -i;}

void update(int x, ll val)
{
	for(int i = x;i <= n;i += lowbit(i))
		trees[i] += val;
}

ll query(int x)
{
	ll ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
		ans += trees[i];
	return ans;
}

void print(int x[])
{
	for(int i = 1;i <= n;i ++)
		cout << x[i] << ' ';
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, qqq;
	char ch;
	while(~ scanf("%d", &n))//while(cin >> n)
	{
		RESET(head);
		RESET_(change, true);
		RESET(trees);
		RESET(q);
		for(int i = 1;i < n;i ++)
		{
			//cin >> a >> b;
			scanf("%d%d", &a, &b);
			add(a, b);
		}
		bfs();
		dfs[1] = 1;
		zz[1] = 2;
		int last;
		for(int i = 1;i < n;i ++)
		{
			if(fa[q[i]] != fa[q[i - 1]])
				last = zz[fa[q[i]]];
			else last += size[q[i - 1]];
			dfs[last] = q[i];
			zz[q[i]] = last + 1;
		}
		for(int i = 1;i <= n;i ++)
			update(i, 1),re[dfs[i]] = i;
		//print(dfs);
		//print(size);
		//cin >> qqq;
		scanf("%d\n", &qqq);
		while(qqq --)
		{
			//cin >> ch >> a;
			scanf("%c%d\n", &ch, &a);
			if(ch == 'Q')
				//cout << query(re[a] + size[a] - 1) - query(re[a] - 1) << endl;
				printf("%d\n", query(re[a] + size[a] - 1) - query(re[a] - 1));
			if(ch == 'C')
			{
				if(change[re[a]])
					update(re[a], -1);
				else update(re[a], 1);
				change[re[a]] = !change[re[a]];
			}
		}
	}
	return 0;
}
