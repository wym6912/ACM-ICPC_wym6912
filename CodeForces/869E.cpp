//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <pair>

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

const ll hashn = 37;
const int maxn = 2509;
const int maxm = 300009;
//const double pi = acos(-1.0);
const double eps = 1e-6;

ll mm[maxn][maxn];

map < pair < pii, pii >, ll > m;

int lowbit(int t){return t & -t;}

int update(int x, int y, ll num)
{
    for(int i = x;i <= maxn;i += lowbit(i))
        for(int j = y;j <= maxn;j += lowbit(j))
            mm[i][j] += num;
}

ll query(int x, int y)
{
    ll sum = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        for(int j = y;j > 0;j -= lowbit(j))
            sum += mm[i][j];
    return sum;
}

int main()
{
	int n, mmm, t, x1, x2, y1, y2, q;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll h = 1;
	cin >> n >> mmm >> q;
	while(q --)
	{
		cin >> t >> x1 >> y1 >> x2 >> y2;
		if(t == 1)
		{
			h *= hashn;
			m[mp(mp(x1, y1), mp(x2, y2))] = h;
			update(x1, y1, h);
			update(x2 + 1, y2 + 1, h);
			//one place means [a, b) , but we should update [a, b]
			update(x1, y2 + 1, -h);
			update(x2 + 1, y1, -h);
		}
		if(t == 2)
		{
			ll tmp = m[mp(mp(x1, y1), mp(x2, y2))];
			m[mp(mp(x1, y1), mp(x2, y2))] = 0;
			update(x1, y1, -tmp);
			update(x2 + 1, y2 + 1, -tmp);
			update(x1, y2 + 1, tmp);
			update(x2 + 1, y1, tmp);
		}
		if(t == 3)
		{
			query(x1, y1) == query(x2, y2) ? cout << "Yes" << endl : cout << "No" << endl;
		}
	}
	return 0;
}

