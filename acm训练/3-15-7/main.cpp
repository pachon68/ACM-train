#include <bits/stdc++.h>

using namespace std;
int n,vis[26],root,p[28];
char str[26][26];
bool flag=false;
void dfs(int cur,int tot){
       vis[cur]=1,p[tot]=cur;
       if(tot==n){
             if(str[cur][root]=='W'||str[root][cur]=='L')flag=true;
             return;
       }
       bool run=false;
       for(int i=1;i<=n;i++){
            if(!vis[i]&&(str[i][1]=='W'||str[1][i]=='L'))run=true;
       }
       if(!run)return;
       for(int i=1;i<=n;i++){
             if((!vis[i]&&str[cur][i]=='W')||(!vis[i]&&str[i][cur]=='L')){
                  vis[i]=1;
                  dfs(i,tot+1);
                  if(flag)return;
                  vis[i]=0;
             }
       }
       return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++){
          root=i;
          memset(vis,0,sizeof(vis));
          dfs(i,1);
          if(flag){
               for(int j=1;j<=n;j++){
                    if(j!=n)printf("%d ",p[j]);
                    else printf("%d",p[j]);
               }
               break;
          }
    }
    if(!flag)cout<<"No Solution";
    return 0;
}
