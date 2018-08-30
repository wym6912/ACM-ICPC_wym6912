#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
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
const int maxn = 100009;
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

int n, A[maxn];

struct node
{
	int l, r, sum;
}tree[maxm];
int root[maxn], tot;

vi dis;
int id(int x){return lower_bound(dis.begin(), dis.end(), x) - dis.begin();}

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

int query(int l, int r, int nl, int nr, int place)
{
	if(nl == nr) return nl;
	int sum = tree[tree[r].l].sum - tree[tree[l].l].sum, mid = midf(nl, nr);
	if(sum >= place) return query(tree[l].l, tree[r].l, nl, mid, place);
	return query(tree[l].r, tree[r].r, mid + 1, nr, place - sum);
}

int main()
{
	int q, x, siz;
	tot = 1;
	
	scan_d(n);
	scan_d(q);
	
	//scanf("%d %d", &n, &q);
	for(int i = 1;i <= n; ++ i)
		scan_d(A[i]), 
		//scanf("%d", A + i),
		dis.push_back(A[i]);
	sort(dis.begin(), dis.end());
	dis.erase(unique(dis.begin(), dis.end()), dis.end());
	siz = dis.size();
	for(int i = 1; i <= n; ++ i)
		build(0, siz - 1, root[i], root[i - 1], 1, id(A[i]));
	while(q --)
	{
		int a, b, c;
		
		scan_d(a);
		scan_d(b);
		scan_d(c);
		out(dis[query(root[a - 1], root[b], 0, siz - 1, c)]);
		puts("");
		
		/*
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", dis[query(root[a - 1], root[b], 0, siz - 1, c)]);
		*/
	}
	return 0;
}

