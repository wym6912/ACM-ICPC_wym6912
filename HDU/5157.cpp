//#define NOSTDCPP
//#define Cpp11
//#define Linux_System
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#endif

# ifdef Linux_System
# define getchar getchar_unlocked
# define putchar putchar_unlocked
# endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define midf(x, y) ((x + y) >> 1)
# define DXA(_) ((_ << 1))
# define DXB(_) ((_ << 1) | 1)

# define next __Chtholly__
# define x1 __Mercury__
# define y1 __bbtl04__
# define index __ikooo__

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;
typedef long double ld;

const int MOD = 1e9 + 7;
const int maxn = 100000 + 10;
const int maxc = 30;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll myrand(ll mod){return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod;}

template <class T>
inline bool scan_d(T & ret)
{
	char c;
	int sgn;
	if(c = getchar(), c == EOF)return false;
	while(c != '-' && (c < '0' || c > '9'))c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while(c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + (c - '0');
	ret *= sgn;
	return true;
}
#ifdef Cpp11
template <class T, class ... Args>
inline bool scan_d(T & ret, Args & ... args)
{
	scan_d(ret);
	scan_d(args...);
}
#define cin.tie(0); cin.tie(nullptr);
#define cout.tie(0); cout.tie(nullptr);
#endif
inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n')ch = getchar();
	return true;
}

inline void out_number(ll x)
{
	if(x < 0)
	{
		putchar('-');
		out_number(- x);
		return ;
	}
	if(x > 9)out_number(x / 10);
	putchar(x % 10 + '0');
}

int n;
char s[maxn];
struct PA
{
	int num[maxn],len[maxn],fail[maxn],S[maxn], ch[maxn][maxc];	
	int p,last,cnt, ans[maxn];
	ll tot[maxn];
	
	//tot ��ʾ��ǰ�ڵ��ʾ���Ĵ��еĺ�׺�ӻ��Ĵ��ĸ���(�����Լ�)
	//len ��ǰ�ڵ��ʾ�Ļ��Ĵ��ĳ���
	//S ������ӵ��ַ�
	//p�ڵ���� cnt�ַ�������
	
	int newnode(int l){
	    tot[p]=0; num[p]=0; len[p]=l;
	    return p++;
	}
	void init(){
	    p=0; memset(ch,0,sizeof(ch));
	    newnode(0); newnode(-1);
	    last=0; cnt=0; S[cnt]=-1; fail[0]=1;
	    //��ͷ��һ���ַ�����û�е��ַ�����������
	}
	int get_fail(int x){ //��KMPһ����ʧ�����һ���������
	    while(S[cnt-len[x]-1]!=S[cnt]) x = fail[x];
	    return x;
	}
	ll add(int c,int pos){ //�����Ե�ǰ�ַ���β�Ļ��Ĵ�����
	    S[++cnt]=c;
	    int cur=get_fail(last); //ͨ����һ�����Ĵ���������Ĵ���ƥ��λ��
	    if (!ch[cur][c]){
	    	//���������Ĵ�û�г��ֹ���˵��������һ���µı��ʲ�ͬ�Ļ��Ĵ�
	        int now=newnode(len[cur]+2); // �½��ڵ�
	        fail[now]=ch[get_fail(fail[cur])][c];
	        //��AC�Զ���һ������failָ�룬�Ա�ʧ�����ת
	        ch[cur][c]=now;
	        num[now] = num[fail[now]] + 1;
	        //tot[now] = tot[fail[now]] + 1;
	    }
	    last = ch[cur][c];
	    tot[last]++;
	    return ans[pos] = num[last];
	}
};

PA shunx;

ll cnt_s[maxn], cnt_n[maxn];

int main()
{
    while(~ scanf("%s", s))
    {
	    n = strlen(s);
	    shunx.init();
	    //nix.init();
	    for(int i = 0; i < n; ++ i)
	    	cnt_s[i] = shunx.add(s[i] - 'a' + 1, i);
	    reverse(s, s + n);
	    //cout << s << endl;
	    shunx.init();
	    cnt_n[n] = 0;
	    for(int i = 0; i < n; ++ i)
	    	cnt_n[n - i - 1] = shunx.add(s[i] - 'a' + 1, i) + cnt_n[n - i];
	    /*
	    for(int i = 0; i < n; ++ i)	
	    	cout << cnt_s[i] << ' ' << cnt_n[i + 1] << endl;
	    */	
	    ll ans = 0;
	    for(int i = 0; i < n; ++ i)
	    	ans += cnt_s[i] * cnt_n[i + 1];
	    printf("%lld\n", ans);
	}
	return 0;
}