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

struct LINE //扫描 
{
	int x, y1, y2;//横坐标，左右端点 
	bool in;//入边 
	LINE(int x, int y1, int y2, bool in): x(x), y1(y1), y2(y2), in(in){}
	LINE(){}
	bool operator < (const LINE &b)const
	{
		if(x != b.x)return x < b.x;
		return in > b.in;
	}
}line[maxn];

int n;
///////////////实现线段树的功能/////////////////////

typedef struct Node
{
	int cover;//完全覆盖层数
	int lines;//分成多少个线段
	bool L, R;//左右端点是否被覆盖
	int coverlength;//覆盖长度 
	int length;//总长度 
	Node(){}
	Node(int cover, int lines, bool L, bool R, int coverlength) : 
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
		printf("cover=%d lines=%d L=%d R=%d CoverLength=%d Length=%d\n",
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

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].L = tree[p].R = false;
		tree[p].coverlength = 0;
		tree[p].lines = 0;
		tree[p].cover = 0;
		tree[p].length = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
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

// 现在任务：实现 cover() uncover() pre() 和线段树这个结构体 

int main()
{
	int x1, x2, y1, y2;
	while(scan_d(n))
	{
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			line[DXA(i)] = LINE(x1, y1 + 10001, y2 + 10001, 1);
			line[DXB(i)] = LINE(x2, y1 + 10001, y2 + 10001, 0);
		}
		int nl = DXA(n);
		sort(line, line + nl);
		int prex = line[0].x;
		int ans = 0;
		int prelength = 0, prelines = 0;
		pre(1, 20001, 1);
		for(int i = 0; i < nl; i ++)
		{
			if(line[i].in)cover(line[i].y1, line[i].y2 - 1, 1, 20001, 1);
			else uncover(line[i].y1, line[i].y2 - 1, 1, 20001, 1);
			//更新横向的边界 
			ans += 2 * prelines * (line[i].x - prex);
			prelines = tree[1].lines;
			prex = line[i].x;
			//更新纵向边界 
			ans += abs(tree[1].coverlength - prelength);
			prelength = tree[1].coverlength;
		}
		out_number(ans);
		puts("");
		getchar();
	}
	return 0;
}
/*
7
-15 0 5 10
-5 8 20 25
15 -4 24 14
0 -6 16 4
2 15 10 22
30 10 36 20
34 0 40 16
2
-10 -10 0 10
0 -10 10 10
*/
