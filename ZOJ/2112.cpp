#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstring>
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
# define midf(x, y) (((x) + (y)) >> 1)
# define fi first
# define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 50009;
const int maxm = maxn * 40;
const double pi = acos(-1.0);
const double eps = 1e-6;

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

inline void out(ll x)
{
	if(x < 0)
	{
		putchar('-');
		out(- x);
		return ;
	}
	if(x > 9)out (x / 10);
	putchar(x % 10 + '0');
}

int n, A[maxn], siz;

struct node
{
	int l, r, sum;
}tree[maxm];
int root[maxn], tot, yroot[maxn];

void pre(int l, int r, int &p)
{
	p = ++ tot;
	tree[p].sum = 0;
	if(l == r) return;
	int mid = midf(l, r);
	pre(l, mid, tree[p].l);
	pre(mid + 1, r, tree[p].r);
}
/*非递归版 
void updat(int pos, int v, int &p, int pre)
{
	int tmp = ++ tot, l = 1, r = siz;
	p = tmp; 
	tree[tmp] = tree[pre];
	tree[tmp].sum += v;
	while(l < r)
	{
		int mid = midf(l, r);
		if(pos <= mid)
		{
			tree[tmp].l = ++ tot; tree[tmp].r = tree[pre].r;
			tree[tree[tmp].l].sum = tree[tree[pre].l].sum + v;
			tmp = tree[tmp].l;
			pre = tree[pre].l;
			r = mid;
		}
		else 
		{
			tree[tmp].r = ++ tot; tree[tmp].l = tree[pre].l;
			tree[tree[tmp].r].sum = tree[tree[pre].r].sum + v;
			tmp = tree[tmp].r;
			pre = tree[pre].r;
			l = mid + 1;
		}
	}
}
*/
void build(int nl, int nr, int &p, int pre, int val, int place)
{
	p = ++ tot;
	tree[p] = tree[pre];
	tree[p].sum += val;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(mid >= place) build(nl, mid, tree[p].l, tree[pre].l, val, place);
	else build(mid + 1, nr, tree[p].r, tree[pre].r, val, place);
}

namespace BIT
{
	int B[maxn]; //保存新的临时根的数组 
	
	int lowbit(int x) {return x & -x;}
	
	void update(int x, int pos, int v)
	{
		for(int i = x; i <= n; i += lowbit(i))
			//updat(pos, v, root[i], root[i]);
			build(1, siz, root[i], root[i], v, pos); //将变化更新到树状数组上 
	}
	
	int sum(int x)
	{
		int ans = 0;
		for(int i = x; i; i -= lowbit(i))
			ans += tree[tree[B[i]].l].sum; //从缓存数组中读取结果 
		return ans;
	}
};

using namespace BIT;

vi dis;
int id(int x){return lower_bound(dis.begin(), dis.end(), x) - dis.begin();}

struct query
{
	int type, f, t, k;
};
query qqq[maxn];

int ans(int f, int t, int k)
{
	//将结果缓存到树状数组里面 
	for(int i = f - 1; i; i -= lowbit(i)) B[i] = root[i];
	for(int i = t; i; i -= lowbit(i)) B[i] = root[i];
	int sl = 1, sr = siz, lrt = yroot[f - 1], rrt = yroot[t];
	while(sl < sr) // 二分查找第 k 大
	{
		int s = sum(t) - sum(f - 1) + tree[tree[rrt].l].sum - tree[tree[lrt].l].sum;
		int mid = midf(sl, sr);
		if(s < k)
		{
			//去右子树查找 
			k -= s;
			sl = mid + 1; 
			for(int i = f - 1; i; i -= lowbit(i)) B[i] = tree[B[i]].r;
			for(int i = t; i; i -= lowbit(i)) B[i] = tree[B[i]].r;
			rrt = tree[rrt].r, lrt = tree[lrt].r;
		}
		else 
		{
			//去左子树查找 
			for(int i = f - 1; i; i -= lowbit(i)) B[i] = tree[B[i]].l;
			for(int i = t; i; i -= lowbit(i)) B[i] = tree[B[i]].l;
			rrt = tree[rrt].l, lrt = tree[lrt].l;
			sr = mid;
		}
	}
	return sl - 1;
}


int main()
{
	int q, tt, T;
	char ch;
	//scan_d(n);
	//scan_d(q);
	scanf("%d", &T);
	while(T --)
	{
		tot = 0;
		scanf("%d %d", &n, &q);
		dis.clear();
		for(int i = 1; i <= n; ++ i)
			//scan_d(A[i]), 
			scanf("%d", A + i),
			dis.push_back(A[i]);
		for(int i = 1; i <= q; ++ i)
		{
			scanf("\n%c", &ch);
			switch(ch)
			{
				case 'Q':
					qqq[i].type = 1;
					scanf("%d %d %d", &qqq[i].f, &qqq[i].t, &qqq[i].k);
					break;
				case 'C':
					qqq[i].type = 2;
					scanf("%d %d", &qqq[i].f, &qqq[i].t);
					dis.push_back(qqq[i].t);
					//对查询离散化，离线处理答案 
					break;
				default:
					assert(ch == 'Q' || ch == 'C');
			}
		}
		sort(dis.begin(), dis.end());
		dis.erase(unique(dis.begin(), dis.end()), dis.end());
		siz = dis.size();
		//pre(1, siz, yroot[0]);
		for(int i = 1; i <= n; ++ i)
			//updat(id(A[i]) + 1, 1, yroot[i], yroot[i - 1]);
			build(1, siz, yroot[i], yroot[i - 1], 1, id(A[i]) + 1);
		RESET(root);
		for(int i = 1; i <= q; ++ i)
		{
			if(qqq[i].type == 1)
				printf("%d\n", dis[ans(qqq[i].f, qqq[i].t, qqq[i].k)]);
			else
			{
				BIT :: update(qqq[i].f, id(A[qqq[i].f]) + 1, -1);
				BIT :: update(qqq[i].f, id(qqq[i].t) + 1, 1);
				A[qqq[i].f] = qqq[i].t;
			}
		}
	}
	return 0;
}

