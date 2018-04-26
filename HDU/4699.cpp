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
const int maxn = 1000009;
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

ll data[maxn], pre[maxn], dp[maxn];
stack <ll> st, st2;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, t, c;
	ll f;
	char ch;
	while(scanf("%d", &T) == 1)
    {
        c = 0;
        dp[0] = -1000000000;
        pre[0] = 0;
        while(! st.empty())st.pop();
        while(! st2.empty())st2.pop();
        while(T --)
        {
            scanf(" %c", &ch);
            switch(ch)
            {
                case 'I':
                    scanf("%lld", &f);
                    st2.push(f);
                    data[++ c] = f;
                    pre[c] = pre[c - 1] + data[c];
                    dp[c] = max(pre[c], dp[c - 1]);
                    break;
                case 'D':
                    if(! st2.empty())st2.pop(), c --;
                    break;
                case 'L':
                    if(! st2.empty())
                    {
                        st.push(st2.top());
                        c --;
                        st2.pop();
                    }
                    break;
                case 'R':
                    if(! st.empty())
                    {
                        st2.push(st.top());
                        data[++ c] = st.top();
                        pre[c] = pre[c - 1] + data[c];
                        dp[c] = max(pre[c], dp[c - 1]);
                        st.pop();
                    }
                    break;
                case 'Q':
                    scanf("%d", &t);
                    out_number(dp[t]);
                    puts("");
                    break;
                default:
                    assert(ch == 'I' || ch == 'D' || ch == 'L' || ch == 'R' || ch == 'Q');
            }
        }
    }
	return 0;
}
/*
9
I 612
I 565
I 315
Q 1
L
L
I -523
R
Q 3

*/
