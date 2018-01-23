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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 1009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
double m;
double data[maxn], place[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(~ scanf("%d %lf", &n, &m))
    {
        for(int i = 1; i <= n; i ++)
            scanf("%lf", &data[i]);
        printf("%lf", m);
        for(int i = 1; i <= n; i ++)
            place[i] = m;
        for(int i = 2; i <= n; i ++)
        {
            for(int j = i - 1; j >= 1; j --)
                if((data[i] - data[j]) * (data[i] - data[j]) <= m * m * 4.)
                {
                    //cout << data[i] << ' ' << data[j] << ' ' << i << ' ' << j << endl;
                    place[i] = max(place[j] + sqrt(m * m * 4. - (data[i] - data[j]) * (data[i] - data[j])), place[i]);
                }
        }
        for(int i = 2; i <= n; i ++)
            printf(" %.10lf", place[i]);
        printf("\n");
    }
	return 0;
}
