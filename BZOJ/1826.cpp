#define NOSTDCPP
//#define Cpp11
#define Linux_System
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

struct node
{
    int fir, sec;
    node (int fir = 0, int sec = 0) : fir(fir), sec(sec) {}
    bool operator < (const node &b) const
    {
        if(fir == b.fir)return sec < b.sec;
        return fir < b.fir;
    }
};

priority_queue <node> pq;

int nxt[maxn], pre[maxn];
int data[maxn], data2[maxn];
short hasit[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("swap.in", "r", stdin);
	//freopen("swap.out", "w", stdout);
	int n, m;
	scan_d(n);
	scan_d(m);
	//scanf("%d %d", &n, &m);
	RESET_(pre, -1);
	for(int i = 1; i <= n; i ++)
		scan_d(data[i]);
	//	scanf("%d", &data[i]);
	memcpy(data2 + 1, data + 1, sizeof(int) * n);
	sort(data2 + 1, data2 + 1 + n);
	int p = unique(data2 + 1, data2 + 1 + n) - data2 - 1;
	for(int i = 1; i <= n; i ++)
		data[i] = find(data2 + 1, data2 + 1 + p, data[i]) - data2;
	for(int i = n; i >= 1; i --)
    {
        if(pre[data[i]] == -1)nxt[i] = n + 1;
        else nxt[i] = pre[data[i]];
        pre[data[i]] = i;
    }
	//for(int i = 1; i <= n; i ++)
	//	cout << nxt[i].fi << ' ' << nxt[i].se << endl;
	node tmp;
	int ans = 0, size = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(hasit[data[i]])
		{
			pq.push(node(nxt[i], data[i]));
			continue;
		}
		hasit[data[i]] = 1;
		ans ++;
		if(size == m)
		{
			tmp = pq.top();
			pq.pop();
			hasit[tmp.sec] = 0;
			size --;

		}
		pq.push(node(nxt[i], data[i]));
		size ++;
	}
	out_number(ans);
	puts("");
	return 0;
}
/*
6 2
1 2 3 1 2 3
10 3
1 3 4 2 5 3 1 4 5 6
6 3
1 3 2 3 5 1
*/

