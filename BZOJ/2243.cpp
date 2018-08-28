#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
const int inf = 2e9;

int top;
int fa[maxn],c[maxn][2];
int val[maxn], tag[maxn], cl[maxn], s[maxn], ls[maxn], rs[maxn];
int q[maxn];
bool rev[maxn];
int n, m, f, t, type, w;

void init(){
    s[0] = 0;
    for(int i = 0; i <= n; i ++)
    	s[i] = rev[i] = c[i][0] = c[i][1] = fa[i] = q[i] = 0,
		cl[i] = ls[i] = rs[i] = tag[i] = -1;
    top = 0;
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    int l = c[x][0], r = c[x][1];
    s[x] = s[l] + s[r] + 1;
    if(l) s[x] -= (cl[x] == rs[l]), ls[x] = ls[l]; // ls 表示左区间的颜色是什么
    else ls[x] = cl[x];
    if(r) s[x] -= (cl[x] == ls[r]), rs[x] = rs[r]; // rs 表示右区间的颜色是什么
    else rs[x] = cl[x];
}
void rever(int p)
{
	rev[p] ^= 1;
	int l = c[p][0], r = c[p][1];
	if(l) swap(ls[l], rs[l]);
	if(r) swap(ls[r], rs[r]);
}
void pushdown(int x)
{
    int l = c[x][0],r = c[x][1];
    if(rev[x])
    {
        rev[x] ^= 1;
        swap(c[x][0], c[x][1]);
        rever(l);
        rever(r);
    }
    if(~ tag[x])
    {
    	if(l) tag[l] = tag[x], cl[l] = ls[l] = rs[l] = tag[x], s[l] = 1;
    	if(r) tag[r] = tag[x], cl[r] = ls[r] = rs[r] = tag[x], s[r] = 1;
    	tag[x] = -1;
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

int find(int x){
    access(x);splay(x);
    while(c[x][0]) x = c[x][0];
    return x;
}

void change(int x, int y, int v)
{
    makeroot(x);access(y);splay(y);
	tag[y] = v; cl[y] = ls[y] = rs[y] = v; s[y] = 1;
}

int ans(int x, int y)
{
    makeroot(x);access(y);splay(y);
    return s[y];
}

int main()
{
	int val;
	char ch;
	scanf("%d %d", &n, &m);
	init();
	for(int i = 1; i <= n; i ++) scanf("%d", &cl[i]), ls[i] = rs[i] = cl[i], s[i] = 1;
	for(int i = 1; i < n; i ++) scanf("%d %d", &f, &t), link(f, t);
	while(m --)
	{
		scanf("\n%c", &ch);
		switch(ch)
		{
			case 'C':
				scanf("%d %d %d", &f, &t, &val);
				change(f, t, val);
				break;
			case 'Q':
				scanf("%d %d", &f, &t);
				printf("%d\n", ans(f, t));
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
