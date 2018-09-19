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

ll a[maxn];

namespace SplayTree
{
	#define ls(p) t[p].ch[0]
	#define rs(p) t[p].ch[1]
	#define inf 0x3f3f3f3f3f3f3f3f
	struct node {
	    int size;
		ll sum, mx, lm, rm, v;
	    int tag;
	    int f, ch[2];
	    node() {}
	    node(ll val) {ch[0] = ch[1] = tag = f = 0; size = 1; v = sum = mx = lm = rm = val;}
	}t[maxn];
	int st[maxn], sz, top, root;
	int newnode() {return top ? st[top--] : ++sz;}
	int wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;

	void paint(int p, ll val) //如果是区间加一个数，用下面的模板
	{
	    t[p].tag = 1; t[p].v = val;
	    t[p].sum = val * t[p].size;
	    t[p].lm = t[p].rm = t[p].mx = max(val, t[p].sum);
	}

	void pushdown(int p)
	{
	    if(t[p].tag)
	    {
	        if(ls(p)) paint(ls(p), t[p].v);
	        if(rs(p)) paint(rs(p), t[p].v);
	        t[p].tag = 0;
	    }
	}

	void pushup(int p)
	{
	    t[p].size = t[ls(p)].size + t[rs(p)].size + 1;
	    t[p].sum = t[ls(p)].sum + t[rs(p)].sum + t[p].v;
	    t[p].mx = max(max(t[ls(p)].mx, t[rs(p)].mx), max(0ll, t[ls(p)].rm) + t[p].v + max(0ll, t[rs(p)].lm));
	    t[p].lm = max(t[ls(p)].lm, t[ls(p)].sum + t[p].v + max(0ll, t[rs(p)].lm));
	    t[p].rm = max(t[rs(p)].rm, t[rs(p)].sum + t[p].v + max(0ll, t[ls(p)].rm));
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

	void build_tree(int &p, int L, int R, int fa)
	{
	    int mid = midf(L, R);
	    p = newnode();
		t[p] = node(a[mid]);
		t[p].f = fa;
	    if(L == R) return;
	    if(L < mid) build_tree(ls(p), L, mid - 1, p);
	    if(mid < R) build_tree(rs(p), mid + 1, R, p);
	    pushup(p);
	}

	int Get_max(int x)
	{
	    pushdown(x);
	    while(t[x].ch[1])
	    {
	        x = t[x].ch[1];
	        pushdown(x);
	    }
	    return x;
	}

	int Kth(int k)
	{
	    int p = root, lsize = 0;
	    while(p)
	    {
	        pushdown(p);
	        int cur = lsize + t[ls(p)].size;
	        if(k == cur + 1) return p;
	        if(k <= cur) p = ls(p);
	        else {
	            lsize = cur + 1;
	            p = rs(p);
	        }
	    }
	    return -1;
	}

	void Ins_from_a(int k, int tot) //插入的数值已经放到 a[] 数组中
	{
	    int f = Kth(k + 1); Splay(f, 0);
	    int p = Kth(k + 2); Splay(p, f);
	    build_tree(ls(p), 1, tot, p);
	    pushup(p); pushup(f);
	}

	void erase(int p)
	{
	    if(! p) return;
	    st[++ top] = p;
	    erase(ls(p)); erase(rs(p));
	}

	void Del(int k, int tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    erase(ls(p)); ls(p) = 0;
	    pushup(p); pushup(f);
	}

	void Mak(int k, int tot, int x)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    paint(ls(p), x);
	    pushup(p); pushup(f);
	}

	ll MaxSum(int k, int tot)
	{
		int f = Kth(k); Splay(f, 0);
		int p = Kth(k + tot + 1); Splay(p, f);
		return t[ls(p)].mx;
	}

	int MaxSumall()
	{
		return t[1].mx;
	}

	void SplayTree(int n)
	{
		for(int i = 2;i <= n + 1; ++i) scanf("%lld", a + i);
		a[1] = a[n + 2] = -inf;
		t[0] = node(-inf); t[0].sum = t[0].size = 0;
		build_tree(root, 1, n + 2, 0);
	}

	void Travel(int x)
	{
		if(! x)return ;
		pushdown(x);
		Travel(t[x].ch[0]);
		a[tmproot ++] = t[x].v;// Check here
		Travel(t[x].ch[1]);
	}

	#undef ls
	#undef rs
	#undef inf
};

using namespace SplayTree;

int main()
{
	int n, x, y;
	char ch;
	scanf("%d", &n);
	SplayTree :: SplayTree(n);
	scanf("%d", &n);
	while(n --)
	{
		scanf("\n%c %d", &ch, &x);
		switch(ch)
		{
			case 'I':
				scanf("%lld", &a[1]);
				-- x;
				SplayTree :: Ins_from_a(x, 1);
				break;
			case 'D':
				SplayTree :: Del(x, 1);
				break;
			case 'R':
				scanf("%d", &y);
				SplayTree :: Mak(x, 1, y);
				break;
			case 'Q':
				scanf("%d", &y);
				printf("%lld\n", SplayTree :: MaxSum(x, y - x + 1));
				break;
			default:
				assert(ch == 'I' || ch == 'D' || ch == 'R' || ch == 'Q');
		}
		/*
		tmproot = 0;
		RESET(a);
		Travel(root);
		for(int i = 1; i <= 10; ++ i) cout << a[i] << ' '; cout << endl;
		*/
	}
	return 0;
}
/*
5
-1 -2 -3 -4 -5
1
Q 1 5
*/
