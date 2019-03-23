#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n,k,fa[maxn],vis[maxn],tmp,cur,total,c,query;
int fd(int dis){
      return fa[dis]==dis?dis:fa[dis]=fd(fa[dis]);
}
int main()
{
    cin>>n;
    for(int i=0;i<=10010;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
         cin>>k>>cur;
         vis[cur]=1;
         for(int j=1;j<k;j++){
               cin>>tmp;
               vis[tmp]=1;
               int u=fd(cur),v=fd(tmp);
               if(u!=v){
                   fa[u]=v;
               }
         }
    }
    for(int i=0;i<=10010;i++){
         if(vis[i]){
             total++;
             if(fa[i]==i)c++;
         }
    }
    cin>>query;
    cout<<total<<' '<<c<<endl;
    for(int i=1;i<=query;i++){
         int u,v;
         cin>>u>>v;
         if(fd(u)==fd(v))cout<<'Y'<<endl;
         else cout<<'N'<<endl;
    }
    return 0;
}
