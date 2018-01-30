#define NOSTDCPP
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
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 50009;
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

typedef struct 
{
	int l, r;
	ll cnt, tag;
}node;

struct ppp
{
	ll l, r;
}data[maxm];

node tree[maxn];
int n, key;
map <ll, int> mppp;
bool visited[maxn];

void predata();

void pushdown(int p)
{
	if(tree[p].tag)
	{
		tree[DXA(p)].tag = tree[DXB(p)].tag = tree[p].tag;
		tree[p].tag = 0;
	}
}

void pushup(int p, int l, int r)
{
	
}

void update(int l, int r, int nl, int nr, ll q, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].tag = q;
	}
	else
	{
		pushdown(p); //一定要把标记下传！！！ 
		int mid = midf(nl, nr);
		if(l <= mid)
			update(l, r, nl, mid, q, DXA(p));
		if(mid < r)
			update(l, r, mid + 1, nr, q, DXB(p));
	}
	pushup(p, nl, nr);
}

void query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		visited[tree[p].tag] = true;
		return ;
	}
	else 
	{
		pushdown(p);
		int mid = midf(nl, nr);
		if(l <= mid)	
			query(l, r, nl, mid, DXA(p));
		if(mid < r)
			query(l, r, mid + 1, nr, DXB(p));
	}
}

void doit()
{
	int rmax = key + 1;
	for(int i = 1; i <= n; i ++)
	{
		//assert(mppp[data[i].l] <= mppp[data[i].r]);
		update(mppp[data[i].l], mppp[data[i].r], 1, rmax, i, 1);
	}
	for(int i = 1; i <= rmax; i ++)
		query(i, i, 1, rmax, 1);
	ll ans = 0;
	//for(int i = 1; i <= (rmax << 2); i ++)
	//	if(tree[i].tag)
	//	{
	//		if(! visited[tree[i].tag])
	//			visited[tree[i].tag] = true, 
	//			ans ++;
	//	}
	for(int i = 1; i <= (rmax); i ++)
		if(visited[i])
			ans ++;
	out_number(ans);
	puts("");
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	scan_d(T);
	while(T --)
	{
		predata();
		doit();
	}
	return 0;
}

void predata()
{
	RESET(tree);
	RESET(visited);
	mppp.clear();
	priority_queue <ll, vi, greater <ll> > pq;
	while(! pq.empty())pq.pop();
	key = 2; // Segment_Tree is from 2, when < data_min is 1
	ll tmp;
	scan_d(n);
	for(int i = 1; i <= n; i ++)
	{
		scan_d(data[i].l);
		scan_d(data[i].r);
		pq.push(data[i].l);
		pq.push(data[i].r);
	}
	while(! pq.empty())
	{
		tmp = pq.top();
		pq.pop();
		if(mppp.find(tmp) == mppp.end())
		{
			mppp[tmp] = key;
			if(! pq.empty() && pq.top() - tmp != 1)key ++;
			key ++;
		}
	}
	return ;
}

/*
4
5
1 4
2 6
8 10
3 4
7 10
3
1 10
1 3
3 10
3
5 6
4 5
6 8
5
1 4
2 6
8 10
3 4
7 10
*/
