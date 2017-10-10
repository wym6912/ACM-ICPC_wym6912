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
#include <cassert>

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
const int maxn = 1009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll matrix[maxn][maxn];

int lowbit(int x){return x & -x;}

void update(int a, int b, int n)
{
	for(int i = a;i < maxn;i += lowbit(i))
		for(int j = b;j < maxn;j += lowbit(j))
			matrix[i][j] += n;
}

ll query(int x, int y)
{
	ll ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
		for(int j = y;j > 0;j -= lowbit(j))
			ans += matrix[i][j];
	return ans & 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, n, q, a, b, c, d;
	char quq;
	cin >> T;
	while(T --)
	{
		RESET(matrix);
		cin >> n >> q;
		while(q --)
		{
			cin >> quq;
			if(quq == 'C')
			{
				cin >> a >> b >> c >> d;
				update(a, b,  1);
				update(c + 1, d + 1, 1);
				update(a, d + 1, -1);
				update(c + 1, b, -1);
			}
			else if(quq == 'Q')
			{
				cin >> a >> b;
				cout << query(a, b) << endl;
			}
			else assert(false);
		}
		if(T)cout << endl;
	}
	return 0;
}
