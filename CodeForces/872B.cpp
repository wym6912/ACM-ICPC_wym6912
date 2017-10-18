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

int n, k;
ll data[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> k)
	{
		cin >> data[1];
		ll minx = data[1], maxx = data[1];
		for(int i = 2;i <= n;i ++)
			cin >> data[i], minx = min(minx, data[i]), maxx = max(maxx, data[i]);
		if(k == 1)cout << minx << endl;
		else if(k >= 3) cout << maxx << endl;
		else
		{
			vi p;
			for(int i = 1;i <= n; i ++)
				if(data[i] == maxx)
					p.push_back(i);
			int psize = p.size();
			if(p[0] == 1 || p[psize - 1] == n)
				cout << maxx << endl;
			else
			{
				//ll ans = -1000000009, sz;
/*
				for(int i = 0;i < psize;i ++)
				{
					sz = data[p[i]];
					cout << sz << endl;
					for(int )
					ans = max(sz, ans);
				}

				bool isu = false;
				for(int i = 1;i <= n; i ++)
				{
					if(data[i] == maxx)
						isu = true;
					else sz = min(sz, data[i]);
					if(isu)
					{
						 ans = max(sz, ans);
						 isu = false;
						 sz = maxx;
					}
				}
				ans = max(sz, ans);
*/
				ll ans = data[1], min1 = data[1], min2 = data[n];
				for(int i = 1;i <= n;i ++)
					min1 = min(min1, data[i]), ans = max(min1, ans);
				for(int i = n;i >= 1;i --)
					min2 = min(min2, data[i]), ans = max(ans, min2);
				cout << ans << endl;
			}
		}
	}
	return 0;
}
