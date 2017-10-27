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
const int maxn = 1000009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll num[maxn];

int findit(int size, int x)
{
	ll ans = -1;
	int l = 1, r = size, mid = (l + r) >> 1;
	while(l < r)
	{
		if(num[mid] < x)
			l = mid + 1;
		else r = mid;
		mid = (l + r) >> 1;
	}
	return num[mid] == x ? mid : -1;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll m;
	int n;
	while(cin >> n >> m)
	{
		for(int i = 1;i <= n;i ++)
			cin >> num[i];
		sort(num + 1, num + 1 + n);
		cout << num[m] << endl; 
	}
	return 0;
}

