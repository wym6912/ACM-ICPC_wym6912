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
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll a, b, c;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> a >> b >> c)
	{
		bool flag = false;
		for(ll i = 0;i <= a / b; i ++)
			if((a - b * i) % c == 0)
			{
				flag = true;
				cout << "YES\n" << i << ' ' << (a - b * i) / c << endl;
				break;
			}
		if(! flag)cout << "NO" << endl;
	}
	return 0;
}

