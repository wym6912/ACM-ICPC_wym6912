#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cassert>

using namespace std; 

typedef long long ll; 
const int maxn = 100005;  
  
int sum[maxn << 2];//求区间和   
int lazy[maxn << 2];//延迟标记   
  
void pushdown(int rt, int m) {  
    if(lazy[rt]) {//如果之前这里做了标记，则说明没有往下更新，暂停了一下，用来判断是否需要往下更新   
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];  
        sum[rt << 1] = (m - (m >> 1)) * lazy[rt];  
        sum[rt << 1 | 1] = (m >> 1) * lazy[rt];  
        lazy[rt] = 0;//往下更新完后，标记置为0，即当前不需要往下更新   
    }  
}  
  
void build(int l, int r, int rt) {  
    lazy[rt] = 0;  
    sum[rt] = r - l + 1;  
    if(l == r) return;  
    int mid = (l + r) >> 1;  
    build(l, mid, rt << 1);  
    build(mid + 1, r, rt << 1 | 1);  
}  
  
void update(int L, int R, int c, int l, int r, int rt) {  
    if(L <= l && r <= R) {  
        sum[rt] = c * (r - l + 1);  
        lazy[rt] = c;//延迟标记，每次把该段更新完后暂时不往下更新，节省时间，这里特别注意和累加的区别，累加是为整个区间增加多少值   
        return;  
    }  
    pushdown(rt, r - l + 1);//向下更新   
    int mid = (l + r) >> 1;  
    if(L <= mid) update(L, R, c, l, mid, rt << 1);  
    if(R >= mid + 1) update(L, R, c, mid + 1, r, rt << 1 | 1);  
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//向上更新   
}  
  
int main() {  
    int T, n, m;  
    scanf("%d", &T);  
    for(int cas = 1; cas <= T; cas ++) {  
        scanf("%d %d", &n, &m);  
        build(1, n, 1);  
          
        for(int i = 0; i < m; i ++) {  
            int a, b, c;  
            scanf("%d %d %d", &a, &b, &c);  
            update(a, b, c, 1, n, 1);  
        }  
          
        printf("Case %d: The total value of the hook is %d.\n", cas, sum[1]);  
    }  
    return 0;  
}  

