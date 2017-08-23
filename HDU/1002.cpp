#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
    int a[100001],b[100001],c[100001],d;
    char a1[100001],a2[100001];
    int N;
    cin>>N;
    for(int m=1;m<=N;m++)
	{
    cin>>a1>>a2;
    cout<<"Case "<<m<<":"<<endl;
    cout<<a1<<" + "<<a2<<" = ";
    d=1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    a[0]=strlen(a1);
    b[0]=strlen(a2);
    for(int s=1;s<=a[0];s++)a[s]=a1[a[0]-s]-'0';
    for(int s=1;s<=b[0];s++)b[s]=a2[b[0]-s]-'0';
    int x=0;
    while(d<=a[0]||d<=b[0])
    {
         c[d]=a[d]+b[d]+x;
         x=c[d]/10;
         c[d]%=10;
         d++;
    }
    c[d]=x;
    if(c[d]==0)d--;
    for(int s=d;s>=1;s--)cout<<c[s];
    cout<<endl;
    if(m!=N)cout<<endl;
	}
    return 0;
}