#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int card[40],ans[40],cardtemp[40],numcard[4];
int smalldealint[10];
inline int deal();
void read();
inline int is7()//判7对的函数
{
    for(int i=0;i<36;i++)
    if(card[i]&&card[i]!=2) return 0;
    return 1;
}
inline int is131()//判13幺的函数
{
    if((card[0]&&card[9]&&card[8]&&card[17]&&card[18]&&card[26]&&card[27]&&card[28]&&card[29]&&card[30]&&card[31]&&card[32]&&card[33])
    &&(card[0]+card[9]+card[8]+card[17]+card[18]+card[26]+card[27]+card[28]+card[29]+card[30]+card[31]+card[32]+card[33]==14))
    return 1;
    return 0;
}
inline int smalldeal(int p,int n);
inline int getnum(int p,int n)//数同种花色的牌有几种
{
    int num=0;
    for(int i=p;i<n+p;i++)
        num+=card[i];
    return num;
}
inline void output(int numans,int ans[]);
int main()
{
    int T;cin>>T;
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        memset(cardtemp,0,sizeof(cardtemp));
        int numans=0;
        read();
        memset(numcard,0,sizeof(numcard));
        for(int i=0;i<28;i+=9)
            numcard[i/9]=getnum(i,9);
        copy(card,card+39,cardtemp);
        for(int i=0;i<34;i++)//枚举哪张牌可以听
            if(cardtemp[i]<4)
            {
                copy(cardtemp,cardtemp+35,card);//把card备份一下，因为下面的操作要修改card数组
                if(card[i+1]==0&&i!=0&&card[i-1]==0&&(card[i]==0||card[i]==3)) continue;//各种剪枝
                //不懂得想一下就懂了
                card[i]++;//加入这张牌
                numcard[i/9]++;//把同种花色的牌的个数加1
                if(is7()||is131()) numans+=ans[i]=1;//如果是十三幺或7对
                else if(deal()) numans+=ans[i]=1;//不然判普通的胡法
                memset(card,0,sizeof(card));//把牌清零，貌似是废话
                numcard[i/9]--;//把同种花色的牌的个数减回没有加牌之前的状态
            }
        output(numans,ans);//输出结果
    }
    return 0;
}
inline int deal()//普通的判胡的处理函数
{
    int num2=0;
    for(int i=0;i<4;i++)
        if(numcard[i]%3==1) return 0;//有单张牌
        else if (numcard[i]%3==2) num2++;//判一下不同花色的牌有几个花色的个数是3*k+2的个数
    if(num2!=1) return 0;//如果同种花色的牌的个数是3*k+2的形式的没有或不止一种 ，则不可能胡牌
    for(int i=0;i<3;i++)//先判 饼 索 万牌的形式能不能胡
    {
        if(numcard[i]%3==0)//如果同种花色牌的个数是3的倍数，则里面没有眼
        {
            if(!smalldeal(i*9,9)) return 0;//3的倍数的牌不合法，则整副牌也不合法
        }
        else//说明牌的个数是3K+2里面有眼，现在需要枚举这对眼
        {
            int f=0;
            copy(&card[i*9],&card[i*9+9],smalldealint);//因为smalldeal函数会直接修改数组，所以要备份一下
            for(int j=i*9;j<i*9+9;j++)
            {
                copy(smalldealint,smalldealint+9,&card[i*9]);//备份还原
                 if(card[j]>1)
                {
                    card[j]-=2;//枚举眼
                    if(smalldeal(i*9,9)) {f=1;break;}//眼合法就不用枚举了
                }
            }
            if(!f) return 0;//枚举眼都不合法，这幅牌也不合法了
        }
    }
    //处理 风牌，东南西北什么的
    if(numcard[3]%3==2)//眼在风牌里面
    for(int i=27;i<34;i++)
    {
        if(card[i]==4) return 0;//四张风直接返回假值
        if(card[i]==2) {card[i]=0;break;}//这里可能也有一个眼，找到一个眼就不用找了
    }
    for(int i=27;i<35;i++)//那么剩下的风牌必须全是3张或0张
    if(card[i]&&card[i]!=3) return 0;
    return 1;
}
inline int smalldeal(int p,int n)//处理3的倍数的牌是不是全能组成3个3个合法牌
{//返回真假值
    for(int i=p;i<p+n;i++)
        if(card[i])
        {
            if(card[i]>=3) card[i]=card[i]-3;
            if(card[i])
            {
                if(!card[i+1]||!card[i+2]||i+2>=p+n) return 0;
                if(card[i]>card[i+1]||card[i]>card[i+2]) return 0;
                card[i+1]-=card[i],card[i+2]-=card[i];
                card[i]=0;
            }
        }
    return 1;
}
inline void read()//读入函数
{
    memset(card,0,sizeof(card));
    for(int i=0;i<13;i++)
    {
        getchar();
        char a[5];
        scanf("%s",a);
        int num=(int)(a[0]-'0');
        if(a[1]=='m') card[num-1]++;
        if(a[1]=='s') card[num-1+9]++;
        if(a[1]=='p') card[num-1+18]++;
        if(a[1]=='c') card[num-1+27]++;
    }
}
inline void output(int numans,int ans[])//输出结果的函数
{
    if(!numans) printf("Nooten\n");//如果没有牌可以听
    else
    {
        cout<<numans;
        for(int i=0;i<35;i++)//按大小输出结果
        if(ans[i])
        {
            if(i/9==0) printf(" %dm",i%9+1);
            else if(i/9==1) printf(" %ds",i%9+1);
            else if(i/9==2) printf(" %dp",i%9+1);
            else printf(" %dc",i%9+1);
        }
       printf("\n");
    }
}

