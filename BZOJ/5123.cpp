#include<cstdio>
const int N=2010,M=9,P=998244353;
int n,m,K,i,j,k,t,a[N][M],b[N][M],g[N][N][2],h[N][N][2],ans;
inline void up(int&x,int y){x=x+y<P?x+y:x+y-P;}
inline bool equal(int*a,int*b){
  for(int i=0;i<K;i++)if(a[i]!=b[i])return 0;
  return 1;
}
inline bool smaller(int*a,int*b){
  for(int i=0;i<K;i++)if(a[i]>=b[i])return 0;
  return 1;
}
inline bool bigger(int*a,int*b){
  for(int i=0;i<K;i++)if(a[i]<=b[i])return 0;
  return 1;
}
int main(){
  scanf("%d",&K);
  scanf("%d",&n);
  for(i=1;i<=n;i++)for(j=0;j<K;j++)scanf("%d",&a[i][j]);
  scanf("%d",&m);
  for(i=1;i<=m;i++)for(j=0;j<K;j++)scanf("%d",&b[i][j]);
  for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<2;k++){
    if(equal(a[i],b[j])){
      t=h[i][j][k^1];
      if(!k)up(t,1);
      if(t){
        up(ans,t);
        up(g[i+1][j][k],t);
      }
    }
    if(g[i][j][k]){
      up(g[i+1][j][k],g[i][j][k]);
      if(!k){if(bigger(a[i],b[j]))up(h[i][j+1][k],g[i][j][k]);}
      else if(smaller(a[i],b[j]))up(h[i][j+1][k],g[i][j][k]);
    }
    if(h[i][j][k])up(h[i][j+1][k],h[i][j][k]);
  }
  printf("%d",ans);
  return 0;
}