//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
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

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 2000009;
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
	ll f, t;
	bool con;
	bool operator < (const node &b) const
	{
		return con > b.con;
	}
}node;

node query[maxn];
int father[maxn];
int n;
ll seq[maxn];
ll x[maxn];

void discrete()
{
	x[0] = 0;
	sort(seq + 1, seq + seq[0]); //ע�ⷶΧ 
	for(int i = 1; i <= seq[0]; i ++) //��ɢ������д�� 
		if(i == 1|| seq[i] != seq[i - 1])
			x[++ x[0]] = seq[i];
}

int qp(ll p)
{
	return lower_bound(x + 1, x + x[0], p) - x;	
}

int find(int x){return x == father[x] ? x : father[x] = find(father[x]);}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
	{
		father[x] = y;
	}
}

int main()
{
	int T;
	scan_d(T);
	while(T --)
	{
		scan_d(n);
		seq[0] = 0;
		for(int i = 1; i <= (n << 1); i ++)
			father[i] = i;
		for(int i = 1; i <= n; i ++)
		{
			scan_d(query[i].f);
			scan_d(query[i].t);
			scan_d(query[i].con);
			seq[++ seq[0]] = query[i].f;
			seq[++ seq[0]] = query[i].t;
		}
		discrete();
		int i;
		for(i = 1; i <= n; i ++)
		{
			if(query[i].con)
				merge(qp(query[i].f), qp(query[i].t));
		}
		bool flag = true;
		for(i = 1; i <= n; i ++)
		{
			if(! query[i].con)
				if(find(qp(query[i].f)) == find(qp(query[i].t)))
				{
					flag = false;
					break;
				}
		}
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}
/*
2
2
1 2 1
1 2 0
2
1 2 1
2 1 1
*/
