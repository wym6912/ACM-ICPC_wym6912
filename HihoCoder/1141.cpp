//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <complex>
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
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
ll m;
ll ans;

ll data[maxn], tmp[maxn];

ll __merge__(int l, int mid, int r)
{
	ll ans = 0; 
	int p1 = l, p2 = mid + 1;
	for(int i = l;i <= r;i ++)
	{
		if(p1 <= mid && (p2 > r || data[p1] <= data[p2]))
			tmp[i] = data[p1], p1 ++;
		else tmp[i] = data[p2], p2 ++, ans += (mid - p1 + 1);
	}
	for(int i = l;i <= r;i ++)data[i] = tmp[i];
	return ans;
}

ll erfen(int l, int r)
{
	ll ans = 0;
	int mid = (l + r) >> 1;
	if(l < r)
	{
		ans += erfen(l, mid);
		ans += erfen(mid + 1, r);
	}
	ans += __merge__(l, mid, r);
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n)
	{
		ans = 0;
		for(int i = 1;i <= n;i ++)
			cin >> data[i];
		ans = erfen(1, n);
		cout << ans << endl;
	}
	return 0;
}
