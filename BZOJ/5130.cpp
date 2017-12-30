#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x, y;
ll n;
int R,C;
int ret;
const int N=2222;
char f[N][N],vis[N][N];

void solve(int d, ll i)
{
	if(d==0){
		x+=i;
	}
	if(d==1){
		y-=i;
	}
	if(d==2){			
		x-=i;
	}
	if(d==3){
		y+=i;
	}
		
	if(d==0){
		y++;
	}
	if(d==1){
		x++;
	}
	if(d==2){
		y--;
	}
	if(d==3){
		x--;
	}
		
}

ll mo(ll a,ll b){return (a%b+b)%b;}

inline void col(int x,int y,int c){
	if(!vis[x][y]){
		vis[x][y]=1;
		f[x][y]=c;
		ret--;
	}
}
inline void moveup(int x,int l,int r,int c){
	for(int i=l;i<=r;i++)col(x,i,c);
}
inline void moveright(int y,int l,int r,int c){
	for(int i=l;i<=r;i++)col(i,y,c);
}

inline void walk(ll x1,ll y1,ll x2,ll y2,int c){
	if(x1==x2){
		if(y1>y2)swap(y1,y2);
		ll k=y2-y1+1;
		y1=mo(y1,C);
		if(k>=C)moveup(mo(x1,R),0,C-1,c);
		else{
			if(y1+k-1<C)moveup(mo(x1,R),y1,y1+k-1,c);
			else{
				moveup(mo(x1,R),y1,C-1,c);
				moveup(mo(x1,R),0,mo(y2,C),c);
			}
		}
	}else{
		if(x1>x2)swap(x1,x2);
		ll k=x2-x1+1;
		x1=mo(x1,R);
		if(k>=R)moveright(mo(y1,C),0,R-1,c);
		else{
			if(x1+k-1<R)moveright(mo(y1,C),x1,x1+k-1,c);
			else{
				moveright(mo(y1,C),x1,R-1,c);
				moveright(mo(y1,C),0,mo(x2,R),c);
			}
		}
	}
}

void solve2(ll n, int d,int c)
{
	ll xx = x, yy = y;
	if(d == 0){		// rgt
		x += n;
	}
	else if(d == 1){	// down
		y -= n;
	}
	else if(d == 2){	// lft
		x -= n;
	}	
	else if(d == 3){	// up
		y += n;
	}
	walk(xx,yy,x,y,c);
	if(d == 0){		// rgt
		y ++;
	}
	else if(d == 1){	// down
		x ++;
	}
	else if(d == 2){	// lft
		y --;
	}	
	else if(d == 3){	// up
		x --;
	}
}
int main()
{
	scanf("%d%d",&R,&C);
	scanf("%lld%lld",&x,&y);
	
	
	x=R-x+1;
	swap(x,y);
	swap(R,C);
	
	scanf("%lld", &n);
	
	x--,y--;
	x%=R;
	y%=C;
	
	
	ll A = n / 4, B = n % 4;
	x += -2 * A + 1, y += -2 * A;
	x%=R;
	y%=C;
	for(int i = 0; i < B; i ++){
		solve((i+3)%4, A * 4 + i);
		x%=R;
		y%=C;
	}
	for(int i=0;i<R;i++)for(int j=0;j<C;j++){
		f[i][j]='.';
		ret++;
	}
	if(n%4==0){
		col(mo(x-1,R),mo(y,C),'@');
	}
	if(n%4==1){
		col(mo(x,R),mo(y+1,C),'@');
	}
	if(n%4==2){
		col(mo(x+1,R),mo(y,C),'@');
	}
	if(n%4==3){
		col(mo(x,R),mo(y-1,C),'@');
	}
	for(ll i=n;i;i--){
		solve2(i-1, i % 4,(i-1+26)%26+'A');
		x%=R;
		y%=C;
		if(!ret)break;
	}
	for(int j=C-1;~j;j--){
		for(int i=0;i<R;i++)putchar(f[i][j]);
		puts("");
	}
}
