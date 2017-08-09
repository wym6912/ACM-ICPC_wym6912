#include<stdio.h>
#include<string.h>
const int mod = 10;
inline void cm(int &x){ if(x >= mod) x %= mod; }
struct mat{
    int sz, r[70][70];
    mat(int _sz){ sz = _sz; memset(r, 0, sizeof(r)); }
    mat operator * (mat a){
        mat res = mat(sz);
        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz ; ++j){
                for(int k = 0; k < sz; ++k){
                    res.r[i][j] += r[i][k] * a.r[k][j];
                    cm(res.r[i][j]);
                }
            }
        }
        return res;
    }
};
mat getB(int n){
    mat res = mat(n*2);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &res.r[i][j]);
            res.r[i][j+n] = res.r[i][j];
        }
        res.r[i+n][i+n] = 1;
    }
    return res;
}
mat matpow(int n, int k){
    mat b = getB(n);
    mat res = mat(b.sz);
    for(int i = 0; i < res.sz; ++i) res.r[i][i] = 1;
    while(k){
        if(k&1) res = res*b;
        b = b*b;
        k >>= 1;
    }
    return res;
}
int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        mat ans = matpow(n, k);
        printf("Case %d:\n", ca++);
        for(int i = 0; i < n; ++i){
            for(int j = n; j < n*2; ++j){
                putchar(ans.r[i][j]+'0');
            }
            putchar('\n');
        }
    }
}
