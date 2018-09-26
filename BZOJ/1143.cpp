#include <bits/stdc++.h>
const int N=300;
int n,m;
struct edge
{
    int v,next;
}node[N*N];
int head[N],cnt=0;
bool g[N][N];
void add(int u,int v)
{
    node[cnt].v=v; node[cnt].next=head[u]; head[u]=cnt++;
}
int used[N],match[N];
bool m_find(int u)
{
    for(int i=head[u];~i;i=node[i].next)
    {
        int v=node[i].v;
        if(!used[v])
        {
            used[v]=1;
            if(!match[v]||m_find(match[v]))
            {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    cnt = 0;
    memset(head, -1, sizeof(head));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        g[u][v] = true;
    }
    for(int k = 1; k <= n; ++ k)
    	for(int i = 1; i <= n; ++ i)
    		for(int j = 1; j <= n; ++ j)
    			g[i][j] |= (g[i][k] && g[k][j]);
    for(int i = 1; i <= n; ++ i)
    	for(int j = 1; j <= n; ++ j)
    		if(i != j && g[i][j])
    			add(i, j);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if(m_find(i)) ans++;
    }
//    for(int i=1;i<=n;i++)
//        if(!used[i])//?????
//        {dfs(i);printf("\n");}
    printf("%d\n",n-ans);
    return 0;
}

