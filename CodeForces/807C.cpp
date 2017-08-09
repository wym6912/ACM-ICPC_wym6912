#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a,b,c,d;
    while(n--)
    {
       scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
       if(c==0)
       {
           if(a!=0)
           cout<<-1<<endl;
           else
           cout<<0<<endl;
       }
       else if(c==d)
       {
           if(a==b)
           cout<<0<<endl;
           else
           cout<<-1<<endl;
       }
       else
       {
           long long p,q;
           if((c*b-d*a)%(d-c)==0)
           {
               p=(c*b-d*a)/(d-c);
           }
           else
           {
               p=(c*b-d*a)/(d-c)+1;
           }
           if((a*d-c*b)%c==0)
           {
               q=(a*d-c*b)/c;
           }
           else
		   	q=(a*d-c*b)/c+1;
           if(p<q)
           	p=q;
           if((p+b)%d!=0)
           	p=((p+b)/d+1)*d-b;
           cout<<p<<endl;
       }
    }
    return 0;
}

