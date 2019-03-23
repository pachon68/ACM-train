#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e5+5;
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
      int v,nx;
}p[maxn];
int f,r,dfn[maxn],low[maxn],vis[maxn],head[maxn],tot,cnt,ans,deg[maxn],scc[maxn],u[maxn],v[maxn];
void addedge(int s,int t){
      p[++tot].v=t,p[tot].nx=head[s],head[s]=tot;
}
bool eq[maxn];
stack<int>sk;
void tarjan(int cur){
     dfn[cur]=low[cur]=++tot;
     sk.push(cur);
     vis[cur]=1;
     for(int i=head[cur];i;i=p[i].nx){
           if(eq[i])continue;
           int to=p[i].v;
           if(!dfn[to]){
                eq[(i&1)?i+1:i-1]=true;
                tarjan(to);
                eq[(i&1)?i+1:i-1]=false;
                low[cur]=min(low[cur],low[to]);
           }
           else if(vis[to]){
                low[cur]=min(low[cur],dfn[to]);
           }
     }
     if(dfn[cur]==low[cur]){
           int now;
           cnt++;
           do{
                now=sk.top();
                sk.pop();
                scc[now]=cnt;
                vis[now]=0;
           }while(now!=cur);
     }
}
int main()
{
    rd(f),rd(r);
    REP(i,1,r){
       rd(u[i]),rd(v[i]);
       addedge(u[i],v[i]);
       addedge(v[i],u[i]);
    }
    tot=0;
    REP(i,1,f)if(!dfn[i])tarjan(i);
    REP(i,1,r){
        if(scc[u[i]]!=scc[v[i]]){
            deg[scc[u[i]]]++,deg[scc[v[i]]]++;
        }
    }
    REP(i,1,f){
         if(deg[i]==1)ans++;
    }
    cout<<((ans+1)>>1)<<endl;
    return 0;
}
