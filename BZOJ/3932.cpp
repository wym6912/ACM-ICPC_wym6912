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
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 100009 * 128;
const ll inf = 1e18;
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

template <class T>
inline void out_number(T x)
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

struct timer
{
	int time, event, chg;
	//timer(int time = 0, int event = 0, int chg = -1) : time(time), event(event), chg(chg) {}
	bool operator < (const timer &b) const
	{
		return time < b.time;
	}
}eve[maxn << 1];

int n, m;
vi h;

int root[maxn << 1], tot;
struct node
{
	int l, r, siz;
	ll sum;
}tree[maxm];

void pre_(int nl, int nr, int &p)
{
	p = ++ tot;
	tree[p].siz = tree[p].sum = 0;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	pre_(nl, mid, tree[p].l);
	pre_(mid + 1, nr, tree[p].r);
}

void build(int pre, int &now, int nl, int nr, int chg, int vpl)
{
	now = ++ tot;
	tree[now] = tree[pre];
	tree[now].siz += chg;
	tree[now].sum += h[vpl] * chg;
	if(nl == nr) return ;
	int mid = midf(nl, nr);
	if(vpl <= mid) build(tree[pre].l, tree[now].l, nl, mid, chg, vpl);
	else build(tree[pre].r, tree[now].r, mid + 1, nr, chg, vpl);
}

ll query(int nl, int nr, int p, int k)
{
	if(k >= tree[p].siz) return tree[p].sum;
	if(nl == nr) return tree[p].sum / tree[p].siz * k;
	int sz = tree[tree[p].l].siz, mid = midf(nl, nr);
	ll ans;
	if(sz >= k) ans = query(nl, mid, tree[p].l, k);
	else ans = tree[tree[p].l].sum + query(mid + 1, nr, tree[p].r, k - sz);
	return ans;
} 

int main()
{
	//freopen("query4.in", "r", stdin);
	//freopen("query4.ans", "w", stdout);
	scanf("%d %d", &m, &n);
	int treesiz;
	tot = 0;
	for(int i = 1, f, t, x; i <= m; ++ i)
	{
		scanf("%d %d %d", &f, &t, &x);
		eve[i * 2 - 1] = timer{f, x, 1};
		eve[i * 2] = timer{t + 1, x, -1};
		h.push_back(x);
	}
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	treesiz = h.size();
	m <<= 1;
	sort(eve + 1, eve + 1 + m);
	//printf("%d %d\n", m, treesiz);
	//for(int i = 1; i <= m; ++ i)
	//	printf("%d %d %d\n", eve[i].time, eve[i].event, eve[i].chg);
	ll pre = 1, x, a, b, c, k;
	root[0] = 0;
	//pre_(0, treesiz - 1, root[0]);
	for(int i = 1, nowtime; i <= m; ++ i)
	{
		x = lower_bound(h.begin(), h.end(), eve[i].event) - h.begin();
		//printf("%d\n", x);
		nowtime = eve[i].time;
		if(i == 1 || eve[i - 1].time != nowtime)
		{
			if(i != 1)
			{
				for(int j = eve[i - 1].time + 1; j < nowtime; ++ j)
					//build(root[j - 1], root[j], 1, treesiz, 0, 0);
					root[j] = root[j - 1];
			}
			build(root[nowtime - 1], root[nowtime], 0, treesiz - 1, eve[i].chg, x);
		}
		else build(root[nowtime], root[nowtime], 0, treesiz - 1, eve[i].chg, x);
	//	printf("%d %lld\n", nowtime, tree[root[nowtime]].sum);
	}
	while(n --)
	{
		scanf("%lld %lld %lld %lld", &x, &a, &b, &c);
		k = (pre * a + b) % c + 1;
		k = query(0, treesiz - 1, root[x], (int)k);
		printf("%lld\n", k);
		pre = k;
	}
	return 0;
}

