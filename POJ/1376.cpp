#include<queue>
#include<stdio.h>
#include<string.h>


using namespace std;


typedef struct
{
  int x ,y ,t ,dir;
}NODE;


int sx ,sy ,ex ,ey ,n ,m ,sdir;
int mark[55][55][5];
int map[55][55];
NODE xin ,tou;


bool jude2(int x ,int y)
{
  return !map[x+1][y] && !map[x][y+1] && !map[x+1][y+1];
}


bool ok(int x ,int y ,int dir)
{
  return x >= 1 && x <= n && y >= 1 && y <= m && !map[x][y] && !mark[x][y][dir] && jude2(x ,y);
}






int BFS()
{
  queue<NODE>q;
  memset(mark ,0 ,sizeof(mark));
  xin.x = sx ,xin.y = sy ,xin.t = 0 ,xin.dir = sdir;
  mark[sx][sy][sdir] = 1;
  q.push(xin);
  while(!q.empty())
  {
    tou = q.front();
    q.pop();
    if(tou.x == ex && tou.y == ey) return tou.t;
    //lift
    xin = tou;
    xin.t ++ ,xin.dir ++;
    if(xin.dir == 5) xin.dir = 1;
    if(ok(xin.x ,xin.y ,xin.dir))
    {
      mark[xin.x][xin.y][xin.dir] = 1;
      q.push(xin);
    }


    //right
    xin = tou;
    xin.t ++ ,xin.dir --;
    if(xin.dir == 0) xin.dir = 4;
    if(ok(xin.x ,xin.y ,xin.dir))
    {
      mark[xin.x][xin.y][xin.dir] = 1;
      q.push(xin);
    }


    for(int i = 1 ;i <= 3 ;i ++)
    {
      xin = tou;
      xin.t ++;
      int mk = 0;
      if(tou.dir == 1)
      {
        xin.x -= i;
        for(int j = xin.x + 1;j < tou.x ;j ++)
        if(map[j][xin.y] || map[j][xin.y+1])
        mk = 1;
      }
      if(tou.dir == 3)
      {
        xin.x += i;
        for(int j = tou.x + 1;j < xin.x ;j ++)
        if(map[j][xin.y] || map[j][xin.y+1])
        mk = 1;
      }
      if(tou.dir == 2)
      {
        xin.y += i;
        for(int j = tou.y + 1 ;j < xin.y ;j ++)
        if(map[xin.x][j] || map[xin.x+1][j]) mk = 1;
      }
      if(tou.dir == 4)
      {
        xin.y -= i;
        for(int j = xin.y + 1 ;j < tou.y ;j ++)
        if(map[xin.x][j] || map[xin.x+1][j]) mk = 1;
      }


      if(!mk && ok(xin.x ,xin.y ,xin.dir))
      {
        mark[xin.x][xin.y][xin.dir] = 1;
        q.push(xin);
      }
    }
  }
  return -1;
}


int main ()
{
  char str[10];
  while(~scanf("%d %d" ,&n ,&m) && n + m)
  {
    memset(map ,255 ,sizeof(map));
    for(int i = 1 ;i <= n ;i ++)
    for(int j = 1 ;j <= m ;j ++)
    scanf("%d" ,&map[i][j]);
    scanf("%d %d %d %d" ,&sx ,&sy ,&ex ,&ey);
    scanf("%s" ,str);
    if(str[0] == 'n') sdir = 1;
    else if(str[0] == 'e') sdir = 2;
    else if(str[0] == 's') sdir = 3;
    else sdir = 4;
    printf("%d\n" ,BFS());


  }
  return 0;
}
