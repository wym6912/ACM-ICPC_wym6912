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
const int maxn = 200000 * 4;
const int maxm = -(1 << 30);
const double pi = acos(-1.0);
const double eps = 1e-6;

typedef struct node
{
	int l, r;
	int max_stu;
}node;

node tree[maxn];

void pushup(int p)
{
	tree[p].max_stu = max(tree[DXA(p)].max_stu, tree[DXB(p)].max_stu);
}

void pre(int l, int r, int p)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r){scanf("%d", &tree[p].max_stu);return ;}
	else
	{
		int mid = midf(l, r);
		pre(l, mid, DXA(p));
		pre(mid + 1, r, DXB(p));
		pushup(p);
	}
}

int query(int l, int r, int nl, int nr, int p)
{
	if(l <= nl && nr <= r)return tree[p].max_stu;
	else 
	{
		int ans = maxm;
		int mid = midf(nl, nr);
		if(l <= mid)
			ans = max(ans, query(l, r, nl, mid, DXA(p)));
		if(mid < r)
			ans = max(ans, query(l, r, mid + 1, nr, DXB(p)));
		return ans;
	}
}

void update(int nl, int nr, int px, int ans, int p)
{
	if(nl == px && nr == px)
	{
		tree[p].max_stu = ans;
		return ;
	}
	else 
	{
		int mid = midf(nl, nr);
		if(nl <= px && px <= mid)update(nl, mid, px, ans, DXA(p));
		if(mid < px && px <= nr) update(mid + 1, nr, px, ans, DXB(p));
		pushup(p);
	}
}

int main()
{
	int n, m, tmp, a, b;
	char x;
	while(~ scanf("%d %d", &n, &m))
	{
		pre(1, n, 1);
		for(int i = 1;i <= m;i ++)
		{
			scanf("\n%c %d %d", &x, &a, &b);
			if(x == 'Q')printf("%d\n", query(a, b, 1, n, 1));
			if(x == 'U')update(1, n, a, b, 1);
		}
	}
	return 0;
}
