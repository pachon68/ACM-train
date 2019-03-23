#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
struct node{
     int to,nx;
}p[maxn*3];
struct node2{
     int to,nx;
}q[maxn*3];
int n,m,dfn[maxn],low[maxn],head[maxn],tot,vis[maxn],scc[maxn],cnt,sz[maxn],d[maxn],head2[maxn];
double ans;
void addedge(int s,int t){
      p[++tot].to=t,p[tot].nx=head[s],head[s]=tot;
}
void addedge2(int s,int t){
      d[t]++;
      q[++tot].to=t,q[tot].nx=head2[s],head2[s]=tot;
}
stack<int>sk;
void tarjan(int cur){
      dfn[cur]=low[cur]=++tot;
      sk.push(cur);
      vis[cur]=1;
      for(int i=head[cur];i;i=p[i].nx){
             int to=p[i].to;
             if(!dfn[to]){
                  tarjan(to);
                  low[cur]=min(low[cur],low[to]);
             }
             else if(!scc[to])low[cur]=min(low[cur],dfn[to]);
      }
      if(dfn[cur]==low[cur]){
           int now;
           cnt++;
           do{
                now=sk.top();
                sk.pop();
                vis[now]=0;
                scc[now]=cnt;
                sz[cnt]++;
           }while(now!=cur);
      }
}
int ok(int cur){
      if(d[cur]||sz[cur]!=1)return 0;
      for(int i=head2[cur];i;i=q[i].nx){
          if(d[q[i].to]==1)return 0;
      }
      return 1;
}
void rebuild(){
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=p[j].nx){
            if(scc[i]!=scc[p[j].to])addedge2(scc[i],scc[p[j].to]);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
         int u,v;
         cin>>u>>v;
         addedge(u,v);
    }
    tot=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    tot=0;
    rebuild();
    for(int i=1;i<=cnt;i++){
          if(!d[i])ans++;
    }
    for(int i=1;i<=cnt;i++){
         if(ok(i)){
             ans--;
             break;
         }
    }
    printf("%.6f",(double)(n-ans)/(double)n);
    return 0;
}
