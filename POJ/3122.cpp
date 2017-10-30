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
typedef long double ld;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = 3.14159265359;
const double eps = 1e-7;

int n, mm;
double data[maxn];

int f(double x)
{
	if(fabs(x) < eps)
		return 10002;
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		ans += (int)(data[i] * data[i] / x);
	}
	return ans;
}

void o(double l)
{
	cout << "f(" << l << ") = " << f(l) << endl;
}

double erfen(double m)
{
	double l = 0.0, r = m * m, mid = (l + r) / 2.;
	while(fabs(l - r) > eps)
	{
		int can = f(mid);
		if(can > mm)
			l = mid;
		else r = mid;
		mid = (l + r) / 2.;
	//	o(l);
	//	o(r);
	}
	return mid * pi;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		double m = 0.0;
		scanf("%d%d", &n, &mm);
		for(int i = 1;i <= n;i ++)
			scanf("%lf", &data[i]), m = max(m, data[i]);
		printf("%.4f\n", erfen(m));
	}
	return 0;
}

