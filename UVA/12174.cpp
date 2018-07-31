#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
#define maxn 100010
int num[maxn], mark[maxn], ok[maxn], vis[maxn], n, m;

void init() {

    scanf("%d%d", &n, &m);
    memset(mark,0,sizeof(mark));
    memset(vis,0,sizeof(vis));
    memset(ok,0,sizeof(ok));
    for(int i = 0; i < m; i++)
        scanf("%d", &num[i]);

    ok[0] = 1;
    int i;
    for(i = 0; i < n && i < m ; i++)
        if(!vis[num[i]]) {
            ok[i + 1] = 1; 
            vis[num[i]] = 1;
        }
        else
            break;
    if(i == m && i < n && ok[i])
        while(i++ < n)
            ok[i] = 1;

    set<int> s;
    int L = 0, R = 0;
    while(R < m) {
        while(R < m && !s.count(num[R]))
            s.insert(num[R++]);
        if(R == m)
            break;
        if(R - L == n)
            mark[L] = 1;
        s.erase(num[L++]);
    }
    for(int i = L; i < m; i++)
        mark[i] = 1;

    if(m < n)
        for(int i = L; i < n; i++)
            mark[i] = 1;
}

bool check(int s) {
    bool flag = true;
    for(int i = s; i < m; i += n)
        if(!mark[i]) 
            return  false;
    return true;
}

int solve() {
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(ok[i] && check(i))
            ans++;
    return ans;
}

int main() {
    int test, n, m;
    scanf("%d", &test);
    while(test--) {
        init();
        printf("%d\n", solve());
    }
    return 0;
}