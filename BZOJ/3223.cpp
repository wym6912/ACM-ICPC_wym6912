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

int a[maxn];

namespace SplayTree
{
	#define ls(p) t[p].ch[0]
	#define rs(p) t[p].ch[1]
	#define inf 0x3f3f3f3f
	/*
	nampspace SplayTree 清单 
		结点存储位置: node t[maxn]; 
			size: 包含自己的子树大小
			sum: 区间和
			mx: 区间最大和
			lm: 左连续区间最大和
			rm: 右连续区间最大和
			v: 区间本身的值 
			tag: 是否需要将区间更新为 v 
			rev: 是否需要将区间翻转
			f: 父亲结点
			ch[0]: 左孩子
			ch[1]: 右孩子 
			node(val): 构造函数，表示该节点的值为 val 
		函数:
			newnode(): 确定新的结点的位置
			wh(p): 确定右孩子的父亲是自己？(确定自己有右孩子)
			rever(p): 翻转以 p 为根节点的子树 
			paint(p, val): 将以 p 为根节点的子树的所有值染成 val 
			pushdown(p): 将以 p 为根节点翻转和染色标记下传
			pushup(p): 维护 p 的信息 
			Splay(p, cur): 将 p 旋转到父亲为 cur 位置上 
			build_tree(&p, L, R, fa): 建立以 p 为根，父亲为 fa，在[L, R]的 SplayTree 
			Kth(k): 返回 SplayTree 上第 k 大的位置，越界返回 -1 
			Ins_from_a(k, tot): 将 a 数组的 [1, tot] 位置的信息插入到 SplayTree 第 k 
			位上,（也就是在第 k 位置后面插入一个区间） 
			erase(p): 删除以 p 为根的子树 
			getright(x): 求 SplayTree 的右叶节点 
			Del(k, tot): 删除以 k 开始的 tot 个数 
			Mak(k, tot, x): 将 k 以后的 tot 个数设为 x 
			Rev(k, tot): 将 k 以后的 tot 个数翻转 
			Sum(k, tot): 求 k 以后的 tot 个数的和 
			Sumall(): 求 [1, n]的区间和 
			MaxSum(k, tot): 求 [k, k + tot - 1] 的最大子段和
			MaxSumall(): 求 [1, n] 的最大子段和 
			Merge(root1, root2): root2 接到 root1 右子树，要求 root1 无右子树
			Travel(x): 以 x 为开始，遍历数组，将遍历的值存到 a[] 数组内 
			Split(L, R, C): 将 [L, R] 放到第 C 个数后面(C = 0 表示插入到最前面) 
		构造函数：
			SplayTree(n): 建立一棵读入 n 个数的 SplayTree，包含 -inf 结点 
	*/
	struct node {
	    int size, sum, mx, lm, rm, v;
	    int tag, rev;
	    int f, ch[2];
	    node() {}
	    node(int val) {ch[0] = ch[1] = tag = rev = f = 0; size = 1; v = sum = mx = lm = rm = val;}
	}t[maxn]; 
	int st[maxn], sz, top, root;
	int newnode() {return top ? st[top--] : ++sz;}
	int wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;
	 
	void rever(int p)
	{
	    if(t[p].tag) return;
	    t[p].rev ^= 1;
	    swap(ls(p), rs(p)); swap(t[p].lm, t[p].rm);
	}
	 
	void paint(int p, int val)
	{
	    t[p].tag = 1; t[p].v = val;
	    t[p].sum = val * t[p].size;
	    t[p].lm = t[p].rm = t[p].mx = max(val, t[p].sum);
	    t[p].rev = 0;
	}
	 
	void pushdown(int p)
	{
	    if(t[p].rev)
	    {
	        if(ls(p)) rever(ls(p));
	        if(rs(p)) rever(rs(p));
	        t[p].rev = 0;
	    }
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
	    t[p].mx = max(max(t[ls(p)].mx, t[rs(p)].mx), max(0, t[ls(p)].rm) + t[p].v + max(0, t[rs(p)].lm));
	    t[p].lm = max(t[ls(p)].lm, t[ls(p)].sum + t[p].v + max(0, t[rs(p)].lm));
	    t[p].rm = max(t[rs(p)].rm, t[rs(p)].sum + t[p].v + max(0, t[ls(p)].rm));
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
	 
	void Rev(int k, int tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    rever(ls(p)); 
	    pushup(p); pushup(f);
	}
	 
	int Sum(int k, int tot)
	{
	    int f = Kth(k); Splay(f, 0);
	    int p = Kth(k + tot + 1); Splay(p, f);
	    return t[ls(p)].sum;
	}
	
	int Sumall()
	{
		return t[1].sum;
	}
	
	int MaxSum(int k, int tot)
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
		for(int i = 2;i <= n + 1; ++i) a[i] = i - 1; 
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
	
	void Merge(int root1, int root2)
	{
	    t[root1].ch[1] = root2;
	    t[root2].f = root1;
	}
	
	void Split(int L, int R, int C)
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

int main()
{
	int n, m, l, r;
	scanf("%d%d", &n, &m);
	SplayTree :: SplayTree(n);
	while(m --)
	{
		//scan_d(l);
		//scan_d(r);
		scanf("%d %d", &l, &r);
		SplayTree :: Rev(l, r - l + 1);
	}
	tmproot = 0;
	SplayTree :: Travel(root);
	for(int i = 1; i <= n; i ++)
	{
		out_number(a[i]);
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}
/*
5 3
1 3
1 3
1 4
*/

