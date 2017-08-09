#include<iostream>
#include<cstdio>
using namespace std;
int search2(int,int ,int );
int n,k;
int main()
{
    cin>>n>>k;
    cout<<search2(n,k,1);
    return 0;
}
int search2(int a,int b,int c)
{
    int f=0;
    if(b==1)f=1;
    else for(int i=c;i<=a/b;i++)
    f+=search2(a-i,b-1,i);
    return f;
}
