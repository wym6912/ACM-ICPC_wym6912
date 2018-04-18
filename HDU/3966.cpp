//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
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
const int maxn = 70009;
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
int father[maxn], head[maxn], len[maxn], data[maxn], datar[maxn];
bool vis[maxn];
int l, r, ans, cnt = 0;
int N, nedge;

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
/*
struct node
{
	int sum, lazy;
}tree[maxm << 1];

void pushup(int p, int l, int r)
{
	tree[p].sum = 0;
	if(l < r)
	{
		tree[p].sum = tree[DXA(p)].sum + tree[DXB(p)].sum;
	}
	tree[p].sum += tree[p].lazy * (r - l + 1);
}

void pre(int l, int r, int p)
{
	tree[p].sum = 0;
	tree[p].lazy = 0;
	if(l == r)
	{
		tree[p].lazy = tree[p].sum = datar[l];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int l, int r, int nl, int nr, int p, int d)
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy += d;
		pushup(p, l, r);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, DXA(p), d);
	if(mid < r) update(l, r, mid + 1, nr, DXB(p), d);
	pushup(p, nl, nr);
}

int query(int nl, int nr, int p, int tags, int x)
{
	if(nl == nr)
		return tree[p].sum + tags * (nr - nl + 1);
	int mid = midf(nl, nr);
	if(x <= mid)return query(nl, mid, DXA(p), tags + tree[p].lazy, x);
	else return query(mid + 1, nr, DXB(p), tags + tree[p].lazy, x);
}
线段树end
*/
/*树状数组begin*/

int lowbit(int i){return i & -i;}
int tree[maxm];
void update(int x, int p)
{
	for(int i = x; i <= N + 1; i += lowbit(i))
		tree[i] += p;
	return;
}
int query(int x)
{
	int ans = 0;
	for(int i = x; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

/*树状数组end*/
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

void __update__(int f, int t, int x)
{
	while(head[belong[f]] != head[belong[t]]) //往一条链上靠
	{
		if(dep[head[belong[f]]] < dep[head[belong[t]]])swap(f, t);
		//update(id[head[belong[f]]], id[f], 1, N, 1, x);
		update(id[f] + 1, -x);
		update(id[head[belong[f]]], x);
		f = father[head[belong[f]]];
	}
	if(id[f] > id[t])swap(f, t);
	//update(id[f], id[t], 1, N, 1, x);
	update(id[t] + 1, -x);
	update(id[f], x);
}

int main()
{
	int f, t, q, aa, bb, cc;
	char str;
	while(scanf("\n%d %*d %d", &N, &q) == 2)
	{
		nedge = 0;
		RESET(info);
		RESET(belong);
		RESET(idx);
		RESET(id);
		RESET(size);
		RESET(vis);
		cnt = 0;
		RESET(tree);
		for(int i = 1; i <= N; i ++)
			scan_d(data[i]);
		for(int i = 1; i < N; i ++)
		{
			//scanf("%d %d", &f, &t);
			scan_d(f);
			scan_d(t);
			insert(f, t);
			insert(t, f);
		}
		split();
		pre_way();
		//for(int i = 1; i <= N; i ++)
		//	cout << data[i] << ' ' << id[i] << ' ' << datar[i] << endl;
		for(int i = 1; i <= N; i ++)
			update(id[i] + 1, -data[i]), update(id[i], data[i]);
		while(q --)
		{
			scanf("\n%c", &str);
			switch(str)
			{
				case 'D':
					//scanf("%d %d %d", &aa, &bb, &cc);
					scan_d(aa);
					scan_d(bb);
					scan_d(cc);
					__update__(aa, bb, -cc);
					break;
				case 'I':
					//scanf("%d %d %d", &aa, &bb, &cc);
					scan_d(aa);
					scan_d(bb);
					scan_d(cc);
					__update__(aa, bb, cc);
					break;
				case 'Q':
					//scanf("%d", &f);
					scan_d(f);
					//printf("%d\n", query(1, N, 1, 0, id[f]));
					out_number(query(id[f]));
					puts("");
				default:
					assert(str == 'Q' || str == 'D' || str == 'I');
			}
		}
	}
	return 0;
}
/*
3 2 5
1 2 3
2 1
2 3
I 1 3 5
Q 2
D 1 2 2
Q 1
Q 3
3 2 5
1 2 3
1 2
1 3
I 1 3 5
Q 2
D 1 2 2
Q 1
Q 3
*/

