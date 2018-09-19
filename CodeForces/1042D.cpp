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
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;
const ll inf = 1e16;

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

#define ls(p) t[p].ch[0]
#define rs(p) t[p].ch[1]

struct node 
{
    int size;
	ll v;
    int f, ch[2];
    node() {}
    node(ll val, int fa) {ch[0] = ch[1] = 0; f = fa; size = 1; v = val;}
}t[maxn];
int st[maxn], sz, top, root;
int newnode() {return top ? st[top--] : ++sz;}
int wh(int p) {return t[t[p].f].ch[1] == p;}

void pushup(int p)
{
    t[p].size = t[ls(p)].size + t[rs(p)].size + 1;
}

void rotate(int p)
{
    int f = t[p].f, g = t[f].f, c = wh(p);
    if(g) t[g].ch[wh(f)] = p; t[p].f = g;
    t[f].ch[c] = t[p].ch[c ^ 1]; if(t[f].ch[c]) t[t[f].ch[c]].f = f;
    t[p].ch[c ^ 1] = f; t[f].f = p;
    pushup(f); pushup(p);
}

void Splay(int p, int cur)
{
    for(;t[p].f != cur; rotate(p))
        if(t[t[p].f].f != cur) rotate(wh(p) == wh(t[p].f) ? t[p].f : p);
    if(cur == 0) root = p;
}

void init()
{
	sz = 0;
	top = 0;
	t[0].v = -inf;
	root = newnode();
	t[root] = node(-inf, 0);
	rs(root) = newnode();
	t[rs(root)] = node(inf, root);
	pushup(root);
}

void insert(int &p, ll val, int fa)
{
	if(p == 0) {p = newnode(); t[p] = node(val, fa); return ;}
	if(t[p].v > val) insert(ls(p), val, p);
	else insert(rs(p), val, p);
	pushup(p);
}

int kth_place;
ll qd;
void next_val(int p, ll val)
{
	if(! p) return;
	if(t[p].v <= val) next_val(rs(p), val);
	else 
	{
		if(t[p].v - val <= qd - val) kth_place = p, qd = t[p].v;
		next_val(ls(p), val);
	}
	Splay(p, 0);
}

#undef ls
#undef rs

ll sum[maxn], A[maxn], v;

int main()
{
	int n;
	scanf("%d %I64d", &n, &v);
	sum[0] = 0;
	for(int i = 1; i <= n; ++ i) scanf("%I64d", A + i), sum[i] = sum[i - 1] + A[i];
	init();
	ll ans = 0;
	insert(root, 0, 0);
	for(int i = 1; i <= n; ++ i)
	{
		Splay(i, 0);
		kth_place = -1;
		qd = inf;
		next_val(root, sum[i] - v);
		//printf("%d %I64d\n", kth_place, qd);
		if(!~kth_place) continue;
		Splay(kth_place, 0);
		ans += t[t[kth_place].ch[1]].size;
		insert(root, sum[i], 0);
		Splay(sz, 0);
	}
	printf("%I64d\n", ans);
	return 0;
}

