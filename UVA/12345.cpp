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
const int maxn = 100009;
const int maxm = 1000007;
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

int n, m, unit, cnt_q = 0, cnt_m = 1;

struct query
{
	int L, R, id, t;
	bool operator < (const query &b) const
	{
		if(L / unit == b.L / unit && R == b.R)return t < b.t;
		if(L / unit == b.L / unit)return R < b.R;
		return L / unit < b.L / unit;
	}
}qqq[maxn];

struct time
{
	ll pre, now, pos;
}ttt[maxn];

ll ans[maxn], tmp[maxm], data[maxn], last_version[maxn];

void modify_modui()
{
	int L = 1, R = 1, T = 1, temp = ++ tmp[data[1]];
	for(int i = 1; i <= cnt_q; i ++)
	{
	/*
		for(int j = T + 1; j <= qqq[i].t; j ++) //???????????
		{
			if(L <= ttt[j].pos && ttt[j].pos <= R)
			{
				temp -= (-- tmp[data[ttt[j].pos]] == 0);
                temp += (++ tmp[ttt[j].now] == 1);
			}
			data[ttt[j].pos] = ttt[j].now;
		}
		for(int j = T; j > qqq[i].t; j --)
		{
			if(L <= ttt[j].pos && ttt[j].pos <= R)
			{
				temp -= (-- tmp[data[ttt[j].pos]] == 0);
                temp += (++ tmp[ttt[j].pre] == 1);
			}
			data[ttt[j].pos] = ttt[j].pre;
		}
		for(int j = L; j < qqq[i].L; j ++)
			temp -= (-- tmp[data[j]] == 0);
		for(int j = L - 1; j >= qqq[i].L; j --)
			temp += (++ tmp[data[j]] == 1);
		for(int j = R + 1; j <= qqq[i].R; j ++)
			temp += (++ tmp[data[j]] == 1);
		for(int j = R; j > qqq[i].R; j --)
			temp -= (-- tmp[data[j]] == 0);
		ans[qqq[i].id] = temp;
		L = qqq[i].L;
		R = qqq[i].R;
		T = qqq[i].t;
		*/
		while(T < qqq[i].t)
		{
			T ++;
			if(L <= ttt[T].pos && ttt[T].pos <= R)
			{
				temp -= (-- tmp[data[ttt[T].pos]] == 0);
                temp += (++ tmp[ttt[T].now] == 1);
			}
			data[ttt[T].pos] = ttt[T].now;
		}
		while(T > qqq[i].t)
		{
			if(L <= ttt[T].pos && ttt[T].pos <= R)
			{
				temp -= (-- tmp[data[ttt[T].pos]] == 0);
                temp += (++ tmp[ttt[T].pre] == 1);
			}
			data[ttt[T].pos] = ttt[T].pre;
			T --;
		}
		while(R < qqq[i].R)
		{
			R ++;
			temp -= tmp[data[R]] >= 1;
			tmp[data[R]] ++;
			temp += tmp[data[R]] >= 1;
		}
		while(R > qqq[i].R)
		{
			temp -= tmp[data[R]] >= 1;
			tmp[data[R]] --;
			temp += tmp[data[R]] >= 1;
			R --;
		}
		while(L < qqq[i].L)
		{
			temp -= tmp[data[L]] >= 1;
			tmp[data[L]] --;
			temp += tmp[data[L]] >= 1;
			L ++;
		}
		while(L > qqq[i].L)
		{
			L --;
			temp -= tmp[data[L]] >= 1;
			tmp[data[L]] ++;
			temp += tmp[data[L]] >= 1;
		}
		ans[qqq[i].id] = temp;
	}
}

int main()
{
	char ch;
	ll f, t;
	scan_d(n);
	scan_d(m);
	//freopen("maintain.in", "r", stdin);
	//freopen("maintain.out", "w", stdout);
	//scanf("%d %d", &n, &m);
	unit = (int)pow(n, 2.0 / 3.0);
	for(int i = 1; i <= n; i ++)
	{
		//scanf("%lld", &data[i]);
		scan_d(data[i]);
		last_version[i] = data[i];
	}
	for(int i = 1; i <= m; i ++)
	{
		//scanf("\n%c %lld %lld", &ch, &f, &t);
		scan_ch(ch);
		scan_d(f);
		scan_d(t);
		switch(ch)
		{
			case 'Q':
				++ cnt_q;
				qqq[cnt_q].L = f + 1;
				qqq[cnt_q].R = t;
				qqq[cnt_q].id = cnt_q;
				qqq[cnt_q].t = cnt_m;
				break;
			case 'M':
				++ cnt_m;
				ttt[cnt_m].pos = f + 1;
				ttt[cnt_m].pre = last_version[f + 1];
				ttt[cnt_m].now = t;
				last_version[f + 1] = t;
				break;
			default:
				assert(ch == 'Q' || ch == 'M');
		}
	}
	sort(qqq + 1, qqq + 1 + cnt_q);
	modify_modui();
	for(int i = 1; i <= cnt_q; i ++)
		out_number(ans[i]), puts("");
	return 0;
}

/*
30 30
1 8 7 3 6 4 7 2 1 6 10 3 2 5 4 1 5 9 7 5 8 2 3 8 7 1 2 1 2 5
Q 19 25
Q 11 15
Q 16 28
M 0 9
Q 1 16
Q 5 7
M 29 3
Q 6 8
Q 4 20
M 5 1
M 27 7
M 27 9
M 17 7
M 0 9
Q 6 29
M 28 9
Q 10 19
M 5 2
M 17 1
M 21 2
Q 16 29
M 27 8
Q 10 14
M 14 6
M 7 8
Q 14 24
Q 6 22
M 19 1
M 21 2
M 21 7
*/
