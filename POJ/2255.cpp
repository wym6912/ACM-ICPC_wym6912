#define NOSTDCPP
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

string s1, s2;

void work(int l1, int r1, int l2, int r2)
{
	int m = s2.find(s1[l1]);
	if (m == -1) return;
	if (m > l2) work(l1 + 1, l1 + m - l2, l2, m - 1);
	if (m < r2) work(l1 + m - l2 + 1, r1, m + 1, r2);
	cout << s1[l1];
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> s1 >> s2)
	{
		s1=' '+s1;
    	s2=' '+s2;
		work(1, s1.size(), 1, s2.size());
		cout << endl;
	}
	return 0;
}

