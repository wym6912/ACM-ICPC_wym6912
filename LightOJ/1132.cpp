#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>

using namespace std;

#define clr( x , y ) memset(x,y,sizeof(x))
#define cls( x ) memset(x,0,sizeof(x))
#define mp make_pair
#define pb push_back
typedef long long lint;
typedef long long ll;
typedef long long LL;

const int maxn = 52;
const lint mod = (1LL << 32);
lint n,k;
int kase;
lint C[maxn][maxn];

struct Matrix{
    int n , m ;
    lint a[maxn][maxn];
    Matrix( int n , int m ){
        this->n = n ;
        this->m = m ;
        cls(a);
    }
    Matrix operator * ( const Matrix &tmp ){
        Matrix res( n , tmp.m );
        for( int i = 0 ; i  < n ; i++ )
            for( int j = 0 ; j < tmp.m ; j++ )
                for( int k = 0 ; k < m ; k++ )
                    res.a[i][j] = ( res.a[i][j] + ( a[i][k] * tmp.a[k][j] ) % mod ) % mod;
        return res;
    }
};

void Matrix_print( Matrix x ){
    for( int i = 0 ; i < x.n ; i++ ){
        for( int j = 0 ; j < x.m ; j++){
            cout << x.a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void init(){
    cls(C);
    C[0][0] = 1;
    for( int i = 1 ; i < maxn ; i++ ){
        C[i][0] = 1;
        for( int j = 1 ; j <= i ; j++ ){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if( C[i][j] > mod ) C[i][j] -= mod;
        }
    }
}
Matrix fast_pow( Matrix x , lint n ){
    Matrix res( x.n , x.m );
    for( int i = 0 ; i < x.n ; i++ ) res.a[i][i] = 1;
    while( n ){
        if( n & 1 )
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

void solve(){
    if(k == 0){
        printf( "Case %d: %lld\n" , kase++ , n % mod );
        return;
    }
    Matrix base( k + 2 , 1 );
    Matrix fun( k + 2 , k + 2 );
    fun.a[0][0] = 1;
    for( int i = 1 ; i < k + 2 ; i++ ) fun.a[0][i] = C[k][i - 1];
    for( int i = 1 ; i < k + 2 ; i++ ){
        for( int j = i ; j < k + 2 ; j++ ){
            fun.a[i][j] = C[k - i + 1][j - i];
        }
    }
    for( int i = 0 ; i < k + 2 ; i++ ) base.a[i][0] = 1;
    //Matrix_print( fun );
    //Matrix_print( base );
    fun = fast_pow( fun , n - 1 );
    base = fun * base ;
    printf( "Case %d: %lld\n" , kase++ , base.a[0][0] % mod );
}
int main(){
  //freopen("input.txt","r",stdin);
    int t ; cin >> t ; kase = 1;
    init();
    while( t-- ){
        cin >> n >> k ;
        solve();
    }
    return 0;
}

