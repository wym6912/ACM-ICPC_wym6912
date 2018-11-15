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
# define mp make_pair
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) (((_) << 1))
# define DXB(_) (((_) << 1) | 1)

# define next __Chtholly__
# define distance __Mercury__
# define y1 __bbtl04__
# define fpos __ikooo__

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100009;
const int maxm = 200009;
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

int n, m, cnt, cnt_hld, cnt_pl;
int fir[maxn], dfs_time[maxn << 1], deep[maxn], fpos[maxn], pos[maxn];
int st2[maxn << 1][21], log_2[maxn << 1], father[maxn];
int siz[maxn], pos2[maxn];
int dis[maxn];

struct edg
{
    int to, next, val;
}edg1[maxn << 1];

inline void addedge(int f, int t, int val)
{
    edg1[++ cnt].to = t;
    edg1[cnt].next = fir[f];
    edg1[cnt].val = val;
    fir[f] = cnt;
}

void dfs1(int u)
{
    siz[u] = 1;
    pos[u] = ++ cnt_pl;
    fpos[cnt_pl] = u;
    dfs_time[++ cnt_hld] = u;
    pos2[u] = cnt_hld;
    for(register int i = fir[u], v; i; i = edg1[i].next)
        if((v = edg1[i].to) != father[u])
        {
        	father[v] = u;
        	deep[v] = deep[u] + 1;
            dis[v] = dis[u] + edg1[i].val;
            dfs1(v);
            dfs_time[++ cnt_hld] = u;
            siz[u] += siz[v];
        }
}

inline void rmqinit()
{
    for(register int i = 1; i <= cnt_hld; ++ i)
        st2[i][0] = dfs_time[i];
    for(register int i = 1; i <= 20; ++ i)
        for(register int j = 1; j + (1 << i) - 1 <= cnt_hld; ++ j)
        {
            if(deep[st2[j][i - 1]] < deep[st2[j + (1 << (i - 1))][i - 1]])
                st2[j][i] = st2[j][i - 1];
            else st2[j][i] = st2[j + (1 << (i - 1))][i - 1];
        }
}

inline int RMQ(int x, int y)
{
	if(x > y) swap(x, y);
    int a = log_2[y - x + 1];
    if(deep[st2[x][a]] < deep[st2[y - (1 << a) + 1][a]])
        return st2[x][a];
    return st2[y - (1 << a) + 1][a];
}

inline int distance(int x, int y)
{
    int LCA = RMQ(pos2[x], pos2[y]);
    return dis[x] + dis[y] - (dis[LCA] << 1);
}

int tree[maxn << 2][2];

inline void __make(int &ans, int &s1, int &s2, int v1, int v2)
{
    ans = distance(v1, v2), s1 = v1, s2 = v2;
}

inline void __pushup(int &s1, int &s2, int a1, int a2, int b1, int b2)
{
    int ans = 0;
    if(ans < distance(a1, a2)) __make(ans, s1, s2, a1, a2);
    if(ans < distance(a1, b1)) __make(ans, s1, s2, a1, b1);
    if(ans < distance(a2, b2)) __make(ans, s1, s2, a2, b2);
    if(ans < distance(a1, b2)) __make(ans, s1, s2, a1, b2);
    if(ans < distance(a2, b1)) __make(ans, s1, s2, a2, b1);
    if(ans < distance(b1, b2)) __make(ans, s1, s2, b1, b2);
}

inline void pushup(int p)
{
    __pushup(tree[p][0], tree[p][1], tree[DXA(p)][0], tree[DXA(p)][1], tree[DXB(p)][0], tree[DXB(p)][1]);
}

void pre(int l, int r, int p)
{
    if(l == r)
    {
        tree[p][0] = tree[p][1] = fpos[l];
        return ;
    }
    int mid = midf(l, r);
    pre(l, mid, DXA(p));
    pre(mid + 1, r, DXB(p));
    pushup(p);
}

int l, r, ans1, ans2;
void query(int nl, int nr, int p)
{
    if(l <= nl && nr <= r)
    {
        __pushup(ans1, ans2, tree[p][0], tree[p][1], ans1, ans2);
        return ;
    }
    int mid = midf(nl, nr);
    if(l <= mid) query(nl, mid, DXA(p));
    if(mid < r)  query(mid + 1, nr, DXB(p));
}

struct edg_2
{
    int f, t;
    edg_2(int f = -1, int t = -1) : f(f), t(t) {}
}edg2[maxn];

int tmp, val;
inline void makeans(int l1, int r1, int l2, int r2, int l3, int r3, int &ans)
{
    int aa, bb, aaa, bbb;
    if(l1 <= r1)
    {
	    l = l1, r = r1;
	    ans1 = ans2 = 0;
	    query(1, n, 1);
	    aa = ans1, bb = ans2;
	}
	if(l2 <= r2)
	{
	    l = l2, r = r2;
	    ans1 = ans2 = 0;
	    query(1, n, 1);
	    aaa = ans1, bbb = ans2;
	}
	if(l3 <= r3)
	{
	    l = l3, r = r3;
	    ans1 = ans2 = 0;
	    query(1, n, 1);
	}
    __pushup(aaa, bbb, aaa, bbb, aa, bb);
    __pushup(ans1, ans2, aaa, bbb, ans1, ans2);
    if(ans < distance(ans1, ans2)) ans = distance(ans1, ans2);
}

inline void makeans(int l1, int r1, int l2, int r2, int &ans)
{
    int aa, bb;
    l = l1, r = r1;
    ans1 = ans2 = 0;
    query(1, n, 1);
    aa = ans1, bb = ans2;
    l = l2, r = r2;
    ans1 = ans2 = 0;
    query(1, n, 1);
    __pushup(ans1, ans2, ans1, ans2, aa, bb);
    if(ans < distance(ans1, ans2)) ans = distance(ans1, ans2);
}

inline void makeans(int l1, int r1, int &ans)
{
    l = l1, r = r1;
    ans1 = ans2 = 0;
    query(1, n, 1);
    if(ans < distance(ans1, ans2)) ans = distance(ans1, ans2);
}

int main()
{
    //freopen("14.in", "r", stdin);
    int T;
    //scanf("%d", &T);
    int ans;
    log_2[1] = 0;
    for(register int i = 2; i < (maxn << 1); ++ i)
    {
        if((1 << (log_2[i - 1] + 1)) < i) log_2[i] = log_2[i - 1] + 1;
        else log_2[i] = log_2[i - 1];
    }
    //scanf("%d %d", &n, &m);
    scan_d(n); scan_d(m);
    RESET(fir);
    cnt = cnt_hld = cnt_pl = 0;
    for(register int i = 1, f, t; i < n; ++ i)
    {
        //scanf("%d %d %d", &f, &t, &val);
        scan_d(f), scan_d(t), scan_d(val);
        edg2[i] = edg_2(f, t);
        addedge(f, t, val);
        addedge(t, f, val);
    }
    dis[1] = 0;
    deep[1] = father[1] = 0;
    dfs1(1);
    rmqinit();
    pre(1, n, 1);
    ans = 0;
    for(register int i = 1; i < n; ++ i)
    {
        if(deep[edg2[i].f] > deep[edg2[i].t])
            swap(edg2[i].f, edg2[i].t);
    }
    for(register int Case = 1, f, t, w, sx, ex, sy, ey; Case <= m; ++ Case)
    {
        //scanf("%d %d", &f, &t);
        scan_d(f), scan_d(t);
        ans = 0;
        f = edg2[f].t, t = edg2[t].t;
        w = RMQ(pos2[f], pos2[t]);
        if(f == w || t == w)
        {
            if(f != w) swap(t, f);
            sx = pos[f], ex = pos[f] + siz[f] - 1;
            sy = pos[t], ey = pos[t] + siz[t] - 1;
            
            makeans(1, sx - 1, ex + 1, n, ans);
            makeans(sx, sy - 1, ey + 1, ex, ans);
            makeans(sy, ey, ans);
        }
        else 
        {
            if(pos[f] > pos[t]) swap(f, t);
            sx = pos[f], ex = pos[f] + siz[f] - 1;
            sy = pos[t], ey = pos[t] + siz[t] - 1;
            
            makeans(1, sx - 1, ex + 1, sy - 1, ey + 1, n, ans);
            makeans(sx, ex, ans);
            makeans(sy, ey, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
8 3
2 1 7
3 1 7
4 2 5
5 2 6
4 6 3
7 2 8
1 8 2
4 6
2 3
5 6
*/
