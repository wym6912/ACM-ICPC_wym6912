#define NOSTDCPP
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
#include <cassert>

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
ll data[maxn], delta[maxn];
ll midd[maxn];

ll f(ll x)
{
	ll ans = 0;
	for(int i = 1;i < n;i ++)
	{
		ans += data + n + 1 - upper_bound(data + i + 1, data + 1 + n, data[i] + x);
		//cout << data[i] << data[lower_bound(data + 1, data + 1 + n, data[i] + x) - data] << endl;
		//assert(ans > 0);
		//cout << (*(data + i + 1) == data[i + 1]) << endl;
	}
	//cout << "The number " << ans << " means the division of " << x << " is " << ans << " pairs." << endl;
	return ans;
}

ll erfen(ll x, ll y)
{
	//RESET(midd);
	ll l = x, r = y, mid = (x + y) >> 1;
	//cout << l << ' ' << r << endl;
	ll cmpp = ((n * (n - 1) / 2) & 1) ? ((n * (n - 1) / 2) >> 1) : (n * (n - 1) / 4);
	while(l + 1 < r)
	{
		ll fx = f(mid);
		if(fx <= cmpp)
			r = mid;
		else l = mid;
		//cout << l << ' ' << r << endl;
		mid = (l + r) >> 1;
	}
	//cout << endl;
	//for(int i = x;i <= y;i ++)
	//	cout << f(i) << endl;
	return r;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(~ scanf("%lld", &n))
	{
		for(int i = 1;i <= n;i ++)
			//cin >> data[i];
			scanf("%lld", &data[i]);
		int pl = 1;
		sort(data + 1, data + 1 + n);
		//for(int i = 1;i < n;i ++)
		//	for(int j = n;j >= i + 1;j --)
		//		delta[pl ++] = data[j] - data[i];
		//sort(delta + 1, delta + pl);
		//for(int i = 1;i < pl;i ++)
		//	cout << delta[i] << ' ';
		//cout << endl;
		//cout << erfen(0, data[n] - data[1]) << endl;
		printf("%lld\n", erfen(0, data[n] - data[1]));
	}
	return 0;
}

