#include <bits/stdc++.h>

using namespace std;

const int maxn = 3009;

int tree[maxn][maxn];
bool mark[maxn][maxn];

int lowbit(int t){return t & -t;}

int update(int x, int y, int num)
{
    for(int i = x;i <= maxn;i += lowbit(i))
        for(int j = y;j <= maxn;j += lowbit(j))
            tree[i][j] += num;
}

int query(int x, int y)
{
    int sum = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        for(int j = y;j > 0;j -= lowbit(j))
            sum += tree[i][j];
    return sum;
}

int main()
{
    string str;
    int n, x, y;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n --)
    {
        cin >> str;
        if(str[0] == 'B')
        {
            cin >> x >> y;
            x ++, y ++;
            if(!mark[x][y]){mark[x][y] = true;update(x, y, 1);}
        }
        if(str[0] == 'D')
        {
              cin >> x >> y;
              x ++,y ++;
              if(mark[x][y]){mark[x][y] = false;update(x, y, -1);}
        }
        if(str[0] == 'Q')
        {
             int x1, x2, y1, y2;
             cin >> x1 >> x2 >>y1 >> y2;
             x1 ++, x2 ++, y1 ++, y2 ++;
             if(x1 < x2)swap(x1, x2);
             if(y1 < y2)swap(y1, y2);
             int ans = query(x1, y1) - query(x1, y2 - 1) - query(x2 - 1, y1) + query(x2 - 1, y2 - 1);
             cout << ans << endl;
        }
    }
    return 0;
}
