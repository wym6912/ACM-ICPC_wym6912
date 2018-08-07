#include <bits/stdc++.h>
#include "wall.h"

using namespace std;

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

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int maxn = 2000009;
const int MAXH = 100009;

struct node
{
	int val, min_tag, max_tag;
}tree[maxn << 2];

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].min_tag = min(tree[DXA(p)].min_tag, tree[DXB(p)].max_tag);
		tree[p].max_tag = max(tree[DXA(p)].max_tag, tree[DXB(p)].max_tag);
	}
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		tree[p].val = tree[p].max_tag = tree[p].min_tag = 0;
		return ;
	}
	int mid = midf(l, r);
	tree[p].max_tag = 0;
	tree[p].min_tag = MAXH;
	tree[p].val = 0;
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
}

void update_min_node(int p, int x) //修改 p 的 min 值为 x 
{
	if(x < tree[p].max_tag) tree[p].max_tag = x;
	if(x < tree[p].min_tag) tree[p].min_tag = x;
}

void update_max_node(int p, int x) //修改 p 的 max 值为 x
{
	if(x > tree[p].max_tag) tree[p].max_tag = x;
	if(x > tree[p].min_tag) tree[p].min_tag = x;
}

void pushdown(int p, int l, int r)
{
	update_max_node(DXA(p), tree[p].max_tag);
	update_max_node(DXB(p), tree[p].max_tag);
	tree[p].max_tag = 0;
	update_min_node(DXA(p), tree[p].min_tag);
	update_min_node(DXB(p), tree[p].min_tag);
	tree[p].min_tag = MAXH;
}

int l, r, h;

void update_min(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		update_min_node(p, h);
		return;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_min(nl, mid, DXA(p));
	if(mid < r)  update_min(mid + 1, nr, DXB(p));
}

void update_max(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		update_max_node(p, h);
		return;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update_max(nl, mid, DXA(p));
	if(mid < r)  update_max(mid + 1, nr, DXB(p));
}

void query(int l, int r, int p, int *&x)
{
	if(l == r)
	{
		*x ++= tree[p].max_tag;
		return;
	}
	pushdown(p, l, r);
	int mid = midf(l, r);
	query(l, mid, DXA(p), x);
	query(mid + 1, r, DXB(p), x);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
	pre(1, n, 1);
	for(int i = 0; i < k; i ++)
	{
		switch(op[i])
		{
			case 1:
				l = left[i] + 1;
				r = right[i] + 1;
				h = height[i];
				update_max(1, n, 1);
				break;
			case 2:
				l = left[i] + 1;
				r = right[i] + 1;
				h = height[i];
				update_min(1, n, 1);
				break;
			default:
				assert(false);
		}
	}
	int *o = finalHeight;
	query(1, n, 1, o);
}

