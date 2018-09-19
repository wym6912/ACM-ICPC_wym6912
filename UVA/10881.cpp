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

struct Ants
{
	int direction, place, id;
	bool operator < (const Ants &b) const
	{
		return place < b.place;
	}
}before[maxn], now[maxn];

int place[maxn];

int main()
{
	//freopen("10881.in", "r", stdin);
	//freopen("10881.txt", "w", stdout);
	int T, len, time, ant, pl;
	char dir;
	scanf("%d", &T);
	for(int Casen = 1; Casen <= T; ++ Casen)
	{
		scanf("%d %d %d", &len, &time, &ant);
		for(int i = 1; i <= ant; ++ i)
		{
			scanf("%d %c", &pl, &dir);
			before[i].direction = dir == 'L' ? -1 : 1;
			before[i].id = i;
			before[i].place = pl;
			now[i].direction = dir == 'L' ? -1 : 1;
			now[i].place = pl + time * now[i].direction;
		}
		
		sort(before + 1, before + 1 + ant);
		for(int i = 1; i <= ant; ++ i)
			place[before[i].id] = i;
		
		sort(now + 1, now + 1 + ant);
		//for(int i = 1; i <= ant; ++ i) printf("%d %d\n", i, now[i].place);
		for(int i = 1; i <= ant; ++ i)
		{
			if(now[i].place == now[i + 1].place)
				now[i].direction = 0, now[i + 1].direction = 0;
		}
		
		printf("Case #%d:\n", Casen);
		for(int i = 1; i <= ant; ++ i)
		{
			if(now[place[i]].place < 0 || now[place[i]].place > len) puts("Fell off");
			else {
				printf("%d %s\n", now[place[i]].place, now[place[i]].direction == 1 ? "R" : now[place[i]].direction == 0 ? "Turning" : "L");
			}
		}
		puts("");
	} 
	return 0;
}
/*
2
10 1 4
1 R
5 R
3 L
10 R
10 2 3
4 R
5 L
8 R
*/

