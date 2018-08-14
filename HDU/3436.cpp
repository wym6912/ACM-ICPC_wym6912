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
int n, m, cnt;

short op[maxn];
int qu[maxn];


struct __operation
{
	int l, r;
}opp[maxn];

namespace SplayTree
{
	#define ls(p) t[p].ch[0]
	#define rs(p) t[p].ch[1]
	#define inf 0x3f3f3f3f
	struct node {
	    int size, v, pl;
	    int f, ch[2];
	    node() {}
	    node(int l, int r) 
		{
			assert(l <= r);
			ch[0] = ch[1] = f = 0;
			size = r - l + 1;
			v = r - l + 1;
		}
	}t[maxn]; 
	int st[maxn], sz, top, root, node_pl[maxn];
	int newnode() {return ++ sz;}
	int wh(int p) {return t[t[p].f].ch[1] == p;}
	int tmproot;
	 
	void pushup(int p)
	{
		t[p].size = t[p].v;
		if(ls(p)) t[p].size += t[ls(p)].size;
		if(rs(p)) t[p].size += t[rs(p)].size;
	}
	 
	void rotate(int p)
	{
	    int f = t[p].f, g = t[f].f, c = wh(p);
	    if(g) t[g].ch[wh(f)] = p; t[p].f = g;
	    t[f].ch[c] = t[p].ch[c ^ 1]; if(t[f].ch[c]) t[t[f].ch[c]].f = f;
	    t[p].ch[c ^ 1] = f; t[f].f = p;
	    pushup(f); pushup(p);
	}
	
	int Get_max(int x)
	{
	    while(rs(x))
	    {
	        x = rs(x);
	    }
	    return x;
	}
	
	void Splay(int p, int cur)
	{
	    for(;t[p].f != cur; rotate(p))
	        if(t[t[p].f].f != cur) rotate(wh(p) == wh(t[p].f) ? t[p].f : p);
	    if(cur == 0) root = p;
	}
	
	
	void erase(int p)
	{
	    Splay(p, 0);
	    if(! ls(root))
	    {
	    	root = rs(root);
	    	t[root].f = 0;
		}
		else 
		{
			int tt = Get_max(ls(root));
			Splay(tt, root);
			rs(tt) = rs(root);
			t[rs(root)].f = tt;
			root = tt;
			t[root].f = 0;
			pushup(root);
		}
	}
	 
	void build_tree(int &p, int L, int R, int fa)
	{
	    int mid = midf(L, R);
	    p = newnode(); 
		t[p] = node(opp[mid].l, opp[mid].r);
		t[p].f = fa;
		t[p].pl = mid;
		node_pl[mid] = p;
	    if(L == R) return;
	    if(L < mid) build_tree(ls(p), L, mid - 1, p);
	    if(mid < R) build_tree(rs(p), mid + 1, R, p); 
	    pushup(p);
	}

	int get_Kth(int x, int k)
	{
		int lst = t[ls(x)].size;
		if(k <= lst) return get_Kth(ls(x), k);
		else if(k <= lst + t[x].v) return opp[t[x].pl].l + (k - lst - 1);
		else return get_Kth(rs(x), k - lst - t[x].v);
	}
	 
	int Val(int k)
	{
		//cout << "k = " << k << ", node_pl[k] = " << node_pl[k] << endl;
		k = node_pl[k];
		Splay(k, 0);
	    return t[ls(k)].size + 1;
	}
	
	void SplayTree(int n)
	{
		//for(int i = 2;i <= n + 1; ++i) a[i] = i - 1; 
		//a[1] = a[n + 2] = -inf;
    	t[0] = node(0, 0);
    	t[0].size = 0;
    	t[0].pl = 0;
    	top = 0;
    	root = 0; 
		sz = 0;
    	build_tree(root, 1, n, 0);
	}
	
	void Ins(int &x, int fa, int k)
	{
		if(! x)
		{
			x = newnode();
			t[x] = node(opp[k].l, opp[k].r);
			t[x].f = fa;
			t[x].pl = k;
			node_pl[k] = x;
			return;
		}
		else
		{
			Ins(ls(x), x, k);
			pushup(x);
		}
	}
	
	void Travel(int x)
	{
		if(! x)return ;
		Travel(ls(x));
		a[++ tmproot] = t[x].pl;// Check here
		Travel(rs(x));
	}
	
	void Split_2(int pl)
	{
		int y = node_pl[pl];
		erase(y);
		Ins(root, 0, pl);
		Splay(sz, 0);
	}
	
	#undef ls
	#undef rs
	#undef inf
};

using namespace SplayTree;


int Find_Place(int p) // 离散化后找位置
{
	int l = 1, r = cnt, mid;
	while(l <= r)
	{
		mid = midf(l, r);
		if(opp[mid].l <= p && p <= opp[mid].r)
			return mid;
		if(opp[mid].r < p)
			l = mid + 1;
		else r = mid - 1;
	}
	assert(false);
	return -1;
} 

void doit(int x)
{
	SplayTree :: SplayTree(cnt);
	printf("Case %d:\n", x);
	int pl, modi = 0;
	for(int i = 1; i <= m; i ++)
	{
		switch(op[i])
		{
			case 1:
				pl = Find_Place(qu[i]);
				//cout << "Pl = " << pl << endl;
				SplayTree :: Split_2(pl);
				break;
			case 2:
				pl = Find_Place(qu[i]);
				printf("%d\n", SplayTree :: Val(pl));
				break;
			case 3:
				printf("%d\n", SplayTree :: get_Kth(root, qu[i]));
				break;
			default:
				assert(op[i] == 1 || op[i] == 2 || op[i] == 3);
		}
		/*
		RESET(a);
		tmproot = 0;
		Travel(root);
		for(int j = 1; j <= cnt; j ++)
			printf("%d%c", a[j], j == cnt ? '\n' : ' ');
			*/
	}
}

int main()
{
	int T, p;
	char str[10];
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		p = 0;
		a[++ p] = 0;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; i ++)
		{
			scanf("\n%s %d", str, &qu[i]);
			switch(str[0])
			{
				case 'T':
					op[i] = 1;
					a[++ p] = qu[i];
					break;
				case 'Q':
					op[i] = 2;
					a[++ p] = qu[i];
					break;
				case 'R':
					op[i] = 3;
					//可以不需要进行离散化的，这里可以直接算出来的 
					break;
				default:
					assert(str[0] == 'T' || str[0] == 'Q' || str[0] == 'R');
			}
		}
		a[++ p] = n;
		sort(a + 1, a + p + 1);
		p = unique(a + 1, a + p + 1) - a - 1;
		//for(int i = 1; i <= p; i ++)
		//	cout << a[i] << ' ';
		//cout << endl;
		cnt = 0;
		//opp[++ cnt].l = 0;
		//opp[cnt].r = 0;
		/*离散化的好方法!*/
		for(int i = 2; i <= p; i ++)
		{
			if(a[i] != a[i - 1])
			{
				if(a[i] - a[i - 1] > 1)
				{
					opp[++ cnt].l = a[i - 1] + 1;
					opp[cnt].r = a[i] - 1;
				}
			}
			opp[++ cnt].l = a[i];
			opp[cnt].r = a[i];
		}
		//cout << cnt << endl;
		/*end.*/ 
		//opp[++ cnt].l = n + 1;
		//opp[cnt].r = n + 1;
		/*
		puts("Opp");
		for(int i = 1; i <= cnt; i ++)
			printf("%d %d\n", opp[i].l, opp[i].r);
			*/
		doit(Casen);
	}
	return 0;
}
/*
5
9 5
Top 1
Rank 3
Top 7
Rank 6
Rank 8
6 2
Top 4
Top 5
7 4
Top 5
Top 2
Query 1
Rank 6
10000000 3
TOP 50000
RANK 50000
RANK 60000
36110 40
Top 10720
Top 18193
Rank 19248
Rank 668
Query 34595
Top 19180
Top 19397
Query 9264
Rank 12811
Rank 19818
Rank 28973
Rank 3849
Query 28816
Query 4817
Top 24737
Query 2575
Top 28948
Query 5051
Rank 9939
Top 34541
Rank 4871
Top 23240
Rank 27879
Rank 30680
Top 23647
Top 25238
Top 16851
Rank 19665
Top 24476
Top 27014
Query 18751
Rank 25696
Top 10720
Query 34845
Top 25470
Rank 403
Query 32402
Top 27062
Query 17359
Top 22989
*/
