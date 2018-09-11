#include <bits/stdc++.h>

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
	
const int inf = 1e9 + 7;
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
	
int n, m;
	
int ins[maxn << 2], unin[maxn << 2];
short rev[maxn << 2];
	
void pushup(int p)
{
	ins[p] = ins[DXA(p)] + ins[DXB(p)];
	unin[p] = unin[DXA(p)] + unin[DXB(p)];
}
	
void __rev(int p, short val, int len)
{
	rev[p] = val;
	if(val) ins[p] = len, unin[p] = 0;
	if(! val) ins[p] = 0, unin[p] = len;
}

void pushdown(int p, int l, int r)
{
	if(~ rev[p])
	{
		int mid = midf(l, r);
		__rev(DXA(p), rev[p], mid - l + 1);
		__rev(DXB(p), rev[p], r - mid);
		rev[p] = -1;
	}
}

void pre(int l, int r, int p)
{ 
	rev[p] = -1;
	if(l == r)
	{
		ins[p] = 0;
		unin[p] = 1;
		return ;
	}
	int mid = midf(l, r);
	pre(l, mid, DXA(p));
	pre(mid + 1, r, DXB(p));
	pushup(p);
}
	
int l, r;
bool inss;
int query(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(inss) return ins[p];
		else return unin[p];
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr), ans = 0;
	if(l <= mid) ans += query(nl, mid, DXA(p));
	if(mid < r)  ans += query(mid + 1, nr, DXB(p));
	return ans;
}
	
void update(int nl, int nr, int p)
{
	if(l <= nl && nr <= r)
	{
		if(inss) __rev(p, 1, nr - nl + 1);
		else __rev(p, 0, nr - nl + 1);
		return ;
	}
	pushdown(p, nl, nr);
	int mid = midf(nl, nr);
	if(l <= mid) update(nl, mid, DXA(p));
	if(mid < r)  update(mid + 1, nr, DXB(p));
	pushup(p);
}
	
struct Edge
{
    int to, next;
}edge[maxn << 1];
int head[maxn], tot, top[maxn], fa[maxn], deep[maxn], num[maxn], p[maxn], fp[maxn];
int son[maxn];
int pos;
	
void init()
{
    tot = 0;
    RESET_(head, -1);
    pos = 1;
    RESET_(son, -1);
    RESET_(deep, -1);
}
	
void addedge(int u,int v)
{
	edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
	
void dfs1(int u,int pre,int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}
	
void getpos(int u, int sp)
{
    top[u] = sp;
    if(son[u] != -1)
    {
        p[u] = pos++;
        fp[p[u]] = u;
        getpos(son[u],sp);
    }
    else
    {
        p[u] = pos++;
        fp[p[u]] = u;
        return;
    }
    for(int i = head[u] ; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v, v);
    }
}

void __update__(int u, int v)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        l = p[f1], r = p[u];
		update(1, n, 1);   
        u = fa[f1]; f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = p[u], r = p[v];
    //cout << ">>" << l << ' ' << r << endl;
    update(1, n, 1);
}

int __query__(int u, int v)
{
    int f1 = top[u], f2 = top[v], ans = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        l = p[f1], r = p[u];
		ans += query(1, n, 1);   
        u = fa[f1]; f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    l = p[u], r = p[v];
    ans += query(1, n, 1);
    return ans;
}

int main()
{
	//freopen("ex_manager3.in", "r", stdin);
	//freopen("ex_manager3.ans", "w", stdout);
	char str[10];
	int f;
	scanf("%d", &n);
	init();
	for(int i = 1; i < n; ++ i)
	{
		scanf("%d", &f);
		++ f;
		addedge(f, i + 1);
		addedge(i + 1, f);
	}
	dfs1(1, -1, 0);
	getpos(1, 1);
	pre(1, n, 1);
	scanf("%d", &m);
	while(m --)
	{
		scanf("%s %d", str, &f);
		switch(str[0])
		{
			case 'i':
				inss = false;
				printf("%d\n", __query__(1, ++ f));
				inss = !inss;
				__update__(1, f);
				break;
			case 'u':
				inss = true;
				++ f;
				l = p[f], r = num[f] + l - 1;
				printf("%d\n", query(1, n, 1));
				inss = !inss;
				update(1, n, 1);
				break;
			default:
				assert(str[0] == 'i' || str[0] == 'u');
		}
	}
}
/*
7
0 0 0 1 1 5
5
install 5
install 6
uninstall 1
install 4
uninstall 0
*/

