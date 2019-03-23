#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=2e6+5;
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
     int u,v,t,nx;
}p[3000010];
int n,m,vis[maxn],head[maxn],tot,dis[maxn],dfn[maxn],low[maxn],cnt,gt[maxn];
void addedge(int u,int v,int w){
      p[++tot].v=v,p[tot].nx=head[u],head[u]=tot,p[tot].t=w;
}
stack<int>sk;
void tarjan(int cur){
      dfn[cur]=low[cur]=++tot;
      sk.push(cur);
      vis[cur]=1;
      for(int i=head[cur];i;i=p[i].nx){
           int to=p[i].v;
           if(!dfn[to]){
               tarjan(to);
               low[cur]=min(low[cur],low[to]);
           }
           else if(vis[to])low[cur]=min(low[cur],dfn[to]);
      }
      if(dfn[cur]==low[cur]){
           int now;
           cnt++;
           do{
                now=sk.top();
                sk.pop();
                vis[now]=0;
                gt[now]=cnt;
           }while(now!=cur);
      }
}
void spfa(){
      REP(i,1,n)vis[i]=0;
      memset(dis,0x7f,sizeof(dis));
      memset(vis,0,sizeof(vis));
      queue<int>q;
      q.push(1);
      vis[1]=1,dis[1]=0;
      while(!q.empty()){
           int cur=q.front();
           q.pop();
           vis[cur]=0;
           for(int i=head[cur];i;i=p[i].nx){
                 int to=p[i].v;
                 if(gt[to]==gt[cur])p[i].t=0;
                 if(dis[to]>dis[cur]+p[i].t){
                       dis[to]=dis[cur]+p[i].t;
                       if(!vis[to]){
                            q.push(to);
                            vis[to]=1;
                       }
                 }
           }
      }

}
int main()
{
    rd(n),rd(m);
    REP(i,1,n)dis[i]=1e9;
    REP(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    tot=0;
    REP(i,1,n)if(!dfn[i])tarjan(i);
    spfa();
    cout<<dis[n]<<endl;
    return 0;
}
