#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <cmath>  
#include <stack>  
#include <bitset>  
#include <queue>  
#include <set>  
#include <map>  
#include <string>  
#include <algorithm>  
#define FOP freopen("data.txt","r",stdin)  
#define FOP2 freopen("data1.txt","w",stdout)  
#define inf 0x3f3f3f3f  
#define maxn 310  
#define mod 4  
#define PI acos(-1.0)  
#define LL long long  
using namespace std;  
  
typedef int Matrix[maxn][maxn];  
int x[maxn];  
int sum;  
  
int gcd(int a, int b)  
{  
    return b == 0 ? a : gcd(b, a%b);  
}  
  
int lcm(int a, int b)  
{  
    return a / gcd(a, b) * b; //防溢出  
}  
  
//equ个方程，var个变元 A[r][c], 0<r<equ, 0<c<var  
int gauss_elimination(Matrix A, int equ, int var)  
{  
    memset(x, 0, sizeof(x));  
    int row, col; //当前处理的行row和列col  
    int max_r;  
    for(row = 0, col = 0; row < equ && col < var; row++, col++)  
    {  
        if(A[row][col] == 0)  
        {  
            for(int r = row+1; r < equ; r++)  
                if(A[r][col])  
                {  
                    for(int c = 0; c <= var; c++) swap(A[row][c],A[r][c]);  
                    break;  
                }  
        }  
  
        //与第row+1~equ行进行消元  
        int LCM, ta, tb;  
        for(int r = row+1; r < equ; r++)  
        {  
            if(A[r][col] == 0) continue;  
  
            LCM = lcm(abs(A[r][col]),abs(A[row][col]));  
            ta = LCM / abs(A[r][col]);  
            tb = LCM / abs(A[row][col]);  
            if(A[r][col] * A[row][col] < 0) tb = -tb;//异号的情况是相加  
            for(int c = col; c <= var; c++)  
            {  
                A[r][c] = A[r][c] * ta - A[row][c] * tb;  
                A[r][c] = (A[r][c]%mod+mod)%mod;  
            }  
        }  
    }  
  
    int temp;  
    for (int r = var - 1; r >= 0; r--)  
    {  
        temp = A[r][var];  
        for(int c = r + 1; c < var; c++)  
        {  
            if (A[r][c] != 0) temp -= x[c] * A[r][c];  
            temp = (temp%mod+mod)%mod;  
        }  
        while(temp % A[r][r] != 0) temp += mod; //剩余系的特殊处理  
        x[r] = (temp / A[r][r])%mod;  
        sum += x[r];  
    }  
    return 0;  
}  
  
Matrix A;  
  
int vis[][9] = {1, 1, 0, 1, 0, 0, 0, 0, 0,  
                1, 1, 1, 0, 1, 0, 0, 0, 0,  
                0, 1, 1, 0, 0, 1, 0, 0, 0,  
                1, 0, 0, 1, 1, 0, 1, 0, 0,  
                1, 0, 1, 0, 1, 0, 1, 0, 1,  
                0, 0, 1, 0, 1, 1, 0, 0, 1,  
                0, 0, 0, 1, 0, 0, 1, 1, 0,  
                0, 0, 0, 0, 1, 0, 1, 1, 1,  
                0, 0, 0, 0, 0, 1, 0, 1, 1  
               };  
int cot;  
  
int main()  
{  
    int t, n = 9;  
    for(int i = 0; i < n; i++)  
    {  
        for(int j = 0; j < n; j++) A[i][j] = vis[i][j];  
        scanf("%d", &t);  
        A[i][n] = (mod - t)%mod;  
    }  
  
    gauss_elimination(A, n, n);  
  
    for(int i = 0; i < n; i++)  
    {  
        while(x[i]--)  
        {  
            printf("%d", i+1);  
            sum--;  
            printf(sum > 0 ?  " " : "\n");  
        }  
    }  
  
    return 0;  
}  
