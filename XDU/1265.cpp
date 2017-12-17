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

const int MOD = 1002;
const int maxn = 1009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll data[maxn];

ll T, a, b, c, n, k;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T --)
	{
		RESET(data);
		cin >> a >> b >> c;
		cin >> n >> k;
		int tmp = a;
		ll pl = 0;
		data[a] = 1;
		int maxt = a;
		for(register int i = 1;i < n;i ++)
		{
			data[tmp = (tmp * b + c) % MOD] ++;
			maxt = max(maxt, tmp);
		}
		if(n == 0 || k == 0 || k > n)
		{
			cout << 0 << endl;
		}
		for(register int i = min(maxt, 1001);i >= 0;i --)
		{
			pl += data[i];
			if(pl >= k)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

