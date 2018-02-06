#include <bits/stdc++.h>

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
const int maxn = 1000009 * 4;
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

template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
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

typedef struct
{
	int tag;
	int minx;
}node;

node tree[maxn];

int n, q;

void pushup(int p, int l, int r)
{
	tree[p].minx = 0;
	if(l < r)
	{
		tree[p].minx = min(tree[DXA(p)].minx, tree[DXB(p)].minx);
	}
	tree[p].minx += tree[p].tag;
}

void pre(int l, int r, int p)
{
	if(l == r)
	{
		scan_d(tree[p].tag);
		tree[p].minx = tree[p].tag;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

int minx;

void query(int l, int r, int nl, int nr, int t, int p)
{
	if(l <= nl && nr <= r)
	{
		minx = min(minx, tree[p].minx + t);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)query(l, r, nl, mid, t + tree[p].tag, DXA(p));
	if(mid < r) query(l, r, mid + 1, nr, t + tree[p].tag, DXB(p));
}

void update(int l, int r, int nl, int nr, int t, int p)
{
	if(l <= nl && nr <= r)
	{
		tree[p].tag += t;
		pushup(p, nl, nr);
		return ;
	}
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, t, DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, t, DXB(p));
	pushup(p, nl, nr);
}

int main()
{
	int f, t, d;
	scan_d(n, q);
	pre(1, n, 1);
	for(int i = 1; i <= q; i ++)
	{
		scan_d(d, f, t);
		minx = 1e9 + 1;
		query(f, t, 1, n, 0, 1);
		if(minx < d)
		{
			puts("-1");
			out_number(i);
			puts("");
			return 0;
		}
		else update(f, t, 1, n, -d, 1);
	}
	puts("0");
	return 0;
}

