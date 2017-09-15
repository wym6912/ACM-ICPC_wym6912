#include<bits/stdc++.h> 
using namespace std; 
const int N=2e5+7; 
int root[N],a[N],c[N*25],ls[N*25],rs[N*25],tot,fa[N],n; 
vector<int> adj[N]; 
namespace LCA 
{
	int ord[N<<1],d[N<<1],fir[N],dp[N<<1][20],mm[N<<1],m=0;
    void dfs_lca(int u,int p,int deep)     
	{         
		ord[++m]=u;         
		d[m]=deep;         
		fir[u]=m;         
		for(int i=0;i<adj[u].size();++ i)         
		{ 
			int v=adj[u][i]; 
			if(v==p) continue; 
			dfs_lca(v,u,deep+1); 
			ord[++m]=u; 
			d[m]=deep;         
		}     
	}     
	void init_RMQ()     
	{         
		mm[0] = -1;         
		for(int i=1;i<=m;++i)         
		{ 
			mm[i]= ((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			dp[i][0]=i;         
		}         
		for(int j=1;j<=mm[m];++j) 
			for(int i=1;i+(1<<j) - 1<=m;++i) 
			{     
				int x=dp[i][j-1],y=dp[i+(1<<(j-1))][j-1];     
				dp[i][j]=d[x]<d[y]?x:y; 
			}     
	}     
	int lca(int u,int v)     
	{         
		u=fir[u],v=fir[v];         
		if(u>v) swap(u,v);         
		int k=mm[v-u+1];         
		int x=dp[u][k],y=dp[v-(1<<k)+1][k];         
		return d[x]<d[y]?ord[x]:ord[y];    
	}     
	void init(int u)     
	{        
		m=0;         
		dfs_lca(u,0,0);         
		init_RMQ();     
	}
} 
void build(int &rt,int l,int r)
{     
	rt=++tot;     
	if(l==r) return ;     
	int m=(l+r)>>1;     
	build(ls[rt],l,m);     
	build(rs[rt],m+1,r); 
}
void update(int &rt,int last,int l,int r,int p) 
{     
	rt=++tot;     
	ls[rt]=ls[last];    
	rs[rt]=rs[last];     
	c[rt]=c[last]+1;     
	if(l == r) return ;     
	int m=(l+r)>>1;     
	if(p<=m) update(ls[rt],ls[last],l,m,p);     
		else update(rs[rt],rs[last],m+1,r,p); 
} 
int query(int u,int v,int lca,int p,int l,int r) 
{     
	int val=c[ls[u]]+c[ls[v]]-c[ls[lca]];     
	if(p) val-=c[ls[p]];     
	if(l==r) return l;     
	int m=(l+r)>>1;     
	if(val<(m-l+1)) 
		return query(ls[u],ls[v],ls[lca],ls[p],l,m);     
	else 
		return query(rs[u],rs[v],rs[lca],rs[p],m+1,r); 
}
void dfs(int u,int p) 
{     
	fa[u]=p;     
	update(root[u],root[p],1,n,a[u]);     
	for(int i=0;i<adj[u].size();++i)     
	{         
		int v=adj[u][i];         
		if(v==p) continue;         
		dfs(v,u);     
	}
} 
int main() 
{     
	int q;     
	scanf("%d",&n);     
	for(int i=1;i<n;++i)     
	{         
		int u,v;         
		scanf("%d%d",&u,&v);         
		adj[u].push_back(v);         
		adj[v].push_back(u);     
	}     
	LCA::init(1);     
	for(int i=1;i<=n;++i) 
		scanf("%d",&a[i]),++a[i];     
	build(root[0],1,n);
    dfs(1,0);
    scanf("%d",&q);     
	while(q--)     
	{         
		int u,v;         
		scanf("%d%d",&u,&v);         
		int lca=LCA::lca(u,v);         
		printf("%d\n",query(root[u],root[v],root[lca],root[fa[lca]],1,n)-1);     
	}     
	return 0; 
}

