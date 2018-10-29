//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
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
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define pos __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 320;
const ll inf = 1e18;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll myrand(ll mod){return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod;}

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
#ifdef Cpp11
template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
}
#define cin.tie(0); cin.tie(nullptr);
#define cout.tie(0); cout.tie(nullptr);
#endif
inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n')ch = getchar();
	return true;
}

template <class T>
inline void out_number(T x)
{
	if(x < 0)
	{
		putchar('-');
		out_number(- x);
		return ;
	}
	if(x > 9)out_number(x / 10);
	putchar(x % 10 + '0');
}

int n, m, q, data[maxn], L[maxn], R[maxn], block, pos[maxn], 
	tmp[maxn], ff[maxm][maxm], gg[maxm][maxn];
//ff 从 x 块到 y 块的值 
//gg 每一块元素的出现次数 

inline void init_block(int x) //处理从第 x 块到后面所有块的值 
{
	int sum = 0, blk = x;
	RESET(tmp);
	for(int i = L[x]; i <= n; ++ i) 
	{
		++ tmp[data[i]];
		if(tmp[data[i]] & 1)
		{
			if(tmp[data[i]] != 1) -- sum;
		}
		else ++ sum;
		if(R[blk] == i)
		{
			ff[x][blk] = sum;
			++ blk;
		}
	}
	for(int i = 1; i <= m; ++ i) gg[x][i] = gg[x - 1][i];
	for(int i = L[x]; i <= R[x]; ++ i) ++ gg[x][data[i]];
}

inline void init()
{
	block = (int)sqrt(1.0 * n);
	for(int i = 1; i <= block; ++ i)//算出每个点在块上的位置 
	{
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	if(R[block] < n) ++ block, L[block] = R[block - 1] + 1, R[block] = n; //特殊处理 
	for(int i = 1; i <= block; ++ i)
	{
		init_block(i);
		for(int j = L[i]; j <= R[i]; ++ j)
			pos[j] = i;
	}
}

inline void doit(int l, int r, int &ans)
{
	for(int i = l; i <= r; ++ i)
	{
		++ tmp[data[i]];
		if(tmp[data[i]] & 1)
		{
			if(tmp[data[i]] != 1) -- ans;
		}
		else ++ ans;
	}
}

inline int query(int l, int r)
{
	int p = pos[l], q = pos[r], ans = 0;
	if(p == q) //两点在一块上 
	{
		for(int i = l; i <= r; ++ i) tmp[data[i]] = 0;
		doit(l, r, ans);
		return ans;
	}
	else //两点在两块 
	{
		if(q - p > 1) ans = ff[p + 1][q - 1];
		for(int i = l; i <= R[p]; ++ i) tmp[data[i]] = gg[q - 1][data[i]] - gg[p][data[i]];
		for(int i = L[q]; i <= r; ++ i) tmp[data[i]] = gg[q - 1][data[i]] - gg[p][data[i]];
		doit(l, R[p], ans);
		doit(L[q], r, ans);
		return ans;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++ i) scanf("%d", data + i);
	init();
	int l, r, lst = 0;
	while(q --)
	{
		scanf("%d %d", &l, &r);
		l = (l + lst) % n + 1, r = (r + lst) % n + 1;
		if(l > r) swap(l, r);
		printf("%d\n", lst = query(l, r));
	}
	return 0;
}
/*
5 3 5
1 2 2 3 1
0 4
1 2
2 2
2 3
3 5
*/

