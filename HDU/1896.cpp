#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
    int position,dis;
    friend bool operator < (Node a,Node b){
        if(a.position!=b.position)return a.position>b.position;
        else return a.dis>b.dis;
    }
};
int main(){
    int T,N,k;
    Node m;
    scanf("%d",&T);
    while(T--){k=0;priority_queue<Node>stone;
        scanf("%d",&N);
        while(N--)scanf("%d%d",&m.position,&m.dis),stone.push(m);
        while(!stone.empty()){k++;
            if(k&1)m=stone.top(),m.position+=m.dis,stone.push(m);
            stone.pop();
            if(stone.empty())printf("%d\n",stone.top().position);
        }
    }
    return 0;
}