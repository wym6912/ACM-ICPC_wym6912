#include<cstdio>
const int N=100010;
int n,m,i,x,y,a[N],f[N];
inline int abs(int x){return x>0?x:-x;}
int main(){
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(f[1]=1,i=2;i<=n;i++)f[i]=abs(a[i]-a[i-1])<=1?f[i-1]:i;
  while(m--)scanf("%d%d",&x,&y),puts(f[y]<=x?"YES":"NO");
  return 0;
}