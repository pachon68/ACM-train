#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+6;
int n,tmp,root,tot,p[maxn],mx=-1;
vector<int>G[maxn];
void dfs1(int cur,int cnt){
      if(G[cur].size()==0){
           mx=max(mx,cnt);
           return;
      }
      for(int i=0;i<G[cur].size();i++){
           dfs1(G[cur][i],cnt+1);
      }
      return;
}
void dfs2(int cur,int cnt){
     if(cnt==mx){
        p[++tot]=cur;
        return;
     }
     for(int i=0;i<G[cur].size();i++){
           dfs2(G[cur][i],cnt+1);
     }
     return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp==-1)tmp=0,root=i;
        G[tmp].push_back(i);
    }
    dfs1(root,1);
    dfs2(root,1);
    cout<<mx<<endl;
    for(int i=1;i<=tot;i++){
        if(i!=1)cout<<' ';
        cout<<p[i];
    }
    return 0;
}
