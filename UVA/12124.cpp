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
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 1009;
const int maxm = 300009;
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

struct cpt
{
	int price, quality;
	bool operator < (const cpt &b) const
	{
		return quality == b.quality ? price < b.price : quality < b.quality;
	}
};

int n, m;
map <string, int> mp;
int cnt;
int id(string token)
{
	if(mp.count(token)) return mp[token];
	mp[token] = ++ cnt;
	return cnt;
}

vector <cpt> vp[maxn];

bool ok(int mid)
{
	int p = 0, xx;
	for(int i = 1; i <= cnt; ++ i)
	{
		xx = 1e9 + 10;
		for(int j = 0; j < vp[i].size(); ++ j)
		{
			if(vp[i][j].quality >= mid)
				xx = min(xx, vp[i][j].price);
		}
		if(xx == 1e9 + 10) return false;
		p += xx;
	}
	//cout << mid << ' ' << p << endl;
	return m >= p;
}

int ans()
{
	int l = 0, r = 1e9, mid, ans = -1;
	while(l <= r)
	{
		mid = midf(l, r);
		if(ok(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	//freopen("12124.in", "r", stdin);
	//freopen("12124.out", "w", stdout);
	string token, extra;
	int T;
	cpt tmp;
	cin >> T;
	while(T --)
	{
		for(int i = 1; i <= cnt; ++ i) vp[i].clear();
		cnt = 0;
		mp.clear();
		cin >> n >> m;
		for(int i = 1; i <= n; ++ i)
		{
			cin >> token >> extra >> tmp.price >> tmp.quality;
			//cout << token << ' ' << extra << ' ' << tmp.price << ' ' << tmp.quality << endl;
			vp[id(token)].push_back(tmp);	
		}
		//for(int i = 1; i <= cnt; ++ i) sort(vp[i].begin(), vp[i].end());
		/*
		for(int i = 1; i <= cnt; ++ i)
		{
			cout << "\nxi = \n";
			for(vector <cpt> :: iterator it = vp[i].begin(); it != vp[i].end(); ++ it)
				cout << (*it).price << " " << (*it).quality << '\n';
		}
		*/
		cout << ans() << '\n';
	}
	return 0;
}
/*
1
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
*/

