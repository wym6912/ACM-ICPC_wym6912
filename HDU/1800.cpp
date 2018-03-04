//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
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

# ifdef Linux_System
# define getchar getchar_unlocked
# define putchar putchar_unlocked
# endif

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
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 3009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
string str;
vector <string> vss;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n)
	{
		vss.clear();
		int j;
		for(int i = 1; i <= n; i ++)
		{
			cin >> str;
			int strsize = str.size();
			for(j = 0; j < strsize; j ++)
				if(str[j] != '0')
					break;
			str = str.substr(j, strsize - j);
			vss.pb(str);
		}
		sort(vss.begin(), vss.end());
		int tmp = 1, ans = 1;
		for(vector <string> :: iterator it2 = vss.begin() + 1; it2 != vss.end(); it2 ++)
			if(* (it2) == *(it2 - 1))
				tmp ++;
			else ans = max(tmp, ans), tmp = 1;
		ans = max(ans, tmp);
		cout << ans << endl;
	}
	return 0;
}

