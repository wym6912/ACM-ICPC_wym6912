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
const int maxn = 100;
const int maxm = 100;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m;

char mp[maxn][maxn];
string tmp;

int dx[] = {0, 0, 1, -1, 0};
int dy[] = {0, 1, 0, 0, -1};
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int fx, fy, tx, ty;

void CantorReverse(int n, int CantorValue, int e[])
{
    int i, j, t, vst[10] = {0};
    for (i = 0; i < n; i ++)
    {
        t = CantorValue / fac[n - i - 1];
        for (j = 1;j < n;j ++)
            if (! vst[j])
            {
                if (t == 0) break;
                -- t;
            }
        e[i] = j;
        vst[j] = 1;
        CantorValue %= fac[n - i - 1];
    }
}

bool modify(int &x, int &y, int p)
{
    if(x + dx[p] >= 1 && x + dx[p] <= n && y + dy[p] >= 1 && y + dy[p] <= m)
        if(mp[x + dx[p]][y + dy[p]] != '#')
        {
            x += dx[p], y += dy[p];
            return true;
        }
    return false;
}

int find_ans(int fx, int fy, int tx, int ty)
{
    int ans = 0, tmpl = tmp.size();
    int four[5];
    for(int i = 0;i < 24;i ++)
    {
        bool ok = false;
        CantorReverse(4, i, four);
        //cout << four[0] << four[1] <<four[2] << four[3] << endl;
        int ax = fx, ay = fy;
        for(int j = 0; j < tmpl; j ++)
        {
            if(! modify(ax, ay, four[tmp[j] - '0']))break;
            if(ax == tx && ay == ty)
                ok = true;
        }
        if(ok)ans ++;
    }
    return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i ++)
        {
            cin >> tmp;
            for(int j = 0; j < m; j ++)
            {
                mp[i][j + 1] = tmp[j];
                if(mp[i][j + 1] == 'S')fx = i, fy = j + 1;
                if(mp[i][j + 1] == 'E')tx = i, ty = j + 1;
            }
        }
        cin >> tmp;
        cout << find_ans(fx, fy, tx, ty) << endl;
        /*
        for(int i = 1;i <= n; i ++)
        {
            for(int j = 1;j <= m; j ++)
                cout << mp[i][j];
            cout << endl;
        }*/
    }
	return 0;
}
