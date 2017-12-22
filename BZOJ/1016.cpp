#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 31011
using namespace std;
int n,m,cnt,tot,ans=1,sum;
int fa[105];
struct edge{int x,y,v;}e[1005];
struct data{int l,r,v;}a[1005];
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
bool cmp(edge a,edge b){return a.v<b.v;}
int find(int x){return x==fa[x]?x:find(fa[x]);}
void dfs(int x,int now,int k)
{
     if(now==a[x].r+1)
     {
         if(k==a[x].v)sum++;
         return;
     }
     int p=find(e[now].x),q=find(e[now].y);
     if(p!=q)
     {
         fa[p]=q;
         dfs(x,now+1,k+1);
         fa[p]=p;fa[q]=q;
     }
     dfs(x,now+1,k);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        e[i].x=read(),e[i].y=read(),e[i].v=read();
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(e[i].v!=e[i-1].v){a[++cnt].l=i;a[cnt-1].r=i-1;}
        int p=find(e[i].x),q=find(e[i].y);
        if(p!=q){fa[p]=q;a[cnt].v++;tot++;}
    }
    a[cnt].r=m;
    if(tot!=n-1){printf("0");return 0;}
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        sum=0;
        dfs(i,a[i].l,0);
        ans=(ans*sum)%mod;
        for(int j=a[i].l;j<=a[i].r;j++)
        {
            int p=find(e[j].x),q=find(e[j].y);
            if(p!=q)fa[p]=q;
        }
    }
    printf("%d",ans);
    return 0;
}
