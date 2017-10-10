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
const int maxn = 1039;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll data[maxn][maxn];
int n;

int lowbit(int x){return x & -x;}

void update(int x, int y, int val)
{
	for(int i = x;i > 0; i -= lowbit(i))
		for(int j = y;j > 0;j -= lowbit(j))
			data[i][j] += val;
}

ll query(int x, int y)
{
	ll ans = 0;
	for(int i = x;i < n;i += lowbit(i))
		for(int j = y;j < n;j += lowbit(j))
			ans += data[i][j];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int I, a, b, c, d;
	ll ans;
	while(cin >> I && I != 3)
	{
		if(! I)
		{
			RESET(data);
			cin >> a;
			n = ++ a;
		}
		else if(I == 1)
		{
			cin >> a >> b >> c;
			a ++;b ++;
			update(a, b, c);
		}
		else if(I == 2)
		{
			cin >> a >> b >> c >> d;
			//for(int i = 1;i <= n;i ++, cout << endl)
			//	for(int j = 1;j <= n;j ++)
			//		cout << data[i][j] << " ";
			a ++;b ++;c ++;d ++;
			ans = 0;
			ans += query(a, b);
			ans += query(c + 1, d + 1);
			ans -= query(a, d + 1);
			ans -= query(c + 1, b);
			cout << ans << endl;
		}
		else assert(false);
	}
	return 0;
}
