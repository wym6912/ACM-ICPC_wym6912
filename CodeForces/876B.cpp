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

struct numm
{
	ll data, modd;
}num[maxn];

bool comp(const numm &a, const numm &b)
{
	return a.modd < b.modd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, k;
	while(cin >> n >> k >> m)
	{
		for(int i = 1;i <= n;i ++)
			cin >> num[i].data, num[i].modd = num[i].data % m;
		sort(num + 1, num + n + 1, comp);
		ll mod2 = num[1].modd;
		int x = 1, p = 1; // x is number, p is position
		for(int i = 2;i <= n && x != k;i ++)
		{
			if(mod2 == num[i].modd)
				x ++;
			else x = 1, mod2 = num[i].modd, p = i;
		}
	//	for(int i = 1;i <= n;i ++)
	//		cout << num[i].modd << ' ' ;
	//	cout << endl << x << ' ' << p << num[p].data << endl;
		if(x >= k)
		{
			cout << "Yes" << endl;
			for(int i = p;i <= p + k - 1;i ++)
				cout << num[i].data << ' ';
			cout << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}
