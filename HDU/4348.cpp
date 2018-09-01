//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
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

const int MOD = 1e9 + 7;
const int maxn = 100009;
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

typedef struct node
{
	int l, r, add, len;
	ll sum;
};

node tree[maxn * 40];
int tot, root[maxn], n, m;

void pushup(int p)
{
	tree[p].sum = tree[tree[p].l].sum + tree[tree[p].r].sum;
	tree[p].sum += (ll) tree[p].add * (tree[p].len);
}

void pre(int l, int r, int &p)
{
	p = ++ tot;
	tree[p].add = 0;
	tree[p].sum = 0;
	tree[p].len = r - l + 1;
	if(l == r)
	{
		scanf("%d", &tree[p].add);
		tree[p].sum = tree[p].add;
        tree[p].l = tree[p].r = 0;
		return;
	}
	int mid = midf(l, r);
	pre(l, mid, tree[p].l);
	pre(mid + 1, r, tree[p].r);
	pushup(p);
}

int val;
void build(int nl, int nr, int &p, int pre, int l, int r)
{
	p = ++ tot;
	tree[p] = tree[pre];
	if(l <= nl && nr <= r)
	{
		tree[p].sum += (ll)val * (tree[p].len);
		tree[p].add += val;
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid) build(nl, mid, tree[p].l, tree[pre].l, l, r);
	if(mid < r)  build(mid + 1, nr, tree[p].r, tree[pre].r, l, r);
	pushup(p);
}

int l, r;
ll query(int pl, int nl, int nr, ll tags)
{
	if(l <= nl && nr <= r)
		return tree[pl].sum + tags * tree[pl].len;
	ll sum = 0;
	int mid = midf(nl, nr);
	if(l <= mid) sum += query(tree[pl].l, nl, mid, tree[pl].add + tags);
	if(mid < r)  sum += query(tree[pl].r, mid + 1, nr, tree[pl].add + tags);
	return sum;
}

int main()
{
	int vn, f, t;
	char ch;
	bool ddd = false;
	while(~ scanf("%d %d", &n, &m))
	{
		if(ddd) printf("\n");
		else ddd = true;
		vn = 0;
		tot = 0;
		pre(1, n, root[vn]);
		while(m --)
		{
			scanf("\n%c", &ch);
			switch(ch)
			{
				case 'C':
					scanf("%d %d %d", &f, &t, &val);
					vn ++;
					build(1, n, root[vn], root[vn - 1], f, t);
					break;
				case 'Q':
					scanf("%d %d", &l, &r);
					printf("%I64d\n", query(root[vn], 1, n, 0));
					break;
				case 'H':
					scanf("%d %d %d", &l, &r, &t);
					printf("%I64d\n", query(root[t], 1, n, 0));
					break;
				case 'B':
					scanf("%d", &vn);
					break;
				default:
					assert(ch == 'C' || ch == 'Q' || ch == 'H' || ch == 'B');
			}
		}
	}
	return 0;
}

