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
# define pb push_back
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll myrand(ll mod){return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod;}

ll data[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, tmp, tmp2;
	int i;
	while(cin >> a >> b)
	{
		i = 0;
		tmp = a;
		while(tmp)
		{
			i ++;
			data[i] = tmp % b;
			tmp /= b;
			tmp = -tmp;
		}
		tmp2 = 0;
		for(int j = 1; j <= i; j ++) //from 0
		{
			if(data[j] < 0)
			{
				data[j + 1] -= (j % 2) ? 1 : -1;
				data[j] = data[j] + b;
			}
			if(data[j] >= b)
			{
				data[j + 1] -= (j % 2) ? 1 : -1;
				data[j] -= b;
			}
		}
		if(data[i + 1] < 0)
		{
			i ++;
			data[i + 1] ++;
			data[i] += b;
		}
		if(data[i + 1])cout << i + 1 << endl;
		else cout << i << endl;
		for(int j = 1; j <= i + 1; j ++)
		{
			if(j == i + 1 && data[j] == 0)break;
			cout << data[j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

