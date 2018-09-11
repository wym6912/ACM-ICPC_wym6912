#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000+20;
const ll inf = 1e18;
int n,m,top;
int fa[maxn],c[maxn][2], size[maxn];
ll maxsum[maxn], lsum[maxn], rsum[maxn], sum[maxn], val[maxn], lazy[maxn];
int q[maxn];
bool rev[maxn];
int id;
int tot, head[maxn];
void init(int n){
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(rev, 0, sizeof(rev));
    memset(c, 0, sizeof(c));
    memset(fa, 0, sizeof(fa));
    for(int i = 0; i <= n + 1; ++ i)
		maxsum[i] = lsum[i] = rsum[i] = -inf, lazy[i] = inf, size[i] = 1;
	size[0] = 0;
	size[n + 1] = 0;
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    maxsum[0] = lsum[0] = rsum[0] = 0;
    sum[0] = 0;
    size[0] = 0;
    int l = c[x][0], r = c[x][1];
    size[x] = size[l] + size[r] + 1;
    sum[x] = sum[l] + sum[r] + val[x];
    maxsum[x] = max(max(maxsum[l], maxsum[r]), lsum[r] + val[x] + rsum[l]);
    lsum[x] = max(lsum[l], val[x] + sum[l] + lsum[r]);
    rsum[x] = max(rsum[r], rsum[l] + sum[r] + val[x]);
}
void __tag(int p, ll v)
{
	lazy[p] = val[p] = v;
	maxsum[p] = lsum[p] = rsum[p] = v > 0 ? v * size[p] : 0ll;
	sum[p] = v * size[p];
}
void __rev(int p)
{
	rev[p] ^= true;
	swap(c[p][0], c[p][1]);
	swap(lsum[p], rsum[p]);
}
void pushdown(int x)
{
    int l=c[x][0],r=c[x][1];
    if(rev[x])
    {
        rev[x]^=1;
        __rev(l);
        __rev(r);
    }
    if(lazy[x] != inf)
    {
    	__tag(l, lazy[x]);
    	__tag(r, lazy[x]);
    	lazy[x] = inf;
	}
}
void rotate(int x)
{
    int y=fa[x],z=fa[y],l,r;
    l=(c[y][1]==x);r=l^1;
    if(!isroot(y))c[z][c[z][1]==y]=x;
    fa[c[x][r]]=y;fa[y]=x;fa[x]=z;
    c[y][l]=c[x][r];c[x][r]=y;
    update(y);update(x);
}
void splay(int x)
{
    top = 0;
    q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i])
        q[++top]=fa[i];
    while(top)pushdown(q[top--]);
    while(!isroot(x))
    {
        int y=fa[x],z=fa[y];
        if(!isroot(y))
        {
            if(c[y][0]==x^c[z][0]==y)rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void access(int x)
{
    for(int t=0;x;t=x,x=fa[x])
        splay(x),c[x][1]=t,update(x);
}
void makeroot(int x)
{
    access(x);splay(x);rev[x]^=1;swap(c[x][0], c[x][1]);
}
void link(int x,int y)
{
    makeroot(x); fa[x] = y;
}
void split(int x,int y)
{
    makeroot(x);access(y);splay(y);
}
ll ans(int x, int y)
{
    split(x, y);
    return max(maxsum[y], 0ll);
}
void __update(int x, int y, ll val)
{
	split(x, y);
	__tag(y, val);
}

int main()
{
	int f, t, type;
	ll v;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%lld", sum + i);
		maxsum[i] = lsum[i] = rsum[i] = sum[i] > 0 ? sum[i] : 0;
		val[i] = sum[i];
	}
	for(int i = 1; i < n; ++ i)
	{
		scanf("%d %d", &f, &t);
		link(f, t);
	}
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d %d %d", &type, &f, &t);
		switch(type)
		{
			case 1:
				printf("%lld\n", ans(f, t));
				break;
			case 2:
				scanf("%lld", &v);
				__update(f, t, v);
				//for(int i = 1; i <= n; ++ i) cout << val[i] << ' ';cout << endl;
				break;
			default:
				assert(false);
		}
	}
    return 0;
}
/*
5
-3 -2 1 2 3
1 2
2 3
1 4
4 5
3
1 2 5
2 3 4 2
1 2 5

5
-3968 -165 7588 -173 -75
1 2
2 3
1 4
2 5
7
1 1 5
1 5 2
2 4 2 1938
1 2 4
1 2 3
1 3 4
1 5 1

6
3255 8180 -5067 3612 9586 -1412
1 2
1 3
3 4
4 5
2 6
6
2 4 3 7869
2 5 6 -4673
2 6 1 -8963
2 1 6 8043
1 3 3
1 4 5

9
-3606 -9163 362 -9043 -3313 923 3159 5766 740
1 2
1 3
3 4
3 5
2 6
1 7
5 8
1 9
3
2 6 7 588
1 1 8
1 6 1



*/

