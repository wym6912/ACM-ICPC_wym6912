#include<iostream>
#include<cstdio>
using namespace std;
const int need1=60003;
const int need2=100003;

struct fy{int a,b,le,ri,val;}t[need2*2];
struct yf{int mold,num;}c[need2];

int a[need2];
int tot=0,k,ne=-need1;

void build(int x,int y)
{
    int s=++tot;
    t[s].a=x,t[s].b=y;
    if(x==y)
    {
        t[s].val=a[x];
        return ;
    }
    t[s].le=tot+1;build(x,(x+y)/2);
    t[s].ri=tot+1;build((x+y)/2+1,y);
    t[s].val=t[t[s].le].val+t[t[s].ri].val;
}
void add_(int s)
{
     if(t[s].a<=k&&k<=t[s].b) t[s].val++;
     if(t[s].le!=0&&t[t[s].le].a<=k&&k<=t[t[s].le].b) add_(t[s].le);
     else if(t[s].ri!=0&&t[t[s].ri].a<=k&&k<=t[t[s].ri].b) add_(t[s].ri);
} 
void fire_(int s)
{
    if(t[s].a<=k&&k<=t[s].b) t[s].val--;
    if(t[s].le!=0&&t[t[s].le].a<=k&&k<=t[t[s].le].b) fire_(t[s].le);
    else if(t[s].ri!=0&&t[t[s].ri].a<=k&&k<=t[t[s].ri].b) fire_(t[s].ri);
}
int cnt(int s)
{
    if(k+1<=t[s].a&&t[s].b<=ne) return t[s].val;
    int ans=0,mid=(t[s].a+t[s].b)/2;
    if(k<mid) ans+=cnt(t[s].le);
    ans+=cnt(t[s].ri);
    return ans; 
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int b,i=1;i<=n;i++)
    {
        scanf("%d",&b);
        if(ne<b) ne=b;
        a[b]++;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&c[i].mold,&c[i].num);
        if(c[i].num>ne&&c[i].mold==1) ne=c[i].num;
    } 
    build(1,ne);
    for(int i=1;i<=m;i++)
    {
        k=c[i].num;
        if(c[i].mold==2&&a[k])
        {
            a[k]--;
            fire_(1);
        } 
        else if(c[i].mold==1) 
        {
            a[k]++;
            add_(1);
        }
        else if(c[i].mold==3) printf("%d\n",k>=ne?0:cnt(1));
    }
} 
