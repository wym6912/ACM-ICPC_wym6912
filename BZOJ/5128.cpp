#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
const int N=300010,M=N*20;
int n,S,i,x,y,lim[N],cost[N],g[N],v[N<<1],nxt[N<<1],ok[N<<1],ed;
int f[N],son[N],all,now;
int st[N],en[N],cur,q[M][2],vis[N];
int G[N],V[M],W[M],NXT[M],ED;
priority_queue<P,vector<P>,greater<P> >Q;
ll dis[N];
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;ok[ed]=1;}
inline void ADD(int x,int y,int z){V[++ED]=y;W[ED]=z;NXT[ED]=G[x];G[x]=ED;}
void findroot(int x,int y){
  son[x]=1;f[x]=0;
  for(int i=g[x];i;i=nxt[i])if(ok[i]&&v[i]!=y){
    findroot(v[i],x);
    son[x]+=son[v[i]];
    if(son[v[i]]>f[x])f[x]=son[v[i]];
  }
  if(all-son[x]>f[x])f[x]=all-son[x];
  if(f[x]<f[now])now=x;
}
inline void bfs(int S){
  vis[S]=S;
  q[++cur][0]=S;
  q[cur][1]=0;
  int h=cur;
  while(h<=cur){
    int x=q[h][0],y=q[h++][1]+1;
    for(int i=g[x];i;i=nxt[i])if(ok[i]&&vis[v[i]]!=S){
      vis[v[i]]=S;
      q[++cur][0]=v[i];
      q[cur][1]=y;
    }
  }
}
void solve(int x){
  st[x]=cur+1;
  bfs(x);
  en[x]=cur;
  for(int i=st[x];i<=cur;i++)ADD(q[i][0],x,q[i][1]);
  for(int i=g[x];i;i=nxt[i])if(ok[i]){
    ok[i^1]=0;
    f[0]=all=son[v[i]];
    findroot(v[i],now=0);
    solve(now);
  }
}
inline void ext(int x,ll y){
  if(vis[x])return;
  vis[x]=1;
  dis[x]=y;
  Q.push(P(y+cost[x],x));
}
inline void go(int x,int lim,ll y){
  int&h=st[x],t=en[x];
  while(h<=t){
    if(q[h][1]>lim)break;
    ext(q[h++][0],y);
  }
}
int main(){
  scanf("%d%d",&n,&S);
  for(ed=i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
  for(i=1;i<=n;i++)scanf("%d%d",&lim[i],&cost[i]);
  f[0]=all=n;findroot(1,now=0);solve(now);
  for(i=1;i<=n;i++)vis[i]=0;
  ext(S,0);
  while(!Q.empty()){
    P t=Q.top();Q.pop();
    for(i=G[t.second];i;i=NXT[i])go(V[i],lim[t.second]-W[i],t.first);
  }
  for(i=1;i<=n;i++)printf("%lld\n",dis[i]);
  return 0;
}