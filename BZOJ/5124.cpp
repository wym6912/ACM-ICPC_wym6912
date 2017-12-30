#include<cstdio>
#include<algorithm>
const int N=40005,M=160,inf=~0U>>2;
int n,m,lim,i,j,x,y,z,a[N],v[N][256],pos[N][M],tag[N][M],f[N],g[N],L,R,now;
inline int ask(int x,int y){return v[pos[x][y>>8]][y&255]+tag[x][y>>8];}
inline int askl(int l,int r,int x){return l<=r?ask(r,x)-ask(l-1,x):0;}
inline int askr(int l,int r,int x){return l<=r?r-l+1-askl(l,r,x):0;}
inline void go(int l,int r){
  while(L<l)now-=askl(L+1,R,a[L]),L++;
  while(L>l)now+=askl(L,R,a[L-1]),L--;
  while(R<r)now+=askr(L,R,a[R+1]),R++;
  while(R>r)now-=askr(L,R-1,a[R]),R--;
}
void solve(int l,int r,int dl,int dr){
  int m=(l+r)>>1,dm=dl,&F=f[m];
  for(int i=dl;i<=dr&&i<m;i++){
    go(i+1,m);
    int t=g[i]+now;
    if(t<F)F=t,dm=i;
  }
  if(l<m)solve(l,m-1,dl,dm);
  if(r>m)solve(m+1,r,dm,dr);
}
int main(){
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  lim=n>>8;
  for(i=1;i<=n;i++){
    for(j=0;j<=lim;j++)pos[i][j]=pos[i-1][j],tag[i][j]=tag[i-1][j];
    x=a[i],y=x>>8,z=pos[i][y];
    for(j=0;j<256;j++)v[i][j]=v[z][j];
    for(j=x&255;j<256;j++)v[i][j]++;
    pos[i][y]=i;
    for(j=y+1;j<=lim;j++)tag[i][j]++;
  }
  for(i=1;i<=n;i++)f[i]=inf;
  for(i=1;i<=m;i++){
    for(j=0;j<=n;j++)g[j]=f[j],f[j]=inf;
    L=R=1,now=0;
    solve(i,n,i-1,n);
  }
  printf("%d",f[n]);
  return 0;
}