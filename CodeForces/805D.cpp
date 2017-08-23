#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    string s;
    cin>>s;
    long long ans = 0,cnt = 0;
    int n = s.size();
    for(int i = n - 1;i >= 0;i --){
        if(s[i] == 'b')
            cnt ++;
        else
        {
            ans += cnt;
            ans %= mod;
            cnt = cnt * 2 % mod;
        }
    }
    printf("%I64d\n",ans % mod);
    return 0;
}
