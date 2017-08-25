#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100010;
int tree[20][MAXN];
int sorted[MAXN], tmp[MAXN], hdd[MAXN];
int toleft[20][MAXN];
int idx, n;
int to[2000000],NEXT[2000000],head[1000001],
    q[1000001],fa[1000001],size[1000001],
    dfs[1000001],zz[1000001];

void build(int l,int r,int dep) 
{
     if(l == r)return;     
	 int mid = (l+r)>>1;     
	 int same = mid - l + 1;//?????????????????
     for(int i = l; i <= r; i++) //???l,??one
         if(tree[dep][i] < sorted[mid])
             same--;
     int lpos = l;     
	 int rpos = mid+1;     
	 for(int i = l;i <= r;i++)
	 {
	 	if(tree[dep][i] < sorted[mid])
			tree[dep+1][lpos++] = tree[dep][i];
		else if(tree[dep][i] == sorted[mid] && same > 0)
		{
		    tree[dep+1][lpos++] = tree[dep][i];
			same--;
		}
		else             
			tree[dep+1][rpos++] = tree[dep][i];         
		toleft[dep][i] = toleft[dep][l-1] + lpos - l;     
		}     
		build(l,mid,dep+1);     
		build(mid+1,r,dep+1); 
}
 
//?????k???,[L,R]????,[l,r]???????? 
int query(int L,int R,int l,int r,int dep,int k) 
{
     if(l == r)return tree[dep][l];
	 int mid = (L+R)>>1;
	 int cnt = toleft[dep][r] - toleft[dep][l-1];
	 if(cnt >= k)     
	 {         
	 	int newl = L + toleft[dep][l-1] - toleft[dep][L-1];         
		int newr = newl + cnt - 1;         
		return query(L,mid,newl,newr,dep+1,k);     
	 }
	 else     
	 {         
	 	int newr = r + toleft[dep][R] - toleft[dep][r]; 
        int newl = newr - (r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);     
	 } 
}

void add(int x,int y)
{
    to[++idx]=y;
    NEXT[idx]=head[x];
    head[x]=idx;
    to[++idx]=x;
    NEXT[idx]=head[y];
    head[y]=idx;
    return ;
}
void bfs()
{
    int l=0,r=0;
    q[r++]=1;
    while(l!=r)
    {
        int x=q[l++];
        size[x]=1;
        for(int i=head[x];i;i=NEXT[i])
            if(to[i]!=fa[x])
            {
                fa[to[i]]=x;
                q[r++]=to[i];
            }
    }
    for(int i=n-1;i>=0;--i)
        size[fa[q[i]]]+=size[q[i]];
    return ;
}

int main()
{
	int m,a,b;
	while(~ scanf("%d",&n))
	{
		memset(tree, 0, sizeof(tree));
		memset(dfs, 0,sizeof(dfs));
		memset(fa, 0, sizeof(fa));
		memset(head, 0, sizeof(head));
		memset(NEXT, 0, sizeof(NEXT));
		idx = 0;
		memset(to, 0, sizeof(to));
		memset(toleft, 0,sizeof(toleft));
		memset(zz, 0, sizeof(zz));
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&tmp[i]);
			sorted[i] = tmp[i];
		}
		for(int i = 1;i < n;++ i)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		bfs();
		dfs[1] = 1;
		zz[1] = 2;
		int last;
		for(int i = 1;i < n ; ++ i)
		{
			if(fa[q[i]] != fa[q[i-1]])
			last = zz[fa[q[i]]];
			else
			(last += size[q[i - 1]]);
			dfs[last] = q[i];
			zz[q[i]] = last + 1;
		}
		for(int i = 1;i <= n;i ++)	
		{
			tree[0][i] = tmp[dfs[i]];
		}
		//for(int i = 1;i <= n;i ++)
		//	cout << tree[0][i] << ' ' ;
		//cout << endl;
		//for(int i = 1;i <= n;i ++)
		//	cout << size[i] << ' ';
		//cout << endl;
		for(int i = 1;i <= n;i ++)
			hdd[dfs[i]] = i;
		sort(sorted + 1, sorted + 1 + n);
		build(1, n, 0);
		scanf("%d",&m);
		int s, t, k;
		while(m --)
		{
			scanf("%d%d",&s,&k);
			s = hdd[s];
			//cout <<"s = " << s << ", dfs[s] = " << dfs[s] 
			//<< ", size[s] =  " << size[s] << endl;
			printf("%d\n",query(1, n, s, s + size[dfs[s]] - 1, 0, k));
		}
	}
	return 0;
}
