#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000+10;
const int inf = 2e9;
int top;
int fa[maxn],c[maxn][2];
int val[maxn], mx[maxn];
int q[maxn];
bool rev[maxn];
int n, m, f, t;
void init(){
    memset(mx, 0, sizeof(mx));
    memset(rev, 0, sizeof(rev));
    memset(c, 0, sizeof(c));
    memset(fa, 0, sizeof(fa));
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x && c[fa[x]][1]!=x;
}
void update(int x)
{
    int l=c[x][0], r=c[x][1];
    mx[x]=max(mx[l], max(mx[r], val[x]));
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
    access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
    makeroot(x);fa[x] = y;
}
void split(int x,int y)
{
    makeroot(x);access(y);splay(y);
}
void cut(int x,int y)
{
    split(x, y);
    //if(c[y][0]==x)c[y][0]=fa[x]=0;
    c[y][0]=fa[c[y][0]]=0;
    //pushup
    //update(y);
}
//为什么往左孩子找？
int find(int x){
    access(x);splay(x);
    //找到原来的根节点
    while(c[x][0])x=c[x][0];
    return x;
}

char str[10];
int main()
{
	scanf("%d %d", &n, &m);
	init();
	while(m --)
	{
		scanf("\n%s %d %d", str, &f, &t);
		switch(str[0])
		{
			case 'Q':
				while(fa[f]) f = fa[f];
				while(fa[t]) t = fa[t];
				f == t ? puts("Yes") : puts("No");
				break;
			case 'C':
				link(f, t);
				break;
			case 'D':
				cut(f, t);
				break;
			default:
				assert(str[0] == 'Q' || str[0] == 'C' || str[0] == 'D');
		}
	}
}
/*
200 5
Query 123 127
Connect 123 127
Query 123 127
Destroy 127 123
Query 123 127

3 5
Connect 1 2
Connect 3 1
Query 2 3
Destroy 1 3
Query 2 3
*/
