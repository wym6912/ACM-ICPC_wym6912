#define NOSTDCPP
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

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 500009;
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
	#define inf 0x3fffffffffffffff
	struct node {
	    ll size, mx, v, sum;
	    ll tag, rev;
	    ll f, ch[2];
	    node() {}
	    node(int val) {ch[0] = ch[1] = tag = rev = f = 0; size = 1; v = sum = mx = val;}
	}t[maxn]; 
	ll st[maxn], sz, top, root;
	ll newnode() {return top ? st[top--] : ++sz;}
	ll wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;
	 
	void rever(ll p)
	{
	    if(t[p].tag) return;
	    t[p].rev ^= 1;
	    swap(ls(p), rs(p));
	}
	 
	void paint(ll p, ll val)
	{
	    t[p].tag = val; t[p].v += val;
	    t[p].mx = val + t[p].mx;
	    //t[p].rev = 0;
	}
	 
	void pushdown(ll p)
	{
	    if(t[p].rev)
	    {
	        if(ls(p)) rever(ls(p));
	        if(rs(p)) rever(rs(p));
	        t[p].rev = 0;
	    }
	    if(t[p].tag)
	    {
	        if(ls(p)) paint(ls(p), t[p].tag);
	        if(rs(p)) paint(rs(p), t[p].tag);
	        t[p].tag = 0;
	    }
	}
	 
	void pushup(ll p)
	{
		if(! p) return ;
	    t[p].size = t[ls(p)].size + t[rs(p)].size + 1;
	    t[p].mx = t[p].v;
	    if(ls(p)) t[p].mx = min(t[p].mx, t[ls(p)].mx);
	    if(rs(p)) t[p].mx = min(t[p].mx, t[rs(p)].mx);
	}
	 
	void rotate(ll p)
	{
	    int f = t[p].f, g = t[f].f, c = wh(p);
	    if(g) t[g].ch[wh(f)] = p; t[p].f = g;
	    t[f].ch[c] = t[p].ch[c ^ 1]; if(t[f].ch[c]) t[t[f].ch[c]].f = f;
	    t[p].ch[c ^ 1] = f; t[f].f = p;
	    pushup(f); pushup(p);
	}
	 
	void Splay(ll p, ll cur)
	{
	    for(;t[p].f != cur; rotate(p))
	        if(t[t[p].f].f != cur) rotate(wh(p) == wh(t[p].f) ? t[p].f : p);
	    if(cur == 0) root = p;
	}
	
	void build_tree(ll &p, ll L, ll R, ll fa)
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
	
	int Get_max(ll x)
	{
	    pushdown(x);
	    while(t[x].ch[1])
	    {
	        x = t[x].ch[1];
	        pushdown(x);
	    }
	    return x;
	}
	 
	int Kth(ll k)
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
	 
	void Ins_from_a(ll k, ll tot) //插入的数值已经放到 a[] 数组中 
	{
	    //for(int i = 1;i <= tot; ++i) a[i] = read();
	    int f = Kth(k + 1); Splay(f, 0);
	    int p = Kth(k + 2); Splay(p, f);
	    build_tree(ls(p), 1, tot, p);
	    pushup(p); pushup(f);
	}
	 
	void erase(ll p)
	{
	    if(! p) return;
	    st[++ top] = p;
	    erase(ls(p)); erase(rs(p));
	}
	 
	void Del(ll k, ll tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    erase(ls(p)); ls(p) = 0;
	    pushup(p); pushup(f);
	}
	 
	void Mak(ll k, ll tot, ll x)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    paint(ls(p), x); 
	    pushup(p); pushup(f);
	}
	 
	void Rev(ll k, ll tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    rever(ls(p)); 
	    pushup(p); pushup(f);
	}
	 
	int Sum(ll k, ll tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    return t[ls(p)].sum;
	}
	
	int Sumall()
	{
		return t[1].sum;
	}
	
	int MaxSum(ll k, ll tot)
	{
		int f = Kth(k); Splay(f, 0);
		int p = Kth(k + tot + 1); Splay(p, f);
		return t[ls(p)].mx;
	}
	
	int MaxSumall()
	{
		return t[1].mx;
	}
	
	void SplayTree(ll n)
	{
		for(int i = 2;i <= n + 1; ++i) scan_d(a[i]); 
		a[1] = a[n + 2] = inf;
    	t[0] = node(inf); t[0].sum = t[0].size = 0;
    	build_tree(root, 1, n + 2, 0);
	}
	
	void Travel(ll x)
	{
		if(! x)return ;
		pushdown(x);
		Travel(t[x].ch[0]);
		a[tmproot ++] = t[x].v;// Check here
		Travel(t[x].ch[1]);
	}
	
	void Merge(ll root1, ll root2)
	{
	    t[root1].ch[1] = root2;
	    t[root2].f = root1;
	}
	
	void Split(ll L, ll R, ll C)
	{
		Splay(Kth(L), 0);
	    Splay(Kth(R + 2), root);
	    int root1 = t[t[root].ch[1]].ch[0]; //删除区间[L,R]
	    t[t[root].ch[1]].ch[0] = 0;
	    pushup(t[root].ch[1]);
	    pushup(root);
	    Splay(Kth(C + 1), 0); //先分裂区间C两边，插入区间[L,R]，然后合并
	    int root2 = t[root].ch[1];
	    Merge(root, root1);
	    pushup(root);
	    Splay(Get_max(root),0);
	    Merge(root, root2);
	    pushup(root);
	}
	
	#undef ls
	#undef rs
	#undef inf
};

using namespace SplayTree;

int n, m;
char str[10];

int main()
{
	ll ff, tt, dd;
	scanf("%d", &n);
	SplayTree :: SplayTree(n);
	scanf("%d", &m);
	while(m --)
	{
		scanf("%s", str);
		switch(str[0])
		{
			case 'A':
				//scan_d(ff);
				//scan_d(tt);
				//scan_d(dd);
				scanf("%lld %lld %lld", &ff, &tt, &dd);
				SplayTree :: Mak(ff, tt - ff + 1, dd);
				break;
			case 'D':
				//scan_d(ff);
				scanf("%lld", &ff);
				SplayTree :: Del(ff, 1);
				break;
			case 'I':
				//scan_d(ff);
				//scan_d(a[1]);
				scanf("%lld %lld", &ff, &a[1]);
				SplayTree :: Ins_from_a(ff, 1);
				break;
			case 'M':
				//scan_d(ff);
				//scan_d(tt);
				scanf("%lld %lld", &ff, &tt);
				out_number(SplayTree :: MaxSum(ff, tt - ff + 1));
				puts("");
				break;
			case 'R':
				switch(str[3])
				{
					case 'E':
						//scan_d(ff);
						//scan_d(tt);
						scanf("%lld %lld", &ff, &tt);
						SplayTree :: Rev(ff, tt - ff + 1);
						break;
					case 'O':
						//scan_d(ff);
						//scan_d(tt);
						//scan_d(dd);
						scanf("%lld %lld %lld", &ff, &tt, &dd);
						if(dd < 0) dd = 0;
						dd --;
						dd %= (tt - ff + 1);
						//cout << dd << endl;
						if(dd != tt - ff + 1)SplayTree :: Split(tt - dd, tt, ff - 1);
						break;
					default:
						assert(str[3] == 'E' || str[3] == 'O');
				}
				break;
			default:
				assert(false);
		}
		/*
		tmproot = 0;
		SplayTree :: Travel(root);
		for(int i = 1; i <= n + 10; i ++)
			printf("%lld%c", a[i], i == n + 10 ? '\n' : ' ');
		*/
	}
	return 0;
}
/*
10
1 4 7 8 9 6 3 2 5 10
10
REVERSE 3 8
REVOLVE 5 10 -2147483647
DELETE 1
INSERT 0 5
INSERT 10 4
REVOLVE 1 11 -1111111111
REVOLVE 1 11 5
ADD 8 11 2
MIN 1 6
MIN 8 11
*/ 
