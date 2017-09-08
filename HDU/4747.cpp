
#pragma comment(linker, "/STACK:102400000,102400000")  
#include <iostream>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#include <cmath>  
#include <map>  
#include <set>  
#include <stack>  
#include <string.h>  
//freopen ("in.txt" , "r" , stdin);  
using namespace std;  
  
#define eps 1e-8  
#define zero(_) (abs(_)<=eps)  
const double pi=acos(-1.0);  
typedef long long LL;  
const int Max=200010;  
const LL INF=0x3FFFFFFF;  
int arr[Max];  
int mex[Max];  
map<int,int> maps;  
struct node  
{  
    LL sum;//表示和  
    int ma;//表示区间最大值  
    int lazy;//表示区间值一样  
    int l,r;  
    node* pl,*pr;  
} tree[3*Max];  
int tot=0;  
int Next[Max];  
void build(node* p,int left,int right)  
{  
    p->l=left;  
    p->r=right;  
    if(left==right)  
    {  
        p->ma=mex[left];  
        p->sum=mex[left];  
        p->lazy=0;  
        return ;  
    }  
    int middle=(left+right)/2;  
    tot++;  
    p->pl=tree+tot;  
    build(p->pl,left,middle);  
    tot++;  
    p->pr=tree+tot;  
    build(p->pr,middle+1,right);  
    p->sum=p->pl->sum+p->pr->sum;  
    p->ma=max(p->pl->ma,p->pr->ma);  
}  
  
void update(node* p,int value,int left,int right);  
void down(node* p)  
{  
    if(p->l==p->r)  
        return ;  
    p->lazy=0;  
    int middle=(p->l+p->r)/2;  
    update(p->pl,p->ma,p->l,middle);  
    update(p->pr,p->ma,middle+1,p->r);  
}  
int findpos(node* p,int value)  
{  
    if(p->l==p->r)  
    {  
        if(p->ma>=value)  
            return p->l;  
    }  
    if(p->lazy)  
        down(p);  
    if(p->pl->ma>value)  
        return findpos(p->pl,value);  
    return findpos(p->pr,value);  
}  
void update(node* p,int value,int left,int right)  
{  
    if(p->l==left&&p->r==right)  
    {  
        p->lazy=1;  
        p->ma=value;  
        p->sum=(p->r-p->l+1)*value;  
        return;  
    }  
    LL ans=0;  
    int middle=(p->l+p->r)/2;  
    if(p->lazy)  
    {  
        down(p);  
    }  
    if(left>middle)  
    {  
        update(p->pr,value,left,right);  
    }  
    else if(right<=middle)  
        update(p->pl,value,left,right);  
    else  
    {  
        update(p->pl,value,left,middle);  
        update(p->pr,value,middle+1,right);  
    }  
    p->sum=p->pl->sum+p->pr->sum;  
    p->ma=max(p->pl->ma,p->pr->ma);  
}  
int n;  
int main()  
{  
  
    while(cin >> n && n)  
    {  
        tot=0;  
        memset(tree,0,sizeof(tree));  
        memset(Next,0,sizeof(Next));  
        maps.clear();  
        for(int i=1; i<=n; i++)  
            scanf("%d",arr+i);  
        int p=0;  
        for(int i=1; i<=n; i++)  
        {  
            Next[maps[arr[i]]]=i;  
            maps[arr[i]]=i;  
            while(maps.find(p)!=maps.end())p++;  
            mex[i]=p;  
        }  
        build(tree,1,n);  
        LL ans=0;  
        for(int i=1; i<=n; i++)  
        {  
            ans+=tree->sum;  
            if(Next[i]==0) Next[i]=n+1;  
            if(tree->ma>arr[i])  
            {  
                int pos=findpos(tree,arr[i]);  
                if(pos<=Next[i]-1)  
                    update(tree,arr[i],pos,Next[i]-1);  
            }  
            update(tree,0,i,i);  
        }  
        cout<<ans<<"\n";  
    }  
    return 0;  
}  
