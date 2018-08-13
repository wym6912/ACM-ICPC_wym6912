#define NOSTDCPP
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

const int maxNode = 444444;

struct Treap
{
	int root, treapCnt, key[maxNode], priority[maxNode],
		childs[maxNode][2], cnt[maxNode], size[maxNode],
		nodeid;
	
	Treap()
	{
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}
	
	void update(int x)
	{
		size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
	}
	
	void rorate(int &x,int t)
	{
		int y = childs[x][t];
		childs[x][t] = childs[y][1 - t];
		childs[y][1 - t] = x;
		update(x);
		update(y);
		x = y;
	}
	
	void __insert__(int &x,int k)
	{
		if(x)
		{
			if(key[x] == k)
				cnt[x] ++;
			else
			{
				int t = (key[x] < k);
				__insert__(childs[x][t], k);
				if(priority[childs[x][t]] < priority[x])
					rorate(x, t);
			}
		}
		else 
		{
			x = treapCnt ++;
			key[x] = k;
			cnt[x] = 1;
			priority[x] = rand();
			childs[x][0] = childs[x][1] = 0;
		}
		update(x);
	}
	
	void __erase__(int &x, int k)
	{
		if(key[x] == k)
		{
			if(cnt[x] > 1) cnt[x] --;
			else
			{
				if(! childs[x][0] && ! childs[x][1])
				{
					x = 0;
					return;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rorate(x, t);
				__erase__(x, k);
			}
		}
		else __erase__(childs[x][key[x] < k], k);
		update(x);
	}
	
	int __getKth__(int &x,int k)
	{
		if(k <= size[childs[x][0]])
		{
			return __getKth__(childs[x][0], k);
		}
		k -= size[childs[x][0]] + cnt[x];
		if(k <= 0)return key[x];
		return __getKth__(childs[x][1], k);
	}
	
	int __getRank__(int &x, int k)
	{
		if(x == 0) return 0;
		if(k == key[x]) return size[childs[x][0]] + 1;
		if(k < key[x]) return __getRank__(childs[x][0], k);
		return size[childs[x][0]] + cnt[x] + __getRank__(childs[x][1], k);
	}
	
	void __getPre__(int &x, int k)
	{
		if(x == 0) return ;
		if(key[x] < k)
		{
			nodeid = x;
			__getPre__(childs[x][1], k);
		}
		else __getPre__(childs[x][0], k);
	}	
	
	void __getNext__(int &x, int k)
	{
		if(x == 0) return ;
		if(key[x] > k)
		{
			nodeid = x;
			__getNext__(childs[x][0], k);
		}
		else __getNext__(childs[x][1], k);
	}

	void insert(int k)
	{
		__insert__(root, k);
	}
	
	int getKth(int k)
	{
		return __getKth__(root, k);
	}
	
	void reset()
	{
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}
	
	int getNext(int k)
	{
		nodeid = 0;
		__getNext__(root, k);
		return key[nodeid];
	}
	
	int getPre(int k)
	{
		nodeid = 0;
		__getPre__(root, k);
		return key[nodeid];
	}
	
	int getRank(int k)
	{
		return __getRank__(root, k);
	}	
	
	void erase(int k)
	{
		__erase__(root, k);
	}
}treap;

int data[10000007];

int main()
{
	int cmd, k, p, cnt;
	srand(*new int);
	while(scanf("%d", &cmd))
	{
		switch(cmd)
		{
			case 0:
				exit(0);
			case 1:
				scanf("%d %d", &p, &k);
				data[k] = p;
				treap.insert(k);
				cnt ++;
				break;
			case 2:
				if(cnt < 1)
				{
					printf("%d\n", 0);
					break;
				}
				k = treap.getKth(cnt);
				printf("%d\n", data[k]);
				treap.erase(k);
				data[k] = 0;
				cnt --;
				break;
			case 3:
				if(cnt < 1)
				{
					printf("%d\n", 0);
					break;
				}
				k = treap.getKth(1);
				printf("%d\n", data[k]);
				treap.erase(k);
				data[k] = 0;
				cnt --;
				break;
			default:
				assert(cmd == 0 || cmd == 1 || cmd == 2 || cmd == 3);
		}
	}
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
*/
