#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int s;
    cin>>s;
    long long a[40];
    a[1]=1;
    a[2]=1;
    for(int k=3;k<=s;k++)a[k]=a[k-1]+a[k-2];
    cout<<a[s];
    return 0;
}
