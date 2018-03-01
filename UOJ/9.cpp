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
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

const int ten[4] = {1, 10, 100, 1000};
const int maxl = 100;
struct BigNumber
{
	int d[maxl];
	BigNumber(string s)
	{
		int len = s.size();
		d[0] = (len - 1) / 4 + 1;
		int i, j, k;
		for(i = 1; i < maxl; ++ i)d[i] = 0;
		for(i = len - 1; ~i; -- i)
		{
			j = (len - i - 1) / 4 + 1;
			k = (len - i - 1) % 4;
			d[j] += ten[k] * (s[i] - '0');
		}
		while(d[0] > 1 && d[d[0]] == 0) -- d[0];
	}
	BigNumber()
	{
		*this = BigNumber(string("0"));
	}
	string toString()
	{
		string s("");
		int i, j, temp;
		for(i = 3; i >= 1; -- i)if(d[d[0]] >= ten[i])break;
		temp = d[d[0]];
		for(j = i; ~j; -- j)
		{
			s += (char)(temp / ten[j] + '0');
			temp %= ten[j];
		}
		for(i = d[0] - 1; i; -- i)
		{
			temp = d[i];
			for(j = 3; ~j; --j)
			{
				s += (char)(temp / ten[j] + '0');
				temp %= ten[j];
			}
		}
		return s;
	}
};

bool operator < (const BigNumber &a, const BigNumber &b)
{
	if(a.d[0] != b.d[0])return a.d[0] < b.d[0];
	int i;
	for(i = a.d[0]; i; -- i)if(a.d[i] != b.d[i])return a.d[i] < b.d[i];
	return false;
}

string data[10001], tmp;
BigNumber num[10001];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> data[i];
	int datasize = data[1].size(), data0size;
	for(int i = 0; i < datasize; ++ i)
		if(! (data[1][i] >= '0' && data[1][i] <= '9'))
			data[0] += data[1][i];
		else break;
	data0size = data[0].size();
	for(int i = 1; i <= n; ++ i)
	{
		tmp = "";
		for(int j = data0size; data[i][j] != '.'; ++ j)
			tmp += data[i][j];
		num[i] = BigNumber(tmp);
	}
	sort(num + 1, num + 1 + n);
	for(int i = 1; i <= n; ++ i)
	{
		cout << data[0] << num[i].toString() << ".in\n";
	}
	return 0;
}

