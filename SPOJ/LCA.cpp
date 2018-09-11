#define NOSTDCPP
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
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 3000 + 10;
const int maxm = 1000 + 10;
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

inline void out_number(ll x)
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

int n;

struct eddy
{
	int to, next;
}edg_2[maxn];
int fir[maxm], eddy_tot;
int deep[maxm], ffather[maxm], son[maxm], size[maxm], head[maxm], out[maxm], ans[maxm];

void addedge(int f, int t)
{
	edg_2[++ eddy_tot].to = t;
	edg_2[eddy_tot].next = fir[f];
	fir[f] = eddy_tot;
}

void dfs1(int u, int pre, int d)
{
	deep[u] = d;
	ffather[u] = pre;
	son[u] = 0;
	size[u] = 1;
	for(int i = fir[u]; i; i = edg_2[i].next)
	{
		if(edg_2[i].to != pre)
		{
			dfs1(edg_2[i].to, u, d + 1);
			size[u] += size[edg_2[i].to];
			if(! son[u] || size[edg_2[i].to] > size[son[u]])
				son[u] = edg_2[i].to;
		}
	}
}

void getpos(int u, int sp)
{
	head[u] = sp;
	if(son[u]) getpos(son[u], sp);
	for(int i = fir[u]; i; i = edg_2[i].next)
	{
		if(edg_2[i].to != son[u] && edg_2[i].to != ffather[u])
			getpos(edg_2[i].to, edg_2[i].to); 
	}
}

int LCA(int u, int v)
{
    int f1 = head[u], f2 = head[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        u = ffather[f1]; f1 = head[u];
    }
    if(u == v) return u;
    if(deep[u] > deep[v]) swap(u, v);
    return u;
}

int main()
{
	int root, cnt, to;
	int T;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		scanf("%d", &n);
		eddy_tot = 0;
		RESET(fir);
		RESET(ans);
		RESET(out);
		for(int i = 1; i <= n; ++ i)
		{
			root = i;
			scanf("%d", &cnt);
			for(int j = 1; j <= cnt; ++ j)
			{
				scanf("%d", &to);
				addedge(root, to);
				addedge(to, root);
				++ out[to];
			}
		}
		for(int i = 1; i <= n; ++ i)
		{
			if(! out[i])
			{
				dfs1(i, 0, 0);
				getpos(i, i);
			}
		}
		printf("Case %d:\n", Casen);
		int q;
		scanf("%d", &q);
		while(q --)
		{
			scanf("%d %d", &root, &to);
			printf("%d\n", LCA(root, to));
		}
	}
	return 0;
}
