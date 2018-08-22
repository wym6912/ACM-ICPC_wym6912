#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 10;
const int inf = 2e9;

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

int top;
int fa[maxn],c[maxn][2];
int val[maxn], mx[maxn], sz[maxn], tag[maxn];
int q[maxn];
bool rev[maxn];
int n, m, f, t, type, w;

struct edge
{
	int to, next;
}edg[maxn << 1];
int fir[maxn], cnt;

void addedge(int f, int t)
{
	edg[++ cnt].next = fir[f];
	fir[f] = cnt;
	edg[cnt].to = t;
}

void init(){
    sz[0] = 0;
    for(int i = 0; i <= n; i ++)
    	mx[i] = rev[i] = c[i][0] = c[i][1] = fa[i] = q[i] = 0;
    mx[0] = -inf;
    top = 0;
	for(int i = 1; i <= n; i ++)
    	sz[i] = 1;
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    int l = c[x][0], r = c[x][1];
    mx[x] = max(mx[l], max(mx[r], val[x]));
    sz[x] = sz[l] + sz[r] + 1;
}
void pushdown(int x)
{
    int l=c[x][0],r=c[x][1];
    if(rev[x])
    {
        rev[x]^=1;rev[l]^=1;rev[r]^=1;
        swap(c[x][0],c[x][1]);
    }
    if(tag[x])
    {
    	if(l) tag[l] += tag[x], val[l] += tag[x], mx[l] += tag[x];
    	if(r) tag[r] += tag[x], val[r] += tag[x], mx[r] += tag[x];
    	tag[x] = 0;
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
    access(x);splay(x);rev[x] ^= 1;
}
void link(int x,int y)
{
    makeroot(x);fa[x] = y;
	splay(x);
}
void split(int x,int y)
{
    makeroot(x); access(y); splay(y);
}
void cut(int x, int y)
{
	makeroot(x);
	access(y);
	splay(y);
    c[y][0] = fa[c[y][0]] = 0;
    update(y);
}

int find(int x){
    access(x);splay(x);
    while(c[x][0]) x = c[x][0];
    return x;
}

void add(int x,int y,int v)
{
    makeroot(x);access(y);splay(y);
	tag[y] += v;mx[y] += v;val[y] += v;
}

int maxans(int x,int y)
{
    makeroot(x);access(y);splay(y);
    return mx[y];
}

int main()
{
	int tf, tt;
	while(~ scanf("%d", &n))
	{
		init();
		//memset(fir, 0, sizeof(fir));
		//cnt = 0;
		for(int i = 1; i < n; i ++)
		{
			//scanf("%d %d", &f, &t);
			scan_d(f);
			scan_d(t);
			//addedge(f, t);
			//addedge(t, f);
			link(f, t);
		}
		for(int i = 1; i <= n; i ++)
		{
			//scanf("%d", &val[i]);
			scan_d(val[i]);
			mx[i] = val[i];
		}
		/*
		q[++ top] = 1;
		for(int i = 1; i <= top; i ++)
		{
			int now = q[i];
			for(int j = fir[now]; j; j = edg[j].next)
			{
				if(edg[j].to != fa[now])
				{
					fa[edg[j].to] = now;
					q[++ top] = edg[j].to;
				}
			}
		}
		*/
		//scanf("%d", &m);
		scan_d(m);
		while(m --)
		{
			//scanf("%d", &type);
			scan_d(type);
			switch(type)
			{
				case 1:
					//scanf("%d %d", &f, &t); 
					scan_d(f);
					scan_d(t);
					if(find(f) == find(t)) puts("-1");
					else link(f, t);
					break;
				case 2:
					//scanf("%d %d", &f, &t);
					scan_d(f);
					scan_d(t);
					if(find(f) != find(t) || f == t) puts("-1");
					else cut(f, t);
					break;
				case 3:
					//scanf("%d %d %d", &w, &tf, &tt);
					scan_d(w);
					scan_d(tf);
					scan_d(tt);
					if(find(tf) != find(tt)) puts("-1");
					else 
					{
						add(tf, tt, w);
					}
					break;
				case 4:
					//scanf("%d %d", &f, &t);
					scan_d(f);
					scan_d(t);
					if(find(f) != find(t)) puts("-1");
					else printf("%d\n", maxans(f, t));
					break;
			}
		}
		puts("");
	}
	return 0;
}
