#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000+10;
const int inf = 2e9;
int top;
int fa[maxn],c[maxn][2];
int val[maxn], mx[maxn], sz[maxn];
int q[maxn];
bool rev[maxn];
int n, m, f, t, type;
void init(){
    memset(mx, 0, sizeof(mx));
    memset(rev, 0, sizeof(rev));
    memset(c, 0, sizeof(c));
    memset(fa, 0, sizeof(fa));
    sz[0] = 0;
    for(int i = 1; i <= n; i ++) sz[i] = 1;
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
    c[y][0]=fa[x]=0;
    //pushup
}
//为什么往左孩子找？
int find(int x){
    access(x);splay(x);
    //找到原来的根节点
    while(c[x][0])x=c[x][0];
    return x;
}
int data[maxn];
char str[10];
int main()
{
	int ans;
	scanf("%d", &n);
	init();
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &data[i]);
		if(i + data[i] <= n) fa[i] = i + data[i];
		else fa[i] = n + 1;
		data[i] = fa[i];
	}
	scanf("%d", &m);
	while(m --)
	{
		scanf("%d", &type);
		switch(type)
		{
			case 1:
				scanf("%d", &f);
				makeroot(n + 1);
				++ f;
				access(f);
				splay(f);
				printf("%d\n", sz[c[f][0]]);
				break;
			case 2:
				scanf("%d %d", &f, &t);
				++ f;
				cut(f, data[f]);
				if(f + t <= n) link(f, f + t);
				else link(f, n + 1);
				data[f] = fa[f];
				break;
			default:
				assert(type == 1 || type == 2);
		}
	}
}
/*
4 
1 2 1 1 
3
1 1
2 1 1
1 1
*/