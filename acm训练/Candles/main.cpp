#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=88;
typedef long long ll;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int r,c,tot,vis[maxn][maxn],rt,bot,l,R,mt,sq;
char str[maxn][maxn];
void dfs(int x,int y){
     if(x<1||y<1||x>r||y>c||str[x][y]=='.')return;
     if(vis[x][y])return;
     vis[x][y]=1;
     sq++;
     if(x<mt)mt=x;
     if(x>bot)bot=x;
     if(y<l)l=y;
     if(y>R)R=y;
     dfs(x+1,y);
     dfs(x-1,y);
     dfs(x,y-1);
     dfs(x,y+1);
     return;
}
int main()
{
    rd(r),rd(c);
    REP(i,1,r)scanf("%s",str[i]+1);
  /*  for(int i=1;i<=r;i++){
            REP(j,1,c)printf("%c",str[i][j]);
            cout<<endl;
    }*/
    REP(i,1,r){
       REP(j,1,c){
          if(str[i][j]=='#'&&!vis[i][j]){
               bot=-1,mt=r+1,l=c+1,R=-1,sq=0;
               dfs(i,j);
               tot++;
               if((bot-mt+1)*(R-l+1)==sq)rt++;
          }
       }
    }
    printf("%d\n%d",rt,tot-rt);
    return 0;
}
