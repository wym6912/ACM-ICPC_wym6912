#include <bits/stdc++.h>
   
using namespace std;  
   
int n,m,cnt;  
int dfn[10005],low[10005],num;  
vector<int> g[10005];  
   
void Tarjan(int u,int p) {  
    dfn[u]=low[u]=++num;  
    int v;  
    for(int i=0;i<g[u].size();++i) {  
        v=g[u][i];  
        if(v!=p) {  
            if(dfn[v]==0) {  
                Tarjan(v,u);  
                low[u]=min(low[u],low[v]);  
                if(dfn[u]<low[v]) {  
                    ++cnt;  
                }  
            }  
            else {  
                low[u]=min(low[u],dfn[v]);  
            }  
        }  
    }  
}  
   
int main() {  
    int T,s,e;  
    scanf("%d",&T);  
    while(T --) {  
        scanf("%d%d",&n,&m);  
        for(int i=0;i<n;++i) {  
            g[i].clear();  
            dfn[i]=0;  
        }  
        while(m --)
		 {  
            scanf("%d%d",&s,&e);  
            g[s].push_back(e);  
            g[e].push_back(s);  
        }  
        num=cnt=0;  
        Tarjan(0,-1);  
        printf("%d\n",cnt);  
    }  
    return 0;  
}  
