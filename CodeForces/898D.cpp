//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 1000009;
const int maxm = 1000009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, data[maxn], m, k;

bool isin[maxm];

priority_queue <int> qqqmin;
priority_queue <int, vector <int>, greater <int> > qqqmax;

queue <int> qqq;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	register int j;
	register ll maxx, minx;
	while(cin >> n >> m >> k)
	{
		while(! qqq.empty())qqq.pop();
		ll ans = 0;
		for(int i = 1;i <= n;i ++)
			cin >> data[i];
		sort(data + 1, data + 1 + n);
		for(register int i = 1;i <= n;i ++)
		{
			while(! qqq.empty() && data[i] - qqq.front() >= m)qqq.pop();
			if(qqq.size() == k - 1)ans ++;
			else qqq.push(data[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

