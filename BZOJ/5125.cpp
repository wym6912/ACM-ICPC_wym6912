#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int N=100010;
int n,i,j,k,f[N],p[N],m[N],s[N],w[N];
ll ans;
int t,q[N];
int fa[N],vf[N],vis[N];
set<P>T[N];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
inline void merge(int x,int y){
	if(F(x)!=F(y))fa[fa[x]]=fa[y];
}
inline ll cal(int x){
	int y=f[x];
	ll pre=T[y].rbegin()->first;
	T[y].erase(P(w[x],x));
	ll now=T[y].rbegin()->first;
	T[y].insert(P(w[x],x));
	return now-pre;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d%d",&f[i],&p[i],&m[i],&s[i]);
	for(i=1;i<=n;i++)T[i].insert(P(0,0));
	for(i=1;i<=n;i++){
		w[i]=m[f[i]]-p[i];
		T[f[i]].insert(P(w[i],i));
	}
	for(i=1;i<=n;i++)ans+=1LL*(T[i].rbegin()->first)*s[i];
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=n;i++)merge(i,f[i]);
	for(i=1;i<=n;i++)if(!vf[F(i)]){
		vf[fa[i]]=1;
		for(j=i;!vis[j];j=f[j])vis[j]=1;
		q[t=1]=j;
		for(k=f[j];k!=j;k=f[k])q[++t]=k;
		if(t==1)continue;
		ll tmp=-(1LL<<60);
		for(j=1;j<=t;j++){
			tmp=max(tmp,cal(q[j]));
		}
		ans+=tmp;
	}
	printf("%lld",ans);
}