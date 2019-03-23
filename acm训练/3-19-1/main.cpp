#include <bits/stdc++.h>

using namespace std;
const int maxn=1100;
struct node{
     int x,y;
};
int sx[8]={0,1,-1,0,0},sy[8]={0,0,0,1,-1},n,m,dis[maxn][maxn],p[maxn][maxn];
queue<node>q;
int main()
{
    scanf("%d%d",&n,&m);
    char temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            while( ( temp =  getchar() ) != '1' && temp != '0' );
            p[i][j]=temp-'0';
            dis[i][j]=-1;
            if(p[i][j]){
                q.push(node{i,j});
                dis[i][j]=0;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<p[i][j]<<' ';
        }
        cout<<endl;
    }*/
    while(q.size()){
         node cur=q.front();
         q.pop();
         for(int i=1;i<=4;i++){
               int dx=cur.x+sx[i],dy=cur.y+sy[i];
               if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&dis[dx][dy]==-1){
                    dis[dx][dy]=dis[cur.x][cur.y]+1;
                    q.push(node{dx,dy});
               }
         }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j!=1) cout<<' ';
            cout<<dis[i][j];
        }
        cout<<endl;
    }
    return 0;
}
