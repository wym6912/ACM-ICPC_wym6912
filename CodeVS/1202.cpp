#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int num,sum=0,k;
    cin>>num;
    for(int a=1;a<=num;a++)
    {
        cin>>k;
        sum+=k;
    }
    cout<<sum;
    return 0;
}
