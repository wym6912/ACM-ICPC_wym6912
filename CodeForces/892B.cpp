//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
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
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int x[maxn], maxp, n, rep;
bool isdead[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep = n; // remaining people
	for(int i = n;i >= 1;i --)
		cin >> x[i];
	//memcpy(y + 1, x + 1, n * sizeof(int));
	//if(maxp == 0)
	//{
	//	cout << rep << endl;
	//	return 0;
	//}
	int kp = 0;
	for(int i = 1;i <= n;i ++)
	{
		kp --;
		if(kp >= 0)rep --;
		kp = max(kp, x[i]);
	}
	//for(int i = n;i >= 1;i --)
	//	if(isdead[i])
	//		cout << -1 << ' ';
	//	else cout << x[i] << ' ';
	//cout << endl;
	cout << rep << endl;
	return 0;
}

