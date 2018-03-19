#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<ctime> 

using namespace std;

#define REP(i, a, b) for(int i = (a), _end_ = (b);i <= _end_; ++i)

typedef long long LL;

int m[3][3];  

int a[100050];  

void f() {  
    a[0] = 0;  
    a[1] = 1;  
    REP(i, 2, 100050)
        a[i] = (a[i - 1] + a[i - 2]) % 10000;  
}  

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {  
        if(n == -1) 
            break;  
        f();  
        printf("%d\n", a[n % 15000]);  
    }  
    return 0;
}