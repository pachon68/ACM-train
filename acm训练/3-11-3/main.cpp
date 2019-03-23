#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=2e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
struct node{
    int to,dis;
};
int n,m,vis[maxn],d[maxn];
bool flag=false;
vector<node>g[maxn];
void dfs(int cur){
     vis[cur]=1;
     for(int i=0;i<g[cur].size();i++){
            int to=g[cur][i].to,val=g[cur][i].dis;
            if(vis[to]){
                 if(d[to]!=d[cur]+val){
                        flag=true;
                        break;
                 }
            }
            else d[to]=d[cur]+val,dfs(to);
     }
}
int main()
{
    rd(n),rd(m);
    REP(i,1,m){
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        g[l].push_back({r,w});
        g[r].push_back({l,-w});
    }
    REP(i,1,n){
        if(!vis[i])dfs(i);
        else if(flag)break;
    }
    if(flag)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
