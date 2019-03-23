#include <bits/stdc++.h>

using namespace std;
int v,e,k,vis[506],p[505][505],query,color[505],total;
bool flag;
int main()
{
    cin>>v>>e>>k;
    for(int i=1;i<=e;i++){
        int s,t;
        cin>>s>>t;
        p[s][t]=p[t][s]=1;
    }
    cin>>query;
    for(int i=1;i<=query;i++){
         memset(vis,0,sizeof(vis));
         flag=false,total=0;
         for(int j=1;j<=v;j++){
             cin>>color[j];
             if(!vis[color[j]])vis[color[j]]=1,total++;
         }
         if(total!=k){
              cout<<"No"<<endl;
              continue;
         }
         for(int j=1;j<=v;j++){
             for(int k=j+1;k<=v;k++){
                if(color[j]==color[k]&&p[j][k]){
                    cout<<"No"<<endl;
                    flag=true;
                    break;
                }
             }
             if(flag)break;
         }
         if(!flag)cout<<"Yes"<<endl;
    }
    return 0;
}
