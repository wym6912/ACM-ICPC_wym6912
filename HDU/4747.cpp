# include<bits/stdc++.h>
using namespace std;
# define LL long long
# define mid (l+(r-l)/2)
 
const int N=200000;
 
int a[N+5];
int mex[N+5];
int nxt[N+5];
LL tr[N*4+5];
LL lazy[N*4+5];
int maxn[N*4+5];
 
inline void getMex(int n)
{
    map<int,int>mp;
    map<int,int>f;
    fill(nxt,nxt+1+n,n+1);
    int m=0;
    for(int i=1;i<=n;++i){
        mp[a[i]]=1;
        while(mp[m]) ++m;
        mex[i]=m;
        if(f[a[i]])
            nxt[f[a[i]]]=i;
        f[a[i]]=i;
    }
}
 
inline void pushUp(int rt)
{
    tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
}
 
inline void pushDown(int rt,int l,int r)
{
    if(lazy[rt]!=-1){
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        maxn[rt<<1]=maxn[rt<<1|1]=lazy[rt];
        tr[rt<<1]=lazy[rt]*(LL)(mid-l+1);
        tr[rt<<1|1]=lazy[rt]*(LL)(r-mid);
        lazy[rt]=-1;
    }
}
 
inline void build(int rt,int l,int r)
{
    lazy[rt]=-1;
    if(l==r){
        tr[rt]=mex[l];
        maxn[rt]=mex[l];
    }else{
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushUp(rt);
    }
}
 
inline int query_up(int rt,int l,int r,int L,int R,int x)
{
    if(l==r){
        if(tr[rt]<x) return 0;
        return l;
    }
    pushDown(rt,l,r);
    if(L<=mid&&x<maxn[rt<<1]){
        int k=query_up(rt<<1,l,mid,L,R,x);
        if(k>0) return k;
    }
    if(R>mid&&x<maxn[rt<<1|1]){
        int k=query_up(rt<<1|1,mid+1,r,L,R,x);
        if(k>0) return k;
    }
    return 0;
}
 
inline void update(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R){
        lazy[rt]=x;
        tr[rt]=(LL)x*(LL)(r-l+1);
        maxn[rt]=x;
    }else{
        pushDown(rt,l,r);
        if(L<=mid) update(rt<<1,l,mid,L,R,x);
        if(R>mid) update(rt<<1|1,mid+1,r,L,R,x);
        pushUp(rt);
    }
}
 
inline LL query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return tr[rt];
    pushDown(rt,l,r);
    LL res=0;
    if(L<=mid) res+=query(rt<<1,l,mid,L,R);
    if(R>mid) res+=query(rt<<1|1,mid+1,r,L,R);
    return res;
}
 
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        getMex(n);
        build(1,1,n);
        LL ans=query(1,1,n,1,n);
        for(int i=1;i<n;++i){
            int p=query_up(1,1,n,i+1,nxt[i]-1,a[i]);
            if(p>0) update(1,1,n,p,nxt[i]-1,a[i]);
            ans+=query(1,1,n,i+1,n);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
