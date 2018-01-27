//#define NOSTDCPP
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
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 200000 * 3;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

typedef struct node
{
	int data;
}node;

node tree[maxn];

int n, m;

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

void pushup(int p)
{
	tree[p].data = tree[DXA(p)].data + tree[DXB(p)].data;
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].data = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int query(int l, int r, int tmppos, int p)
{
	tree[p].data --;
	if(l == r)
	{
		//tree[p].data = 0;
		return l;
	}
	int mid = midf(l, r);
	if(tmppos <= tree[DXA(p)].data)
		return query(l, mid, tmppos, DXA(p));
	else return query(mid + 1, r, tmppos - tree[DXA(p)].data, DXB(p));
}

int main()
{
	scanf("%d%d", &n, &m);
	pre(1, n, 1);
	int tmp = 1, pos;
	for(int i = 1; i <= n; i ++)
	{
		tmp = (tmp + m - 1) % tree[1].data; //相对位置 
		if(tmp == 0)tmp = tree[1].data;
		pos = query(1, n, tmp, 1); //绝对位置 
		printf("%d", pos);
		if(i == n)printf("\n");
		else printf(" ");
	}
	return 0;
}

