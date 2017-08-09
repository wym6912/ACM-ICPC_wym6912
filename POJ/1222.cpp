#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cassert>
#define LL long long

using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = 4 * atan(1.0);
const double ee = exp(1.0);
const int maxn = 100 + 10;

int a[maxn][maxn];  //Ôö¹ã¾ØÕó
int x[maxn];        //½â¼¯
bool freeX[maxn];   //±ê¼Ç½âÊÇ·ñÊÇ×ÔÓÉ±äÔª

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

//¸ßË¹ÏûÔª½â·½³Ì×é
//·µ»ØÖµ-2±íÊ¾ÓÐ¸¡µãÊý½â£¬ÎÞÕûÊý½â
//·µ»ØÖµ-1±íÊ¾ÎÞ½â£¬0±íÊ¾ÓÐÎ¨Ò»½â£¬´óÓÚ0±íÊ¾ÓÐÎÞÇî½â£¬·µ»Ø×ÔÓÉ±äÔª¸öÊý
//ÓÐequ¸ö·½³Ì£¬var¸ö±äÔª
//Ôö¹ã¾ØÕóÐÐÊý[0, equ - 1]
//Ôö¹ã¾ØÕóÁÐÊý[0, var]
int gauss(int equ, int var)
{
    for (int i = 0; i <= var; i++)
    {
        x[i] = 0;
        freeX[i] = true;
    }
    //×ª»»Îª½×ÌÝ¾ØÕó
    //col±íÊ¾µ±Ç°ÕýÔÚ´¦ÀíµÄÕâÒ»ÁÐ
    int col = 0;
    int row = 0;
    //maxR±íÊ¾µ±Ç°Õâ¸öÁÐÖÐÔªËØ¾ø¶ÔÖµ×î´óµÄÐÐ
    int maxRow;
    for (; row < equ && col < var; row++, col++)
    {
        //Ã¶¾Ùµ±Ç°ÕýÔÚ´¦ÀíµÄÐÐ
        //ÕÒµ½¸ÃcolÁÐÔªËØ¾ø¶ÔÖµ×î´óµÄÄÇÐÐÓëµÚkÐÐ½»»»
        maxRow = row;
        for (int i = row + 1; i < equ; i++)
        {
            if (abs(a[maxRow][col]) < abs(a[i][col]))
            {
                maxRow = i;
            }
        }
        if (maxRow != row)
        {
            //ÓëµÚrowÐÐ½»»»
            for (int j = row; j < var + 1; j++)
            {
                swap(a[row][j], a[maxRow][j]);
            }
        }
        if (a[row][col] == 0)
        {
            //ËµÃ÷¸ÃcolÁÐµÚrowÐÐÒÔÏÂÈ«ÊÇ0£¬´¦Àíµ±Ç°ÐÐµÄÏÂÒ»ÁÐ
            row--;
            continue;
        }
        for (int i = row + 1; i < equ; i++)
        {
            //Ã¶¾ÙÒªÉ¾µÄÐÐ
            if (a[i][col] != 0)
            {
                for (int j = col; j < var + 1; j++)
                {
                    ///
                    a[i][j] ^= a[row][j];
                }
            }
        }
    }
    for (int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
        {
            ///
            x[i] ^= (a[i][j] && x[j]);
        }
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    int ncase;
    int ca = 1;
    scanf("%d", &ncase);
    while (ncase--)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 30; i++)
        {
            scanf("%d", &a[i][30]);
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int t = i * 6 + j;
                a[t][t] = 1;
                if(i>0)a[(i-1)*6+j][t]=1;
                if(i<4)a[(i+1)*6+j][t]=1;
                if(j>0)a[i*6+j-1][t]=1;
                if(j<5)a[i*6+j+1][t]=1;
            }
        }
        gauss(30, 30);
        printf("PUZZLE #%d\n", ca++);
        for(int i = 0; i < 30; i++)
        {
            printf("%d", x[i]);
            if((i+1) % 6 == 0)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}