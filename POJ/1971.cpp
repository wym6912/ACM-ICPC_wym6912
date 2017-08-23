#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std; 
struct point{    int x,y;};
struct seg{     int a,b;    point v; };
bool operator <(seg a,seg b){
    return (a.v.x<b.v.x)||(a.v.x==b.v.x&&a.v.y<b.v.y);
}    
seg tmp, vs[500500];
point p[1000];
bool common(int i,int j);
int main(){
  int i,j,k,l,n, t; 
  cin>>t; 
  for(k = 0 ; k < t ; k ++)  
  {
     memset(vs,0,sizeof(vs));
     cin>>n; 
     for(i = 0 ;i < n ; i ++)    cin>>p[i].x>>p[i].y; 
     int num=0;
     for(i = 0 ;i < n-1 ; i ++)
          for(j = i +1 ;j < n ;j ++) {
             tmp.a = i;    tmp.b = j;
             tmp.v.x = p[i].x-p[j].x;     tmp.v.y = p[i].y-p[j].y;
             if(tmp.v.x<=0&&tmp.v.y<=0) {
                 tmp.v.x=-tmp.v.x; tmp.v.y=-tmp.v.y;
             }
           if(tmp.v.x<=0&&tmp.v.y>=0) {
                 tmp.v.x=-tmp.v.x; tmp.v.y=-tmp.v.y;
             }
             vs[num++]=tmp; 
          }      
      sort(vs,vs+num); 
       int sum = 0;
       int begin= 0;
       while(begin < num)
	   {
            for(i = begin; vs[i].v.x == vs[begin].v.x&&vs[i].v.y == vs[begin].v.y;i ++)
            	for(j = i + 1;vs[j].v.x == vs[begin].v.x&&vs[j].v.y == vs[begin].v.y;j ++ )      			
					if(!common(i,j)) sum ++;
			begin = i;
       }
       cout<<sum / 2<<endl; 
  }     
  return 0;
}
bool common(int i,int j)
{ 
    if((p[vs[j].b].x-p[vs[i].a].x)*vs[i].v.y==(p[vs[j].b].y-p[vs[i].a].y)*vs[i].v.x)  
		return 1; 
    return 0;
}

