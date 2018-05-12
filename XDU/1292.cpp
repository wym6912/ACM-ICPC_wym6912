#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 300008;
const int MOD = 1e9 + 7;
int n, m, f, t;
int data[273], tmpdata[273];
 
string str, oth;
 
int main()
{
    while(cin >> str)
    {
        memset(data, 0, sizeof(data));
        int ans = 0, strsize = str.size();
        for(int i = 0; i < str.size(); i ++)
            data[str[i]] ++;
        cin >> n;
        while(n --)
        {
            cin >> oth;
            memset(tmpdata, 0, sizeof(tmpdata));
            int osize = oth.size();
            bool flag = true;
            for(int i = 0; i < osize; i ++)
                tmpdata[oth[i]] ++;
            for(int i = 0; i < 256; i ++)
                if(tmpdata[i] > data[i])
                {
                    flag = false;
                    break;
                }
            if(flag)ans = max(ans, osize);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
masterblodpo
7
boogie
magnolia
punch
blood
master
inherent
phantom
ablderrivala
5
arrival
blade
runner
incendies
sicario
 
*/