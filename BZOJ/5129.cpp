#include<cstdio>
const int N=20,P=998244353;
int n,m,i,f[N],g[N],a[N],nxt[N],ans;
void dfs(int x,int y){
  if(x>n){
    int i=2,j=0,k=1;
    for(i=2;i<=n;nxt[i++]=j){
      while(j&&a[j+1]!=a[i])j=nxt[j];
      if(a[j+1]==a[i])j++;
      k*=i-j;
    }
    g[y]=(g[y]+k)%P;
    return;
  }
  for(int i=1;i<=y+1;i++)a[x]=i,dfs(x+1,i>y?i:y);
}
int main(){
  scanf("%d%d",&n,&m);
  for(f[0]=i=1;i<=n;i++)f[i]=1LL*f[i-1]*(m-i+1)%P;
  dfs(1,0);
  for(i=1;i<=n;i++)ans=(1LL*f[i]*g[i]+ans)%P;
  printf("%d",ans);
  return 0;
}