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


ll myrand(ll mod)
{
	return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod;
}

ll fib[30];

int n;


int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fib[1] = fib[2] = 1;
	for(int i = 3; i <= 28; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    while(cin >> n)
    {
        int j = 2;
        for(int i = 1; i <= n; i ++)
            if(fib[j] == i)
            {
                cout << 'O';
                j ++;
            }
            else cout << 'o';
        cout << endl;
    }
    return 0;
}
