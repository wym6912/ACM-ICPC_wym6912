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
const int maxn = 5000;
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

int n_map;

struct LINE //扫描 
{
	double x;
	int y1, y2;//纵坐标，左右端点的 ID 
	bool in;//入边 
	LINE(double x, int y1, int y2, bool in): x(x), y1(y1), y2(y2), in(in){}
	LINE(){}
	bool operator < (const LINE &b)const
	{
		if(x != b.x)return x < b.x;
		return in > b.in; //in = true 表示入边， in = false 表示出边 
	}
}line[maxn * 2];

struct data
{
	double x1, x2, y1, y2;
}pre[maxn];

double seq[maxn * 4];

map <int, double> mp;
map <double, int> mpr;

void cnv()
{
	for(int i = 1; i <= n_map; i ++)
	{
		line[DXB(i - 1)] = LINE(pre[i].x1, mpr[pre[i].y1], mpr[pre[i].y2], true);
		line[DXA(i)]     = LINE(pre[i].x2, mpr[pre[i].y1], mpr[pre[i].y2], false);
	}
	sort(line + 1, line + 1 + DXA(n_map));
}

///////////////实现线段树的功能/////////////////////

typedef struct Node
{
	int cover;//覆盖层数
	double coverl[3];//覆盖 >= i 次的长度 
	void Show(){
		printf("cover=%d cover[0]=%f cover[1]=%f cover[2]=%f\n",
		 cover, coverl[0], coverl[1], coverl[2]);
	}
}node;

node tree[maxn << 2];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		int x;
		if(tree[p].cover <= 1)//统一 0 和 1 的处理 
		{
			x = 1 - tree[p].cover;
			tree[p].coverl[1] = tree[DXA(p)].coverl[x] + tree[DXB(p)].coverl[x];
		}
		else tree[p].coverl[1] = tree[p].coverl[0];
		if(tree[p].cover <= 2)
		{
			x = 2 - tree[p].cover;
			tree[p].coverl[2] = tree[DXA(p)].coverl[x] + tree[DXB(p)].coverl[x];
		}
		else tree[p].coverl[2] = tree[p].coverl[0];
	}
}

void pretree(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].cover = 0;
		tree[p].coverl[0] = mp[l + 1] - mp[l];
		for(int i = 1; i <= 2; i ++)
			tree[p].coverl[i] = 0.0;
		//注意这里：扫描线的区间长度是[l, l + 1] 映射区间的长度 
		return ;
	}
	int mid = midf(l, r);
	pretree(l, mid, DXA(p));
	pretree(mid + 1, r, DXB(p));
	tree[p].cover = 0;
	tree[p].coverl[0] = tree[DXA(p)].coverl[0] + tree[DXB(p)].coverl[0];
	for(int i = 1; i <= 2; i ++)
		tree[p].coverl[i] = 0.0;
}

void cover(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].cover ++;
		if(nl == nr)
		{
			tree[p].coverl[1] = (tree[p].cover > 0) ? tree[p].coverl[0] : 0.0;
			tree[p].coverl[2] = (tree[p].cover > 1) ? tree[p].coverl[0] : 0.0;
		}
		else pushup(p, nl, nr);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)cover(l, r, nl, mid, DXA(p));
	if(mid < r) cover(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

void uncover(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].cover --;
		if(nl == nr)
		{
			tree[p].coverl[1] = (tree[p].cover > 0) ? tree[p].coverl[0] : 0.0;
			tree[p].coverl[2] = (tree[p].cover > 1) ? tree[p].coverl[0] : 0.0;
		}
		else pushup(p, nl, nr);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)uncover(l, r, nl, mid, DXA(p));
	if(mid < r) uncover(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

///////////////完毕。///////////////////// 

int main()
{
	int xx = 0, idz, idend, T;
	double ans;
	scan_d(T);
	while(T --)
	{
		scan_d(n_map);
		mp.clear();
		mpr.clear();
		idz = 0;
		ans = 0.0;
		xx ++;
		for(int i = 1; i <= n_map; i ++)
		{
			scanf("%lf%lf%lf%lf", &pre[i].x1, &pre[i].y1, &pre[i].x2, &pre[i].y2);
			seq[DXB(i - 1)] = pre[i].y1;
			seq[DXA(i)] = pre[i].y2;
		}
		sort(seq + 1, seq + 1 + DXA(n_map));
		//for(int i = 1; i <= DXA(n_map); i ++)
		//	cout << seq[i] << endl;
		idend = unique(seq + 1, seq + 1 + DXA(n_map)) - seq - 1;
		//cout << idend << endl;
		for(int i = 1; i <= idend; i ++)
		{
			mp[i] = seq[i];
			mpr[seq[i]] = i;
			idz ++;
		}
		-- idz;
		cnv();
		pretree(1, idz, 1);
		for(int i = 1; i < DXA(n_map); i ++)
		{
			if(line[i].in)cover(line[i].y1, line[i].y2 - 1, 1, idz, 1);
			else uncover(line[i].y1, line[i].y2 - 1, 1, idz, 1);
			//cout << "A:" << (line[i + 1].x - line[i].x) * tree[1].coverl[2] << " " << 
			//line[i].y1 << " " << line[i].y2 << endl;
			//tree[1].Show();
			ans += (line[i + 1].x - line[i].x) * tree[1].coverl[2];
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

