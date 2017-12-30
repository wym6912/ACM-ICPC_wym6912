#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=210;
char a[N],b[N],c[N],fin[N];
int n,i;
int cnt;
bool f[N][N];
string best;
inline bool check(int len,string cur){
	int i,j,k;
	for(i=1;i<=len;i++)b[i]=cur[i-1];
	int tot=0;
	for(i=1;i*len<=n;i++)for(j=1;j<=len;j++)c[++tot]=b[j];
	sort(c+1,c+n+1);
	for(i=1;i<=n;i++)if(c[i]!=fin[i])return 0;
	for(i=0;i<=n+1;i++)for(j=0;j<=n+1;j++)f[i][j]=0;
	for(i=n;i;i--){
		f[i][i-1]=1;
		for(j=i;j<=n;j++){
			for(k=j-len;k>=i-1;k-=len){
				if(f[i][k]&&f[k+1][j]){f[i][j]=1;break;}
			}
			int o=j-i+1;
			o%=len;
			if(!o)o+=len;
			if(f[i][j-1]&&a[j]==b[o])f[i][j]=1;
		}
	}
	return f[1][n];
}
void solve(int len){
	if(n%len)return;
	for(int i=1;i+len-1<=n;i++){
		string now="";
		for(int j=0;j<len;j++)now.push_back(a[i+j]);
		if(cnt&&best<=now)continue;
		if(check(len,now)){
			cnt++;
			best=now;
		}
	}
	if(cnt){
		cout<<best<<endl;
		exit(0);
	}
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(i=1;i<=n;i++)fin[i]=a[i];
	sort(fin+1,fin+n+1);
	for(i=1;i<n;i++)solve(i);
	puts(a+1);
}