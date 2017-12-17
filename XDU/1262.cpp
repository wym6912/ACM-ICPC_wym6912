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

char n[maxn];
ll qn[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("1.in", "r", stdin);
	scanf("%s", n);
	int nsize = strlen(n);
	RESET(qn);
	ll ans = 0;
	for(register int i = 1;i <= nsize;i ++)
	{
		if(n[i - 1] == 'Q')
			qn[i] ++;
		qn[i] += qn[i - 1];
	}
	//for(int i = 0;i <= nsize;i ++)
	//	cout << qn[i] << ' ';
	//cout << endl;
	for(register int i = 0;i < nsize;i ++)
	{
		if(n[i] == 'A')
		{
			ll preq = qn[i + 1] - qn[0], lastq = qn[nsize] - qn[i];
			ans += lastq * preq;
	//		cout << lastq << ' ' << preq << endl;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

