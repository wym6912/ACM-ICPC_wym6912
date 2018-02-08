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
# define mid(x, y) ((x + y) >> 1)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 300009;
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
	int l, r;
	int sum;
}node;

node tree[maxn];
int n;
int data[maxn];

void pre(int l, int r, int p)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r){scanf("%d", &tree[p].sum);return ;}
	else
	{
		int mid = (l + r) >> 1;
		pre(l, mid, p << 1);
		pre(mid + 1, r, (p << 1) | 1);
		tree[p].sum = tree[p << 1].sum + tree[(p << 1) | 1].sum;
	}
}

ll query(int l, int r, int nl, int nr, int p) // [l, r] \in [nl, nr]
{
    if(nr < nl)return 0;
	ll ans = 0;
	int mid = (nl + nr) >> 1;
	if(l <= nl && nr <= r)return tree[p].sum; //被完全包围
	//if((nl <= l && mid >= l) || (mid >= r && nl <= r)) // [nl, mid] 包括 [l, r]
	if(l <= mid)
	{
		ans += query(l, r, nl, mid, p << 1);
	}
	//if((mid <= l && nr >= l) || (mid >= l && nl >= r))
	if(mid < r)
	{
		ans += query(l, r, mid + 1, nr, (p << 1) | 1);
	}
	return ans;
}

void update(int nl, int nr, int px, int ans, int p)
{
    if(nr < nl)return ;
	if(px == nr && nl == px)
	{
		tree[p].sum += ans;
		return ;
	}
	else
	{
		//if(nr > px || nl < px)return ;
		int mid = (nl + nr) >> 1;
		if(nl <= px && px <= mid)update(nl, mid, px, ans, p << 1);
		if(mid < px && px <= nr)update(mid + 1, nr, px, ans, (p << 1) | 1);
		tree[p].sum = tree[p << 1].sum + tree[(p << 1) | 1].sum;
	}
}

int main()
{
	int T, a, b;
	char info[6];
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; Casen ++)
	{
		printf("Case %d:\n", Casen);
		scanf("%d", &n);
		RESET(tree);
		pre(1, n, 1);
		info[0] = 'A';
		while(info[0] != 'E')
		{
			scanf("\n%s", info);
			switch(info[0])
			{
				case 'Q':
					scanf("%d%d", &a, &b);
					printf("%lld\n", query(a, b, 1, n, 1));
					break;
				case 'A':
					scanf("%d%d", &a, &b);
					update(1, n, a, b, 1);
					break;
				case 'S':
					scanf("%d%d", &a, &b);
					update(1, n, a, -b, 1);
				case 'E':
					break;
				default:
					assert(false);
			}
			//cout << "OUT THE TREE" << endl;
			//for(int i = 1; i <= 4 * n; i ++)
			//	cout << tree[i].l << ' ' << tree[i].r << ' ' << tree[i].sum << endl;
		}
	}
	return 0;
}

