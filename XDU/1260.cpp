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
const int maxn = 1009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;

struct score
{
	string sub;
	double nu, sc;
}data[maxn];

double sss[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string tmp;
	double tmp1, tmp2;
	while(cin >> n)
	{
		//cin >> tmp;
		int num = 0;
		bool find;
		for(int i = 1;i <= n; i ++)
		{
			find = false;
			cin >> tmp >> tmp1 >> tmp2;
			//cout << tmp << tmp1 << tmp2 << endl;
			for(int j = 1;j <= num;j ++)
				if(data[j].sub == tmp)
				{
					data[j].sc = max(data[j].sc, tmp2);
					find = true;
				}
			if(! find)
			{
				num ++;
				data[num].sub = tmp;
				data[num].nu = tmp1;
				data[num].sc = tmp2;
			}
		}
		double avg1 = 0.0, avg2 = 0.0, sc_d = 0.0;
		for(int i = 1;i <= num;i ++)
		{
			avg1 += data[i].sc * data[i].nu;
			sc_d += data[i].nu;
			if(data[i].sc >= 90)
			{
				avg2 += 4.0 * data[i].nu;
			}
			else if(data[i].sc >= 85)
			{
				avg2 += 3.7 * data[i].nu;
			}
			else if(data[i].sc >= 82)
			{
				avg2 += 3.3 * data[i].nu;
			}
			else if(data[i].sc >= 78)
			{
				avg2 += 3.0 * data[i].nu;
			}
			else if(data[i].sc >= 75)
			{
				avg2 += 2.7 * data[i].nu;
			}
			else if(data[i].sc >= 72)
			{
				avg2 += 2.3 * data[i].nu;
			}
			else if(data[i].sc >= 69)
			{
				avg2 += 2.0 * data[i].nu;
			}
			else if(data[i].sc >= 66)
			{
				avg2 += 1.7 * data[i].nu;
			}
			else if(data[i].sc >= 63)
			{
				avg2 += 1.5 * data[i].nu;
			}
			else if(data[i].sc >= 60)
			{
				avg2 += data[i].nu;
			}
		}
		cout << fixed << setprecision(1) << avg1 / sc_d << endl 
		 << fixed << setprecision(2) << avg2 / sc_d << endl;
	}
	return 0;
}

