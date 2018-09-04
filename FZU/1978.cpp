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
const int maxn = 100009;
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

char a[maxn]; //从 1 开始 

namespace SplayTree
{
	#define ls(p) t[p].ch[0]
	#define rs(p) t[p].ch[1]
	#define inf 0x3f3f3f3f
	
	struct node {
	    int size, sum, lm[2], rm[2], v;
	    int tag, rev, swp;
	    int f, ch[2];
	    node() {}
	    node(char val)
		{
			ch[0] = ch[1] = tag = rev = f = 0; 
			swp = size = 1; 
			v = sum = (val == '(' ? 1 : -1);
			lm[0] = rm[0] = min((val == '(' ? 1 : -1), 0);
			lm[1] = rm[1] = max((val == '(' ? 1 : -1), 0);
		}
	}t[maxn]; 
	int st[maxn], sz, top, root;
	int newnode() {return top ? st[top--] : ++sz;}
	int wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;
	 
	void swaptag(int p)
	{
		if(t[p].tag) t[p].tag *= -1;
		else t[p].swp *= -1;
		t[p].v *= -1;
		t[p].sum *= -1;
		//最小值和最大值交换 
		swap(t[p].lm[0], t[p].lm[1]);
		swap(t[p].rm[0], t[p].rm[1]);
		t[p].lm[0] *= -1; t[p].lm[1] *= -1;
		t[p].rm[0] *= -1; t[p].rm[1] *= -1;
	}
	 
	void rever(int p)
	{
	    if(t[p].tag) return;
	    t[p].rev ^= 1;
	    swap(ls(p), rs(p));
		swap(t[p].lm[0], t[p].rm[0]);
		swap(t[p].lm[1], t[p].rm[1]);
	}
	 
	void paint(int p, int val)
	{
	    t[p].tag = val; t[p].v = val;
	    t[p].sum = val * t[p].size;
	    t[p].lm[0] = t[p].rm[0] = min(0, t[p].sum);
	    t[p].lm[1] = t[p].rm[1] = max(0, t[p].sum);
	    t[p].rev = 0;
	    t[p].swp = 1;
	}
	 
	void pushdown(int p)
	{
		if(t[p].tag)
	    {
	        if(ls(p)) paint(ls(p), t[p].tag);
	        if(rs(p)) paint(rs(p), t[p].tag);
	        t[p].tag = 0;
	    }
	    if(t[p].swp != 1)
	    {
	        if(ls(p)) swaptag(ls(p));
	        if(rs(p)) swaptag(rs(p));
	        t[p].swp = 1;
	    }
	    if(t[p].rev)
	    {
	        if(ls(p)) rever(ls(p));
	        if(rs(p)) rever(rs(p));
	        t[p].rev = 0;
	    }
	}
	 
	void pushup(int p)
	{
	    t[p].size = t[ls(p)].size + t[rs(p)].size + 1;
	    t[p].sum = t[ls(p)].sum + t[rs(p)].sum + t[p].v;
	    //t[p].mx = max(max(t[ls(p)].mx, t[rs(p)].mx), max(0, t[ls(p)].rm[0]) + t[p].v + max(0, t[rs(p)].lm[0]));
	    t[p].lm[0] = min(t[ls(p)].lm[0], t[ls(p)].sum + t[p].v + min(0, t[rs(p)].lm[0]));
	    t[p].rm[0] = min(t[rs(p)].rm[0], t[rs(p)].sum + t[p].v + min(0, t[ls(p)].rm[0]));
	    t[p].lm[1] = max(t[ls(p)].lm[1], t[ls(p)].sum + t[p].v + max(0, t[rs(p)].lm[1]));
	    t[p].rm[1] = max(t[rs(p)].rm[1], t[rs(p)].sum + t[p].v + max(0, t[ls(p)].rm[1]));
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
	    //for(int i = 1;i <= tot; ++i) a[i] = read();
	    int f = Kth(k + 1); Splay(f, 0);
	    int p = Kth(k + 2); Splay(p, f);
	    build_tree(ls(p), 1, tot, p);
	    pushup(p); pushup(f);
	}
	 
	void Mak(int k, int tot, int x)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    paint(ls(p), x); 
	    pushup(p); pushup(f);
	}
	 
	void Rev(int k, int tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    rever(ls(p)); 
	    pushup(p); pushup(f);
	}
	
	void Swp(int k, int tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    swaptag(ls(p)); 
	    pushup(p); pushup(f);
	}
	
	void SplayTree(int n)
	{
		//for(int i = 2;i <= n + 1; ++i) scan_d(a[i]); 
		//a[1] = a[n + 2] = -inf;
		root = sz = 0;
		scanf("%s", a + 1);
		a[0] = '(';
		a[n + 1] = ')';
    	t[0] = node(')'); 
		t[0].sum = t[0].size = t[0].v = t[0].lm[0] = t[0].lm[1] = t[0].rm[0] = t[0].rm[1] = 0;
    	build_tree(root, 0, n + 1, 0);
	}
	
	void Travel(int x)
	{
		if(! x)return ;
		pushdown(x);
		Travel(t[x].ch[0]);
		a[tmproot ++] = t[x].v == 1 ? '(' : ')';// Check here
		Travel(t[x].ch[1]);
	}
	
	void Merge(int root1, int root2)
	{
	    t[root1].ch[1] = root2;
	    t[root2].f = root1;
	}
	
	int Query(int L, int R)
	{
		Splay(Kth(L), 0);
	    Splay(Kth(R + 2), root);
	    int x = t[ls(rs(root))].lm[0], y = t[ls(rs(root))].sum;
	    y -= x;
	    x = abs(x) + 1;
	    y = abs(y) + 1;
	    return (x >> 1) + (y >> 1);
	}
	
	#undef ls
	#undef rs
	#undef inf
};

using namespace SplayTree;

int main()
{
	int T;
	int n, m, l, r;
	char str[10];
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		scanf("%d %d", &n, &m);
		SplayTree :: SplayTree(n);
		printf("Case %d:\n", Casen);
		/*
		tmproot = 0;
		RESET(a);
		Travel(root);
		puts(a);
		*/
		while(m --)
		{
			scanf("%s", str);
			switch(str[0])
			{
				case 'I':
					scanf("%d %d", &l, &r);
					SplayTree :: Swp(l, r - l + 1);
					break;
				case 'Q':
					scanf("%d %d", &l, &r);
					printf("%d\n", SplayTree :: Query(l, r));
					break;
				case 'R':
					scanf("%d %d %c", &l, &r, &str[8]);
					SplayTree :: Mak(l, r - l + 1, str[8] == '(' ? 1 : -1);
					break;
				case 'S':
					scanf("%d %d", &l, &r);
					SplayTree :: Rev(l, r - l + 1);
					break;
				default:
					assert(false);
			}
			/*
			tmproot = 0;
			RESET(a);
			Travel(root);
			puts(a);
			*/
		}
	}
	return 0;
}

