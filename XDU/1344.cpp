#include <cstdio>
#include <algorithm>

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

# define bit_and __Chtholly__
# define bit_or __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 200009;
const int S = -1;

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

int max_ans[maxn << 2], tag_and[maxn << 2], tag_or[maxn << 2], bit_and[maxn << 2], bit_or[maxn << 2];

void pushup(int p)
{
	max_ans[p] = max(max_ans[DXA(p)], max_ans[DXB(p)]);
	bit_and[p] = bit_and[DXA(p)] & bit_and[DXB(p)];
	bit_or[p]  = bit_or[DXA(p)] | bit_or[DXB(p)];
}

void __and(int p, int x)
{
	tag_and[p] &= x, tag_or[p] &= x;
	bit_and[p] &= x, bit_or[p] &= x, max_ans[p] &= x;
}

void __or(int p, int x)
{
	tag_or[p] |= x;
	bit_and[p] |= x, bit_or[p] |= x, max_ans[p] |= x;
}

void pushdown(int p)
{
	if(tag_and[p] != S)
	{
		__and(DXA(p), tag_and[p]);
		__and(DXB(p), tag_and[p]);
		tag_and[p] = S;
	}
	if(tag_or[p])
	{
		__or(DXA(p), tag_or[p]);
		__or(DXB(p), tag_or[p]);
		tag_or[p] = 0;
	}
}

void pre(int l, int r, int p)
{
	tag_and[p] = S;
	tag_or[p] = 0;
	if(l == r)
	{
		scanf("%d", &max_ans[p]);
		bit_and[p] = bit_or[p] = max_ans[p];
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}

int l, r, op, val;
void update(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(op == 1) //AND
		{
			if(((val ^ S) & (bit_and[p] | (bit_or[p] ^ S))) == (val ^ S))
			{
				__and(p, val);
				return ;
			}
		}
		if(op == 2) //OR
		{
			if((val & (bit_and[p] | (bit_or[p] ^ S))) == val)
			{
				__or(p, val);
				return ;
			}
		}
	}
	pushdown(p);
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	if(mid < r)  update(mid + 1, nr, DXB(p));
	pushup(p);
}

int query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
		return max_ans[p];
	pushdown(p);
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans = max(query(nl, mid, DXA(p)), ans);
	if(mid < r)  ans = max(query(mid + 1, nr, DXB(p)), ans);
	return ans;
}

int n, q;

int main()
{
	scanf("%d %d", &n, &q);
	pre(1, n, 1);
	while(q --)
	{
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			case 2:
				scanf("%d %d %d", &l, &r, &val);
				update(1, n, 1);
				break;
			case 3:
				scanf("%d %d", &l, &r);
				printf("%d\n", query(1, n, 1));
				break;
			default:
				//assert(op == 1 || op == 2 || op == 3);
				break;
		}
	}
	return 0;
}
/*
5 8 
1 3 2 5 4 
3 1 3
2 1 1 5 
3 1 3 
1 1 4 6 
2 3 4 1 
3 2 3
2 2 3 4 
3 1 5
*/
