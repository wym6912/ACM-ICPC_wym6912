#include <bits/stdc++.h>

using namespace std;

void printspace(int n)
{
    for(int i = 1;i <= n;i ++)
        printf(" ");
}
 
void printal(int n)
{
    for(int i = 1;i <= n;i ++)
        printf("%c",'A' + i - 1);
    for(int i = n - 1;i >= 1;i --)
        printf("%c",'A' + i - 1);
}
 
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1;i <= n;i ++)
        {
            printspace (26 - i);
            printal(i);
            printf("\n");
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1189
    User: 16020120071
    Language: C++
    Result: ÕýÈ·
    Time:1 ms
    Memory:1704 kb
****************************************************************/
