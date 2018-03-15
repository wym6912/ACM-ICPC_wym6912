#define NOSTDCPP
//#define Cpp11
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
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 900090;
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

typedef struct
{
	ll lsum, rsum, sum, lazy;
}node;

node tree[maxm];
int n, m;

void pushup(int p, int l, int r)
{
	if(l < r)
	{
		tree[p].lsum = tree[DXA(p)].lsum;
		tree[p].rsum = tree[DXB(p)].rsum;
		int mid = midf(l, r);
		if(tree[p].lsum == mid - l + 1) //p 结点的左孩子连续
			tree[p].lsum += tree[DXB(p)].lsum;
		if(tree[p].rsum == r - mid) //p 结点的右孩子连续
			tree[p].rsum += tree[DXA(p)].rsum;
		tree[p].sum = max(max(tree[DXA(p)].sum, tree[DXB(p)].sum), 
		                  tree[DXA(p)].rsum + tree[DXB(p)].lsum);
		//sum 值求的是最长连续子区间长度:
		//左儿子的sum值，右儿子的sum值 ，左儿子的rsum值+右儿子的lsum值
	}
}

void pushdown(int p, int l, int r)
{
	//-1 表示不更新
	if(~ tree[p].lazy)
	{
		int mid = midf(l, r);
		tree[DXA(p)].lazy = tree[DXB(p)].lazy = tree[p].lazy;
		tree[DXA(p)].sum = tree[DXA(p)].lsum = tree[DXA(p)].rsum 
		= tree[p].lazy * (mid - l + 1);
		//更新左子树：住人/不住人的长度为 mid - l + 1 
		tree[DXB(p)].sum = tree[DXB(p)].lsum = tree[DXB(p)].rsum 
		= tree[p].lazy * (r - mid);
		//更新右子树：住人/不住人的长度为 r - mid
		tree[p].lazy = -1;
	}
}

void pre(int l, int r, int p)
{
	tree[p].lazy = -1;
	if(l == r)
	{
		tree[p].sum = tree[p].lsum = tree[p].rsum = 1;
		// 默认是没有住人的 
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p, l, r);
}

void update(int l, int r, int nl, int nr, int val, int p)
//update 函数: val = 0 表示 [l, r] 已经住人，val = 1 表示 [l, r] 没有住人 
{
	if(l <= nl && nr <= r)
	{
		tree[p].lazy = val;
		tree[p].sum = tree[p].rsum = tree[p].lsum = val * (nr - nl + 1);
		//一定要更新 tree[p] 附加的信息！ 
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid)update(l, r, nl, mid, val, DXA(p));
	if(mid < r) update(l, r, mid + 1, nr, val, DXB(p));
	pushup(p, nl, nr);
}

ll query(int nl, int nr, int rq, int p)
{
	if(nl == nr) //边界条件：nl == nr ，递归到这里一定属于一个连续的区间 
		return nl;
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(tree[DXA(p)].sum >= rq) // [l, mid] 的总和比需要的大 
		return query(nl, mid, rq, DXA(p));
	else if(tree[DXA(p)].rsum + tree[DXB(p)].lsum >= rq) 
	// 跨越 [l, mid] (mid, r] 有一段符合要求的连续区间 
		return mid - tree[DXA(p)].rsum + 1;
	else 
	// (mid, r] 才有一段符合要求的连续区间 
		return query(mid + 1, nr, rq, DXB(p));
}

struct node2
{
	int start, end;
	bool operator < (const node2 &b) const
	{
		return start < b.start || (start == b.start && end < b.end);
	}
}ss[maxm];

int main()
{
	int f, t, dp, first = 0;
	set <int> st;
	set <node2> snode;
	set <int> :: iterator it;
	set <node2> :: iterator itn;
	char ri[10];
	while(scanf("\n%d %d", &n, &m) == 2)
	{
		ss[0].start = ss[0].end = n + 1;
		ss[m + 2].start = ss[m + 2].end = 0;
		pre(1, n, 1);
		st.clear();
		snode.clear();
		st.insert(n + 1);
		snode.insert(ss[0]);
		snode.insert(ss[m + 2]);
		for(int queryn = 1; queryn <= m; queryn ++)
		{
			scanf("\n%s", ri);
			switch(ri[0])
			{
				case 'N':
					scan_d(f);
					if(tree[1].sum < f) //连续区间长度小于 f 
					{
						puts("Reject New");
						continue;
					}
					t = query(1, n, f, 1);
					printf("New at ");
					out_number(t);
					puts("");
					update(t, t + f - 1, 1, n, 0, 1);
					ss[queryn].start = t;
					ss[queryn].end   = t + f - 1;
					snode.insert(ss[queryn]);
					st.insert(t);
					break;
				case 'F':
					scan_d(f);
					it = st.lower_bound(f);
					if(it != st.end()) 
					{
						//明天再写个映射 
						ss[queryn].start = f;
						ss[queryn].end = 0;
						itn = snode.lower_bound(ss[queryn]); 
						if(!((*itn).start <= f && f <= (*itn).end))itn --;
						//for(set <node2> :: iterator itn2 = snode.begin(); itn2 != snode.end(); itn2 ++)
						//	cout << (*itn2).start << ' ' << (*itn2).end << endl;
						//cout << (*itn).start << endl;
						ss[queryn] = *itn;
						if(itn == snode.end() || !(ss[queryn].start <= f && f <= ss[queryn].end))
						{
							puts("Reject Free");
							break;
						}
						update(ss[queryn].start, ss[queryn].end, 1, n, 1, 1);
						printf("Free from %d to %d\n", ss[queryn].start, ss[queryn].end);
						snode.erase(*itn);
						st.erase((*itn).start);
					}
					else puts("Reject Free");
					break;
				case 'R':
					update(1, n, 1, n, 1, 1);
					puts("Reset Now");
					st.clear();
					snode.clear();
					snode.insert(ss[0]);
					snode.insert(ss[m + 2]);
					st.insert(n + 1);
					break;
				case 'G':
					scan_d(f);
					if(f < (int)st.size())
					{
						it = st.begin();
						while(-- f)it ++;
						printf("Get at ");
						out_number(*it);
						puts("");
					}
					else 
						puts("Reject Get");
					break;
				default:
					assert(false);
			}
		}
		puts("");
	}
	return 0;
}

/*
6 10
New 2
New 5
New 2
New 2
Free 3
Get 1
Get 2
Get 3
Free 3
Reset
10 11
New 2
Free 6
New 4
New 4
Free 10
New 1
New 2
New 5
Free 4
New 5
Get 3
6 32
New 1
Free 2
Get 6
New 1
New 1
Free 1
New 3
New 4
New 5
New 2
Get 2
Get 1
New 3
New 4
Get 6
Get 1
New 3
New 4
New 5
New 1
New 2
Get 3
Free 6
Free 3
Free 3
Get 1
New 4
New 6
Free 1
Get 1
New 3
New 3
6 20
New 2
New 5
New 2
New 2
Free 3
Get 1
Get 2
Get 3
Free 3
Reset
New 2
New 5
New 2
New 2
Free 3
Get 1
Get 2
Get 3
Free 3
Reset
10 13
New 2
New 3
Free 4
New 4
New 3
New 2
New 1
Get 2
Get 3
Get 4
Get 5
Free 8
New 2
6 23
New 2
New 5
New 2
New 2
Free 3
Free 4
Get 1
Get 2
Get 3
Free 3
Reset
New 2
New 4
Get 2
Free 2
Get 2
Get 1
Free 3
New 6
Get 2
Get 1
Free 3
Get 1
*/

