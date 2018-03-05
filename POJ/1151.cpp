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
const int maxn = 1009;
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
}line[maxn];

struct data
{
	double x1, x2, y1, y2;
}pre[maxn];

double seq[maxn * 2];

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
	int cover;//完全覆盖层数
	int lines;//分成多少个线段
	bool L, R;//左右端点是否被覆盖
	double coverlength;//覆盖长度 
	double length;//总长度 
	Node(){}
	Node(int cover, int lines, bool L, bool R, double coverlength) : 
	cover(cover),lines(lines),L(L),R(R),coverlength(coverlength){}
	Node operator +(const Node &b){//连续区间的合并 
		Node c;
		c.cover = 0;
		c.lines = lines + b.lines - (R && b.L);
		c.coverlength = coverlength + b.coverlength;
		c.L = L;
		c.R = b.R;
		c.length = length + b.length;
		return c;
	}
	void Show(){
		printf("cover=%d lines=%d L=%d R=%d CoverLength=%f Length=%f\n",
		 cover, lines, L, R, coverlength, length);
	}
}node;

node tree[maxn];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		if(tree[p].cover)
		{
			tree[p].coverlength = tree[p].length;
			tree[p].L = tree[p].R = true;
			tree[p].lines = 1;
			return ;
		}
		else tree[p] = tree[DXA(p)] + tree[DXB(p)];
	}
}

void pretree(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].L = tree[p].R = false;
		tree[p].coverlength = 0.0;
		tree[p].lines = 0;
		tree[p].cover = 0;
		tree[p].length = mp[l + 1] - mp[l];
		//注意这里：扫描线的区间长度是[l, l + 1] 映射区间的长度 
		return ;
	}
	int mid = midf(l, r);
	pretree(l, mid, DXA(p));
	pretree(mid + 1, r, DXB(p));
	tree[p].cover = 0;
	pushup(p, l, r);
}

void cover(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].cover ++;
		if(tree[p].cover == 1)
		{
			tree[p].coverlength = tree[p].length;
			tree[p].lines = 1;
			tree[p].L = tree[p].R = true;
		}
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
		if(! tree[p].cover)
		{
			if(nl == nr)
			{
				tree[p].coverlength = 0;
				tree[p].lines = 0;
				tree[p].L = tree[p].R = false;
			}
			else tree[p] = tree[DXA(p)] + tree[DXB(p)];
		}
		return;
	}
	int mid = midf(nl, nr);
	if(l <= mid)uncover(l, r, nl, mid, DXA(p));
	if(mid < r) uncover(l, r, mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

///////////////完毕。///////////////////// 

int main()
{
	int xx = 0, idz, idend;
	double ans;
	while(scan_d(n_map) && n_map != 0)
	{
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
			//tree[1].Show();
			//cout << (line[i].x - line[i - 1].x) * tree[1].coverlength << " " << 
			//line[i].y1 << " " << line[i].y2 << endl;
			ans += (line[i + 1].x - line[i].x) * tree[1].coverlength;
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n", xx, ans);
	}
	return 0;
}

