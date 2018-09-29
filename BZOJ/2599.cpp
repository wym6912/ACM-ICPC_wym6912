//#define NOSTDCPP
//#define Cpp11
#define Linux_System
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
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;
	
const int MOD = 1e9 + 7;
const int maxn = 500009;
const int maxm = maxn << 1;
const int inf = 1e9;
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
	
int n, m, A[maxn], hsh[maxn];
int ans, offset[maxn], delta[maxn];
//offset[]: 当前节点相对于当前重链的链底的带权距离
//delta []: 当前节点相对于当前重链的链底的距离
	
struct edge
{
	int to, next, val;
}edg[maxm];
int fir[maxn], edg_cnt;
void addedge(int f, int t, int val)
{
	edg[++ edg_cnt].to = t;
	edg[edg_cnt].next  = fir[f];
	edg[edg_cnt].val   = val;
	fir[f] = edg_cnt;
}
	
int father[maxn], size[maxn], son[maxn], deep[maxn], fae[maxn];
int seg[maxn], id[maxn], ed[maxn], tot;
ll sm[maxn];
bool vis[maxn];
void dfs1(int u, int fa)
{
	seg[id[u] = ++ tot] = u;
	father[u] = fa;
	size[u] = 1;
	son[u] = 0; 
	for(int i = fir[u], v; i; i = edg[i].next)
	{
		v = edg[i].to;		
		if(v != fa)
		{
			deep[v] = deep[u] + 1;
			fae[v] = edg[i].val;
			sm[v] = sm[u] + fae[v];
			dfs1(v, u);
			size[u] += size[v];
			if(! son[u] || size[son[u]] < size[v])
				son[u] = v;
		}
	}
	ed[u] = tot;
}
	
map <ll, int> mp;

void dfs2(int u, bool preferred_son)
{
	if(! son[u]) 
	{
		offset[u] = delta[u] = 0;
		return ;
	}
	//先遍历轻儿子 
	for(int i = fir[u], v; i; i = edg[i].next)
	{
		v = edg[i].to;
		if(v != father[u] && v != son[u])
			dfs2(v, false);
	}
	//再遍历重儿子 
	if(son[u]) dfs2(son[u], true), vis[son[u]] = true;
	int &dlt = delta[u], &ofs = offset[u];
	ofs = offset[son[u]] + fae[son[u]];
	dlt = delta[son[u]] + 1;
	if(mp.count(mp[fae[son[u]] - offset[u]]))
		mp[fae[son[u]] - offset[u]] = 1 - dlt;
	else mp[fae[son[u]] - offset[u]] = 1 - dlt;
	register ll tmp;
	for(register int i = fir[u], v; i; i = edg[i].next)
	{
		v = edg[i].to;
		if(v != father[u] && v != son[u])
		{
			for(register int j = id[v]; j <= ed[v]; ++ j)
			{
				tmp = m - sm[seg[j]] + sm[u];
				if(tmp > 0 && mp.count(tmp - ofs))
					ans = min(ans, mp[tmp - ofs] + deep[seg[j]] - deep[u] + dlt);
			}
			for(register int j = id[v]; j <= ed[v]; ++ j)
			{
				tmp = sm[seg[j]] - sm[u];
				if(tmp <= m)
				{
					if(mp.count(tmp - ofs))
						mp[tmp - ofs] = min(mp[tmp - ofs], deep[seg[j]] - deep[u] - dlt);
					else 
						mp[tmp - ofs] = deep[seg[j]] - deep[u] - dlt;
				}
			}
		}
	}
	if(mp.count(m - ofs))
		ans = min(ans, mp[m - ofs] + dlt);
	//如果是轻儿子，要擦除结果 
	if(! preferred_son)
		mp.clear();
}
	
int main()
{
	edg_cnt = 0;
	//scanf("%d %d", &n, &m);
	scan_d(n);
	scan_d(m);
	for(register int i = 1, f, t, val; i < n; ++ i)
	{
		//scanf("%d %d %d", &f, &t, &val);
		scan_d(f);
		scan_d(t);
		scan_d(val);
		++ f, ++ t;
		addedge(f, t, val);
		addedge(t, f, val);
	}
	dfs1(1, -1);
	ans = inf;
	dfs2(1, false);
	printf("%d\n", ans == inf ? -1 : ans);
	return 0;
}
/*
4 3
0 1 1
1 2 2
1 3 4
*/
