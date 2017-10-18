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

ll dd[100];

ll digits(ll x)
{
	ll ans = 0;
	while(x)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	//freopen("876C.txt", "w", stdout);
	while(cin >> n)
	//for(n = 1;n <= 10000;n ++)
	{
		//cout << "Number" << n << endl;
		int ans = 0;
		for(ll i = n - 1;i >= n - 1009;i --)
			if(digits(i) + i == n)
				ans ++, dd[ans] = i;
		if(ans)
		{
			cout << ans << endl;
			for(int i = ans;i >= 1;i --)
				cout << dd[i] << ' ';
			cout << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
