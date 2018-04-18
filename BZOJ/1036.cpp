//#define NOSTDCPP
//#define Cpp11
#define Linux_System
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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100005;
const int maxm = maxn << 1;
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

int v[maxm], prevv[maxm];
int info[maxn], q[maxn], idx[maxn], dep[maxn], size[maxn], belong[maxn];
int father[maxn], head[maxn], len[maxn];
bool vis[maxn];
int l, r, ans, cnt = 0;
int N, nedge = 0;

inline void insert(int x, int y)
{
	++ nedge;
	v[nedge] = y;
	prevv[nedge] = info[x];
	info[x] = nedge;
}
/*树链剖分begin*/
void split()
{
	RESET_(dep, -1);
	l = 0;
	dep[q[r = 1] = 1] = 0; //点从1开始编号，假设根节点是1
	father[1] = -1;
	while(l < r)
	{
		int x = q[++ l];
		vis[x] = false;
		for(int y = info[x]; y; y = prevv[y])
			if(dep[v[y]] == -1)
			{
				dep[q[++ r] = v[y]] = dep[x] + 1;
				father[v[y]] = x;
			}
	}
	for(int i = N; i; i --)
	{
		int x = q[i], p = -1;
		size[x] = 1;
		for(int y = info[x]; y; y = prevv[y])
			if(vis[v[y]])
			{
				size[x] += size[v[y]];
				if(p == -1 || size[v[y]] > size[p])
					p = v[y];
			}
		if(p == -1)
		{
			idx[x] = len[++ cnt] = 1;
			belong[head[cnt] = x] = cnt;
		}
		else
		{
			idx[x] = ++ len[belong[x] = belong[p]];
			head[belong[x]] = x;
		}
		vis[x] = true;
	}
}
/*树链剖分end*/
/*线段树begin*/
struct node
{
	int sum, maxd;
}tree[maxm << 1];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].maxd = max(tree[DXA(p)].maxd, tree[DXB(p)].maxd);
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
}

void update(int l, int r, int p, int d, int pl)
{
	if(l == r)
	{
		//cout << l << ' ' << r << ' ' << d << endl;
		tree[p].maxd = tree[p].sum = d;
		return ;
	}
	int mid = midf(l, r);
	if(pl <= mid)update(l, mid, DXA(p), d, pl);
	else update(mid + 1, r, DXB(p), d, pl);
	pushup(p, l, r);
}

bool ismax;

int query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		return ismax ? tree[p].maxd : tree[p].sum;
	}
	int mid = midf(nl, nr);
	int ans_max = -0x7fffffff, ans_sum = 0;
	if(l <= mid)
		ismax ? ans_max = max(query(l, r, nl, mid, DXA(p)), ans_max) :
		ans_sum += query(l, r, nl, mid, DXA(p));
	if(mid < r)
		ismax ? ans_max = max(query(l, r, mid + 1, nr, DXB(p)), ans_max) :
		ans_sum += query(l, r, mid + 1, nr, DXB(p));
	return ismax ? ans_max : ans_sum;
}
/*线段树end*/
int id[maxn];
void pre_way()
{
	int me, siz, idn = 1;
	for(int i = 1; i <= cnt; i ++)
	{
		me = 0;
		siz = len[i];
		for(int j = 1; j <= N; j ++)
			if(belong[j] == i && idx[j] == 1)
			{
				me = j;
				break;
			}
		id[me] = idn + siz - 1;
		//cout << me << endl;
		while(-- siz)
		{
			me = father[me];
			if(! id[me])id[me] = idn + siz - 1;
			//cout << me << endl;
		}
		idn += len[i];
	}
	//cout << "ID: ";
	//for(int i = 1; i <= N; i ++)
	//	cout << id[i] << ' ';
	//cout << endl;
}

void query_sum(int f, int t)
{
	int ans = 0;
	ismax = false;
	while(head[belong[f]] != head[belong[t]]) //往一条链上靠
	{
		if(dep[head[belong[f]]] < dep[head[belong[t]]])swap(f, t);
		ans += query(id[head[belong[f]]], id[f], 1, N, 1);
		f = father[head[belong[f]]];
	}
	if(id[f] > id[t])swap(f, t);
	ans += query(id[f], id[t], 1, N, 1);
	out_number(ans);
	puts("");
}

void query_max(int f, int t)
{
	int ans = -0x7fffffff;
	ismax = true;
	while(head[belong[f]] != head[belong[t]]) //往一条链上靠
	{
		if(dep[head[belong[f]]] < dep[head[belong[t]]])swap(f, t);
		ans = max(query(id[head[belong[f]]], id[f], 1, N, 1), ans);
		f = father[head[belong[f]]];
	}
	if(id[f] > id[t])swap(f, t);
	ans = max(query(id[f], id[t], 1, N, 1), ans);
	out_number(ans);
	puts("");
}

int main()
{
	int f, t, q;
	char str[10];
	//freopen("count.in", "r", stdin);
	//freopen("count.out", "w", stdout);
	scan_d(N);
	for(int i = 1; i < N; i ++)
	{
		scan_d(f);
		scan_d(t);
		if(f > t)swap(f, t);
		insert(f, t);
		insert(t, f);
	}
	split();
	pre_way();
	for(int i = 1; i <= N; i ++)
	{
		scan_d(f);
		update(1, N, 1, f, id[i]);
		//cout << id[i] << ' ' << query(id[i], id[i], 1, N, 1) << endl;
	}
	scan_d(q);
	while(q --)
	{
		scanf("\n%s %d %d", str, &f, &t);
		switch(str[0])
		{
			case 'C':
				update(1, N, 1, t, id[f]);
				break;
			case 'Q':
				switch(str[1])
				{
					case 'S':
						query_sum(f, t);
						break;
					case 'M':
						query_max(f, t);
						break;
					default:
						assert(str[0] == 'Q' && (str[1] == 'S' || str[1] == 'M'));
				}
				break;
			default:
				assert(str[0] == 'Q' || str[0] == 'C');
		}
	}
	return 0;
}
/*
12
1 2
2 3
2 4
4 5
3 6
3 7
4 8
7 9
5 10
8 11
3 12
23399 14858 25504 28559 4183 18754 17571 14270 26214 28234 4763 1746
5
CHANGE 9 15423
CHANGE 11 -24476
QMAX 8 4
CHANGE 11 19742
QMAX 3 11
*/
