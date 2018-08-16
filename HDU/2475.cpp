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

# pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 100009;
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

vi graph[maxn], seq;

int a[maxn], dfs_l[maxn], dfs_r[maxn];

namespace SplayTree
{
	#define ls(p) t[p].ch[0]
	#define rs(p) t[p].ch[1]
	#define inf 0x3f3f3f3f
	struct node {
	    int size, v;
	    int f, ch[2];
	    node() {}
	    node(int val) {ch[0] = ch[1] = f = 0; size = 1; v = val;}
	}t[maxn]; 
	int st[maxn], sz, top, root;
	int newnode() {return top ? st[top--] : ++sz;}
	int wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;
	 
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
	
	void build_tree(int &p, int L, int R, int fa)
	{
	    int mid = midf(L, R);
	    p = newnode(); 
		t[p] = node(seq[mid]); 
		t[p].f = fa;
		if(seq[mid] < 0) dfs_r[- seq[mid]] = p; //注意数值的关系 
		else dfs_l[seq[mid]] = p;
	    if(L == R) return;
	    if(L < mid) build_tree(ls(p), L, mid - 1, p);
	    if(mid < R) build_tree(rs(p), mid + 1, R, p); 
	    pushup(p);
	}
	
	int Get_min_place(int x) //查找最小值的位置 
	{
	    while(ls(x))
	    {
	        x = ls(x);
	    }
	    return x;
	}
	
	int Get_max_place(int x) //查找最大值的位置 
	{
	    while(rs(x))
	    {
	        x = rs(x);
	    }
	    return x;
	}
	 
	int Query(int k)
	{
	    Splay(dfs_l[k], 0);
	    return t[Get_min_place(dfs_l[k])].v;
	}
	 
	void Travel(int x)
	{
		if(! x)return ;
		Travel(t[x].ch[0]);
		a[tmproot ++] = t[x].v;// Check here
		Travel(t[x].ch[1]);
	}
	
	void SplayTree()
	{
		root = 0;
		sz = 0;
	}
	
	void Split(int aa, int b)
	{
		if(aa == b) return ; //本来就在一起 
		int lll = dfs_l[aa], rrr = dfs_r[aa];
		Splay(lll, 0);
		Splay(rrr, lll);
		int xx = ls(lll), yy = rs(rrr), z = 0;
		z = Get_max_place(xx);
		ls(lll) = 0;
		rs(rrr) = 0;
		t[xx].f = t[yy].f = 0;
		if(z) rs(z) = yy;
		t[yy].f = z;
		if(b == 0) return ; //如果 b 是根的话，就不用做后面的操作了 
		if(Query(b) == aa)  //如果原来就在一个集合 
		{
			//撤回操作 
			ls(lll) = xx;
			rs(rrr) = yy;
			t[xx].f = lll;
			t[yy].f = rrr;
			rs(z) = 0;
			return ;
		}
		int l = dfs_l[b], r; //插入到新的位置 
		Splay(l, 0);
		r = Get_min_place(rs(l));
		Splay(r, l);
		ls(r) = lll;
		t[lll].f = r;
	}
	
	#undef ls
	#undef rs
	#undef inf
};

using namespace SplayTree;


void dfs(int x)
{
	seq.push_back(x);
	for(int i = 0; i < graph[x].size(); i ++)
		dfs(graph[x][i]);
	seq.push_back(- x);
}

int main()
{
	int T, to, x, y;
	char str[10];
	bool st = false;
	//scan_d(T);
	while(~ scanf("%d", &n))
	{
		if(st) puts("");
		else st = true;
		
		for(int i = 0; i <= n; i ++) graph[i].clear();
		
		for(int from = 1; from <= n; from ++)
		{
			scanf("%d", &to);
			graph[to].push_back(from);
		}
		
		seq.clear();
		dfs(0);
		
		SplayTree :: SplayTree();
		//利用 dfs 序构成括号序列 
		int pp = 0, st = 1;
		for(int i = 1; i < seq.size() - 1; i ++)
		{
			if(seq[i] > 0) pp ++;
			else pp --;
			if(pp == 0)
			{
				SplayTree :: build_tree(root, st, i, 0);
				st = i + 1;
			}
		}
		
		scanf("%d", &to);
		while(to --)
		{
			scanf("\n%s", str);
			switch(str[0])
			{
				case 'Q':
					scanf("%d", &x);
					printf("%d\n", SplayTree :: Query(x));
					break;
				case 'M':
					scanf("%d %d", &x, &y);
					SplayTree :: Split(x, y);
					break;
				default:
					assert(str[0] == 'Q' || str[0] == 'M');
			}
		}
	}
	return 0;
}

