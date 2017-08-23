#include<iostream>
#include<cstdio>
using namespace std;
int search2(int);
int num,a[100],b[100],c[100],sum=0;
int main()
{
    cin>>num;
    search2(1);
    cout<<sum;
    return 0;
}
int search2(int i)
{
    for(int j=1;j<=num;j++)
        if((!a[j])&&(!b[i+j])&&(!c[i-j+num-1]))
        {
            a[j]=1;
            b[i+j]=1;
            c[i-j+num-1]=1;if(i==num)sum++;
            else search2(i+1);
            a[j]=0;
            b[i+j]=0;
            c[i-j+num-1]=0;
        }    		
}
