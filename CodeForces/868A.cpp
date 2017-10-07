//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

char ch[109][2];
char ans[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> ans;
	cin >> n;
	bool fir = false, sec = false;
	for(int i = 1;i <= n;i ++)
		cin >> ch[i],
		ch[i][1] == ans[0] ? fir = true : false,
		ch[i][0] == ans[1] ? sec = true : false,
		ch[i][0] == ans[0] && ch[i][1] == ans[1] ? fir = sec = true : false;
	(fir && sec) ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}
