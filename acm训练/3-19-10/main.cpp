#include <bits/stdc++.h>

using namespace std;
const int maxn=266;
struct node{
      int to,nx;
}p[maxn];
int n,m,dp[maxn][maxn],tot,head[maxn];
void addedge(int u,int v){
     p[++tot].to=v,p[tot].nx=head[u],head[u]=tot;
}
void dfs(int cur){
     for(int i=head[cur];i;i=p[i].nx){
          int to=p[i].to;
          dfs(to);
          for(int j=m;j>=0;j--){
                    for(int k=1;k<=j;k++){
                        dp[cur][j]=max(dp[cur][j],dp[to][j-k]+dp[cur][k]);
                    }
          }
     }
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m){
         memset(head,0,sizeof(head));
         tot=0;
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=n;i++){
             int a,b;
             scanf("%d%d",&a,&b);
             addedge(a,i),dp[i][1]=b;
         }
         m++;
         dfs(0);
         cout<<dp[0][m]<<endl;
    }
    return 0;
}
