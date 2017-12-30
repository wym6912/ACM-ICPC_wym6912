#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll MO=998244353;
struct P{
  ll f,g;
  P(){}
  P(ll _f,ll _g){f=_f,g=_g;}
  P operator+(P b){
    if(f<b.f)return b;
    if(f>b.f)return *this;
    return P(f,(g+b.g)%MO);
  }
  P operator*(P b){return P(f+b.f,g*b.g%MO);}
};
struct E{
  P v0,v1;
  E(){}
  E(P _v0,P _v1){v0=_v0,v1=_v1;}
};
map<ll,E>T;
E solve(ll a,ll b){
  ll len=b-a;
  if(T.find(len)!=T.end())return T[len];
  if(a==b)return T[len]=E(P(0,1),P(-1,0));
  ll mid=(a+b)>>1;
  E l=solve(a,mid),r=solve(mid+1,b);
  P v0=(l.v0+l.v1)*(r.v0+r.v1);
  P v1=(l.v0*(r.v0+r.v1))+((l.v0+l.v1)*r.v0);
  if(v1.f>=0)v1.f++;
  return T[len]=E(v0,v1);
}
int main(){
  ll n;
  scanf("%lld",&n);
  E ans=solve(1,n);
  ans.v0=ans.v0+ans.v1;
  printf("%lld %lld",ans.v0.f,ans.v0.g);
  return 0;
}