/**************************************************************
    Problem: 3884
    User: wym6912
    Language: C++
    Result: Accepted
    Time:184 ms
    Memory:1292 kb
****************************************************************/
 
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
 
#define RESET(_) memset(_, 0, sizeof(_))
#define RESET_(_, val) memset(_, val, sizeof(_))
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
 
const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;
 
int phi(int x)
{
    if(x == 1)return 1;
    else
    {
        {
            int phix = x;
            int y = (int)(sqrt(x));
            int i = 2;
            while(i <= y)
            {
                if(x % i == 0)
                {
                    phix -= phix / i;
                    do{x /= i;}while(x % i == 0);
                }
                i ++;
                y = (int)(sqrt(x));
            }
            if(x != 1)phix -= phix / x;
            return phix;
        }
    }
}
 
ll pow(ll a, ll b, ll p)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans % p;
}
 
ll ans(ll n)
{
    if(n == 1)return 0;
    ll phix = phi(n);
    return pow(2, ans(phix) + phix, n);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    cin >> T;
    while(T --)
    {
        cin >> n;
        cout << ans(n) << endl;
    }
    return 0;
}
