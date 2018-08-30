#define NOSTDCPP
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

const int MAXN = 10010;
const int inf = 0x3f3f3f3f;
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];//top[v]??v??????????
int fa[MAXN]; //????
int deep[MAXN];//??
int num[MAXN];//num[v]???v?????????
int p[MAXN];//p[v]??v?????????????????
int fp[MAXN];//?p????
int son[MAXN];//???
int pos;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 0;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfs1(int u,int pre,int d) //???dfs??fa,deep,num,son
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
void getpos(int u,int sp) //???dfs??top?p
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
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

//???
struct Node
{
    int l,r;
    int Max, Min;
    bool rev;
}segTree[MAXN*4];
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].Max = -inf;
    segTree[i].Min = inf;
    segTree[i].rev = false;
    if(l == r)return;
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
    segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    segTree[i].Min = min(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
}
void revv(int i)
{
	segTree[i].Max *= -1;
	segTree[i].Min *= -1;
	swap(segTree[i].Max, segTree[i].Min);
}
void push_down(int i)
{
	if(segTree[i].rev)
	{
		segTree[i << 1].rev ^= segTree[i].rev;
		segTree[(i << 1) | 1].rev ^= segTree[i].rev;
		revv(i << 1);
		revv((i << 1) | 1);
		segTree[i].rev = false;
	}
}
void update(int i,int k,int val) // ???????k???val
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max = segTree[i].Min = val;
        segTree[i].rev = false;
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}
void update2(int i,int l,int r)  //??????[l,r] ????
{
    if(segTree[i].l == l && r == segTree[i].r)
    {
    	segTree[i].rev ^= 1;
    	revv(i);
    	return ;
	}
	push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid) update2(DXA(i), l, r);
    else if(l > mid)  update2(DXB(i), l, r);
    else update2(DXA(i), l, mid), update2(DXB(i), mid + 1, r);
    push_up(i);
}
int query(int i,int l,int r)  //??????[l,r] ????
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].Max;
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return query(i<<1,l,r);
    else if(l > mid)return query((i<<1)|1,l,r);
    else return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
}
int find(int u,int v)//??u->v?????
{
    int f1 = top[u], f2 = top[v];
    int tmp = -inf;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp = max(tmp,query(1,p[f1],p[u]));
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query(1,p[son[u]],p[v]));
}

void __update__(int u,int v)//??u->v?????
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        update2(1,p[f1], p[u]);
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return ;
    if(deep[u] > deep[v]) swap(u,v);
    update2(1,p[son[u]],p[v]);
}
int e[MAXN][3];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
            addedge(e[i][0],e[i][1]);
            addedge(e[i][1],e[i][0]);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        for(int i = 0;i < n-1; i++)
        {
            if(deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update(1,p[e[i][1]],e[i][2]);
        }
        char op[10];
        int u,v;
        while(scanf("%s",op) == 1)
        {
            if(op[0] == 'D')break;
            scanf("%d%d",&u,&v);
            if(op[0] == 'Q')
                printf("%d\n",find(u,v));
            else if(op[0] == 'C') update(1,p[e[u-1][1]],v);
            else __update__(u, v);
        }
    }
    return 0;
}
/*
1
15
7 1 93
6 2 41
6 1 48
14 4 62
12 15 43
7 8 2
2 10 80
7 13 92
13 5 91
13 11 5
15 1 79
2 3 21
9 12 7
15 4 33
Q 13 7
C 6 6
N 13 1
Q 3 15
C 12 11
N 14 11
Q 2 11
N 2 7
Q 6 7
C 11 10
N 3 8
Q 14 8
C 3 4
Q 8 13
C 5 1
N 7 1
Q 1 11
C 11 8
DONE
*/
/*
ans
92
79
93
-48
93
92
92
*/
