//#define NOSTDCPP
//#define Cpp11
#define Linux_System
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

const int maxn = 1000007;

struct node
{
	int data;
}tree[maxn << 2];

int n, m;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data;
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].data = 0;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int l, r, x;
void update(int nl, int nr, int p)
{
	if(nl == nr)
	{
		switch(x)
		{
			case 1:
				if(! tree[p].data) tree[p].data = 1;
				break;
			case -1:
				//assert(tree[p].data == 1);
				if(tree[p].data) tree[p].data = 0;
				break;
			default:
				assert(x == 1 || x == -1);
		}
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	else update(mid + 1, nr, DXB(p));
	pushup(p, nl, nr);
}

int Last(int nl, int nr, int p)
{
	if(! tree[p].data) return -1;
	if(nl == nr) return nl;
	int mid = midf(nl, nr);
	if(tree[DXB(p)].data) return Last(mid + 1, nr, DXB(p));
	return Last(nl, mid, DXA(p));
}

int First(int nl, int nr, int p)
{
	if(! tree[p].data) return -1;
	if(nl == nr) return nl;
	int mid = midf(nl, nr);
	if(tree[DXA(p)].data) return First(nl, mid, DXA(p));
	return First(mid + 1, nr, DXB(p));
}

int query(int nl, int nr, int p)
{
	if(nl == nr)
	{
		if(tree[p].data == 0) return -1;
		if(tree[p].data == 1) return 1;
		assert(tree[p].data == 0 || tree[p].data == 1);
	}
	int mid = midf(nl, nr);
	if(l <= mid) return query(nl, mid, DXA(p));
	else return query(mid + 1, nr, DXB(p));
}

int getPre(int nl, int nr, int p)
{
	if(l < 0) return -1;
	if(! tree[p].data) return -1;
	if(nl == nr) return nl;
	int mid = midf(nl, nr);
	if(l <= mid) return getPre(nl, mid, DXA(p));
	else
	{
		int t = getPre(mid + 1, nr, DXB(p));
		if(t == -1) return Last(nl, mid, DXA(p));
		else return t;
	}
}

int getNext(int nl, int nr, int p)
{
	if(! tree[p].data) return -1;
	if(nl == nr) return nl;
	int mid = midf(nl, nr);
	if(mid < l) return getNext(mid + 1, nr, DXB(p));
	else
	{
		int t = getNext(nl, mid, DXA(p));
		if(t == -1) return First(mid + 1, nr, DXB(p));
		else return t;
	}
}

int main()
{
	scan_d(n);
	scan_d(m);
	pre(0, n, 1);
	int type;
	while(m --)
	{
		scan_d(type);
		switch(type)
		{
			case 1:
				scan_d(l);
				x = 1;
				update(0, n, 1);
				break;
			case 2:
				scan_d(l);
				x = -1;
				update(0, n, 1);
				break;
			case 3:
				out_number(First(0, n, 1));
				puts("");
				break;
			case 4:
				out_number(Last(0, n, 1));
				puts("");
				break;
			case 5:
				scan_d(l);
				l --;
				out_number(getPre(0, n, 1));
				puts("");
				break;
			case 6:
				scan_d(l);
				l ++;
				out_number(getNext(0, n, 1));
				puts("");
				break;
			case 7:
				scan_d(l);
				out_number(query(0, n, 1));
				puts("");
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
/*
10 11
1 1
1 2
1 3
7 1
7 4
2 1
3
2 3
4
5 3
6 2
*/

/*
20 2
1 12
5 18
*/

