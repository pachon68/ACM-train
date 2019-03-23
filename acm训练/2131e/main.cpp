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
vector<int>e[maxn];
int dfn[maxn],low[maxn],tot,vis[maxn],cnt,scc[maxn];
stack<int>sk;
int tarjan(int cur){
     dfn[cur]=low[cur]=++tot;
     sk.push(cur);
     vis[cur]=1;
     for(int i=0;i<e[cur].size();i++){
          int to=e[cur][i];
          if(!dfn[to]){
               tarjan(to);
               low[cur]=min(low[to],low[cur]);
          }
          else if(vis[to])low[cur]=min(low[cur],dfn[to]);
     }
     if(dfn[cur]==low[cur]){
          cnt++;
          int now;
          do{
              now=sk.top();
              sk.pop();
              vis[now]=0;
              scc[now]=cnt;
          }while(now!=cur);
     }
}
int main()
{
    int n,m;
    rd(n),rd(m);
    REP(i,1,n){
        int now;
        rd(now);
        e[i].push_back(now+n);
        e[now+n].push_back(i);
    }
    REP(i,1,m){
        int s,t;
        rd(s),rd(t);
        e[s].push_back(t);
        e[t].push_back(s);
    }
    REP(i,1,n){
       if(!dfn[i])tarjan(i);
    }
    int ans=0;
    REP(i,1,n){
       if(scc[i]==scc[i+n])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
