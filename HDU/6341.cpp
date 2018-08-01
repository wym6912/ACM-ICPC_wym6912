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

int hang[17][17], lie[17][17];
int data[17][17], ans, rrt[17];
int tmpblock[5][5];

bool isok()
{
	RESET(hang);
	RESET(lie);
	for(int i = 1; i <= 16; i ++)
		for(int j = 1; j <= 16; j ++)
		{
			hang[i][data[i][j]] ++;
			lie [j][data[i][j]] ++;
		}
	for(int i = 1; i <= 16; i ++)
		for(int j = 1; j <= 16; j ++)
			if(! hang[i][j] || ! lie[i][j])
				return false;
	return true;
}

bool isok2(int block)
{
	block --;
	RESET(hang);
	for(int i = 1; i <= block; i ++)
		for(int j = 1; j <= 16; j ++)
		{
			//hang[i][data[i][j]] = true;
			hang[i][data[i][j]] ++;
		}
	for(int i = 1; i <= block; i ++)
		for(int j = 1; j <= 16; j ++)
			if(! hang[i][j])
				return false;
	return true;
}

void add(int block, int x)
{
	block --;
	int px = block / 4 * 4 + 1, py = (block % 4) * 4 + 1;
	for(int i = px; i <= px + 3; i ++)
		for(int j = py; j <= py + 3; j ++)
			hang[i][data[i][j]] += x, 
			lie[j][data[i][j]] += x;
}

bool rorate(int block)
{
	block --;
	int px = block / 4 * 4 + 1, py = (block % 4) * 4 + 1;
	//printf("Block = %d, px = %d, py = %d\nBefore\n", block, px, py);
	//for(int i = 1; i <= 4; i ++, puts(""))
	//	for(int j = 1; j <= 4; j ++)
	//		printf("%3d", data[px + i - 1][py + j - 1]);
	//puts("");
	for(int i = px; i <= px + 3; i ++)
		for(int j = py; j <= py + 3; j ++)
		{
			-- hang[i][data[i][j]], -- lie[j][data[i][j]];
		}
	for(int i = 1; i <= 4; i ++)
		for(int j = 1; j <= 4; j ++)
			tmpblock[i][j] = data[px + i - 1][py + j - 1];
	for(int i = 1; i <= 4; i ++)
		data[px + i - 1][py + 3] = tmpblock[1][i];
	for(int i = 1; i <= 4; i ++)
		data[px + i - 1][py + 2] = tmpblock[2][i];
	for(int i = 1; i <= 4; i ++)
		data[px + i - 1][py + 1] = tmpblock[3][i];
	for(int i = 1; i <= 4; i ++)
		data[px + i - 1][py + 0] = tmpblock[4][i];
	bool ok = true;
	for(int i = px; i <= px + 3; i ++)
		for(int j = py; j <= py + 3; j ++)
		{
			if((++ hang[i][data[i][j]] > 1) || (++ lie[j][data[i][j]] > 1)) 
				ok = false;
		}
	//printf("After\n");
	//for(int i = 1; i <= 4; i ++, puts(""))
	//	for(int j = 1; j <= 4; j ++)
	//		printf("%3d", data[px + i - 1][py + j - 1]);
	return ok;
}

void print2()
{
	for(int u = 1; u <= 16; u ++)
		printf("%d ", rrt[u]);
	printf("\n");
}

void dfs(int block, int sum, int xx)
{
	rrt[block - 1] = xx;
	if(block == 17)
	{
		if(isok()) ans = min(ans, sum);
		return ;
	}
	//if(block % 4 == 1 && block != 1)
	//	if(! isok2(block))
	//		return ;
	if(block != 0) add(block, 1);
	if(sum >= ans) return ;
	bool isok = true;
	for(int i = 1; i <= 4; i ++)
	{
		isok = rorate(block);
		if(isok) dfs(block + 1, sum + (i % 4), i % 4);
	}
	if(block != 0) add(block, -1);
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	//freopen("j.in", "r", stdin);
	//freopen("j.out", "w", stdout);
	scanf("%d", &T);
	while(T --)
	{
		RESET(rrt);
		RESET(hang);
		RESET(lie);
		for(int i = 1; i <= 16; i ++)
			for(int j = 1; j <= 16; j ++)
				scanf("%1x", &data[i][j]), data[i][j] ++;
		//for(int i = 1; i <= 16; i ++, puts(""))
		//	for(int j = 1; j <= 16; j ++)
		//		printf("%3d", data[i][j]);
		//for(int i = 1; i <= 16; i ++)
		//	rorate(i);
		ans = 50;
		dfs(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
/*
2
DC0342B1843CC3A1
694AFC63A5677DF6
E2750879F1B2289B
BF18DEA50ED9405E
A7C47AFC9B4F8F9A
39DFD48EE8C5C346
02E8165363A2E01B
61B52B09D1075D72
FA7947C672FA2D6C
153B2BEFE40C71E0
6C4891A5596D358A
D02E3D8083B149FB
E4281F835F7C8E06
F7CDCAD419EA9C42
A1B0027B0D86D5FA
5369695EB2347B31
09E77C30D358D8F5
8DC2A28DF76A9E76
13F5954E4C0BB103
4B6A61FBE219C24A
6A5D54D14ADC3618
E20CEF6339504DC0
74980CB9E2812AE5
BF31A78267FB9B7F
2ABDC02E2DB552F7
C7384B89C4A76AB3
965E71DAFE699D18
F410F5360813E40C
BFA48A6973420FB1
7806F054DBE6A7C8
3129BDEC1F9A4532
E5DC37215C08E96D
*/
