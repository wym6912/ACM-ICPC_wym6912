#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

ll data[maxn], merg[maxn], tmp2[maxn];

int n, q;

ll selectsort(int f, int t, int k)
{
	if(f == t)return merg[f];
	int l = f, r = t;
	ll pivot = merg[l];
	while(l < r)
	{
		while(l < r && merg[r] >= pivot)r --;
		if(l < r)merg[l ++] = merg[r];
		while(l < r && merg[l] <= pivot)l ++;
		if(l < r)merg[r --] = merg[l];
	}
	merg[l] = pivot;
	int tmp = l - f + 1;
	if(tmp == k)return merg[l];
	else if(tmp > k)return selectsort(f, f + tmp - 1, k);
	else return selectsort(f + tmp + 1, t, k - tmp);
}

ll ans(int f, int t, int k)
{
	int cnt = 0;
	for(int i = f, j = 1; i <= t; i ++, j ++)
		merg[j] = data[i], cnt ++;
	return selectsort(1, cnt, k);
}
/*
ll __merge__(int l, int mid, int r)
{
	ll ans = 0; 
	int p1 = l, p2 = mid + 1;
	for(int i = l;i <= r;i ++)
	{
		if(p1 <= mid && (p2 > r || tmp2[p1] <= tmp2[p2]))
			merg[i] = tmp2[p1], p1 ++;
		else merg[i] = tmp2[p2], p2 ++, ans += (mid - p1 + 1);
	}
	for(int i = l;i <= r;i ++)tmp2[i] = merg[i];
	return ans;
}

ll erfen(int l, int r)
{
	ll ans = 0;
	int mid = (l + r) >> 1;
	if(l < r)
	{
		ans += erfen(l, mid);
		ans += erfen(mid + 1, r);
	}
	ans += __merge__(l, mid, r);
	return ans;
}

ll merge(int a, int b, int c)
{
	RESET(merg);
	for(int i = a;i <= b;i ++)
		tmp2[i] = data[i];
	erfen(a, b);
	return tmp2[a + c - 1];
}
*/
template <class T>
inline bool scan_d(T & ret)
{
	char c;
	int sgn;
	if(c = getchar(), c == EOF)return false;
	while(c != '-' && (c < '0' || c > '9'))c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while(c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + (c - '0');
	ret *= sgn;
	return true;
}

inline void out(ll x)
{
	if(x < 0)
	{
		putchar('-');
		out(- x);
		return ;
	}
	if(x > 9)out (x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	int q;
	scan_d(n);
	scan_d(q);
	{
		for(int i = 1;i <= n;i ++)
			//scanf("%lld", &data[i]);
			scan_d(data[i]);
		while(q --)
		{
			int a, b, c;
			//scanf("%d%d%d", &a, &b, &c);
			scan_d(a);
			scan_d(b);
			scan_d(c);
			//printf("%d %d %d %d\n", a, b, c, q);
			//printf("%lld\n", merge(a, b, c));
			out(ans(a, b, c));
			puts("");
		}
	}
	return 0;
}

