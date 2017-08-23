#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define SIZE 1000000
int b[SIZE + 1],c[SIZE + 1];
int lowbit(int i) {
    return i&-i;
}
void Update(int i,int x){
    while (i <= SIZE){
        c[i] += x;
        i+= lowbit(i);
    }
}
int Sum(int i){
    int sum = 0;
    while(i > 0){
        sum += c[i];
        i-=lowbit(i);
    } 
    return sum;
}

int main(){
    int i,l,r;
    b[1] = 0; b[2] = 1;
    Update(2,1);
    for (i=3;i<=1000000;i++){
        if (i % 2 == 0){
            b[i] = b[i/2] + 1;
        }
        else 
            b[i] = b[i-1] + 1;
        Update(i,b[i]); 
    }
    while (scanf("%d %d",&l,&r) != EOF){
        int s1 = Sum(r);
        int s2 = Sum(l);
        printf("%d\n",s1-s2+b[l]);
    }
    return 0;
}
