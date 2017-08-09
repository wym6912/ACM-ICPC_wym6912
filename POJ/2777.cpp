#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f
#define MAXN 100100

struct tree
{
    int l;
    int r;
    int colr;
    bool lazy;//lazy是lazy-tag
};
tree t[MAXN*4];
int L,T,O;
int cc;
int x,y,c;
void Swap()
{
    int temp=x;
    x=y;
    y=temp;
}
void Build(int l,int r,int index)
{
    t[index].l=l;
    t[index].r=r;
    t[index].colr=1;
    t[index].lazy=0;//lazy=0，说明当前结点没有lazy标记。
    if(l==r)
        return;
    int mid=(l+r)>>1;
    Build(l,mid,index<<1);
    Build(mid+1,r,index<<1|1);
}
void inse(int l,int r,int index,int cl)
{
    if(t[index].l==l && t[index].r==r)
    {
        t[index].colr=(1<<(cl-1));
        t[index].lazy=1;//更新到相应节点的时候，加上lazy-tag
        return;
    }
    if(t[index].lazy) //如果当前的节点有lazy标记，则
    {
        t[index].lazy=0;//1，需要取消lazy标记，
        t[index<<1].lazy=1;//2，往子节点传递lazy标记
        t[index<<1|1].lazy=1;
        t[index<<1].colr=t[index].colr;//3，并传递值
        t[index<<1|1].colr=t[index].colr;
    }
    int mid=(t[index].l+t[index].r)>>1;
    if(r<=mid)
        inse(l,r,index<<1,cl);
    else if(l>mid)
        inse(l,r,index<<1|1,cl);
    else
    {
        inse(l,mid,index<<1,cl);
        inse(mid+1,r,index<<1|1,cl);
    }
    t[index].colr=t[index<<1].colr | t[index<<1|1].colr;//往上更新值。
}
void quer(int l,int r,int index)
{
    //如果遇见带lazy标记的节点，只需要返回当前的节点的值就行了，
    if(t[index].lazy || (t[index].l==l && t[index].r==r) )
    {
        cc|=t[index].colr;
        return;
    }
    int mid=(t[index].l+t[index].r)>>1;
    if(r<=mid)
        quer(l,r,index<<1);
    else if(l>mid)
        quer(l,r,index<<1|1);
    else
    {
        quer(l,mid,index<<1);
        quer(mid+1,r,index<<1|1);
    }
}
int main()
{
    while(scanf("%d%d%d",&L,&T,&O)!=EOF)
    {
        char ss;
        Build(1,L,1);
        while(O--)
        {

            scanf(" %c",&ss);
            if(ss=='C')
            {
                scanf("%d%d%d",&x,&y,&c);
                if(x>y)
                    Swap();
                inse(x,y,1,c);
            }
            else
            {
                int ans=0;
                scanf("%d%d",&x,&y);
                if(x>y)
                    Swap();

                cc=0;
                quer(x,y,1);
                for(int i=0; i<T; i++)
                {
                    if(cc&(1<<i))
                        ans++;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
