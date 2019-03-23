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
     long long x,y,r,val;
}p[maxn];
int dfn[maxn],low[maxn],in[maxn],T,n,tot,pos[maxn],cnt,vis[maxn],w[maxn];
vector<int>g[maxn];
stack<int>sk;
void tarjan(int cur){
     dfn[cur]=low[cur]=++tot;
     vis[cur]=1;
     sk.push(cur);
     for(int i=0;i<g[cur].size();i++){
          int to=g[cur][i];
          if(!dfn[to]){
               tarjan(to);
               low[cur]=min(low[cur],low[to]);
          }
          else if(vis[to])low[cur]=min(low[cur],dfn[to]);
     }
     if(dfn[cur]==low[cur]){
           cnt++;
           int now;
           do{
                now=sk.top();
                sk.pop();
                pos[now]=cnt;
                vis[now]=0;
                w[cnt]=min(w[cnt],(int)p[now].val);
           }while(now!=cur);
     }
}
int main()
{
    int many=1;
    rd(T);
    while(T--){
        rd(n);
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(in,0,sizeof(in));
        memset(w,127,sizeof(w));
        memset(vis,0,sizeof(vis));
        memset(pos,0,sizeof(pos));
        tot=0,cnt=0;
        REP(i,1,n)g[i].clear();
        REP(i,1,n){
             scanf("%lld%lld%lld%lld",&p[i].x,&p[i].y,&p[i].r,&p[i].val);
             for(int j=1;j<i;j++){
                  if((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)<=p[i].r*p[i].r){
                         g[i].push_back(j);
                  }
                  if((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)<=p[j].r*p[j].r){
                         g[j].push_back(i);
                  }
             }
        }
        REP(i,1,n)if(!dfn[i])tarjan(i);
        REP(i,1,n){
           for(int j=0;j<g[i].size();j++){
               int to=g[i][j];
               if(pos[i]!=pos[to])in[pos[to]]++;
           }
        }
        long long ans=0;
        REP(i,1,cnt){
            if(!in[i])ans+=w[i];
        }
        cout<<"Case #"<<many++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
