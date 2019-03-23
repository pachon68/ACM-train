#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n,m,k,query,tmp,vis[maxn];
bool flag;
vector<int>G[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    cin>>query;
    for(int i=1;i<=query;i++){
        cin>>k;
        flag=false;
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=k;j++){
            cin>>tmp;
            vis[tmp]=1;
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<G[j].size();k++){
                if(!vis[j]&&!vis[G[j][k]])flag=true;
            }
            if(flag)break;
        }
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
