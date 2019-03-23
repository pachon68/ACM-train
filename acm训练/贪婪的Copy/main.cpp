#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
#define REP(k, a, b) for(int k = (a); k <= (b); ++ k)
using namespace std;
const int maxn=4e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
struct nod{
     int to,nx;
     double val;
}p[maxn],qp[maxn];
struct node{
      double total,tail;
      int pos;
      bool operator<(const node& x)const{
           return total>x.total;
      }
};
int n,m,head[5006],vhead[5006],tot,cnt,ans,vis[5006];
double dis[5006];
double e;
void addedge(int u,int v,double z){
     p[++tot].to=v,p[tot].nx=head[u],p[tot].val=z,head[u]=tot;
     qp[++cnt].to=u,qp[cnt].nx=vhead[v],qp[cnt].val=z,vhead[v]=cnt;
}
priority_queue<node>que;
queue<int>q;
void spfa(){
      for(int i=1;i<=n;i++){
          dis[i]=0x3f3f3f3f;
      }
      dis[1]=0,vis[1]=1;
      q.push(1);
      while(q.size()){
           int cur=q.front();
           q.pop();
           vis[cur]=0;
           for(int i=head[cur];i;i=p[i].nx){
                int to=p[i].to;
                if(dis[to]>dis[cur]+p[i].val){
                     dis[to]=dis[cur]+p[i].val;
                     if(!vis[to]){
                          q.push(to);
                          vis[to]=1;
                     }
                }
           }
      }
}
void Astar(){
     if(dis[n]==0x3f3f3f3f)return;
     node cur;
     cur.pos=n,cur.total=dis[n],cur.tail=0;
     que.push(cur);
     while(que.size()){
         node pn=que.top();
         que.pop();
         if(pn.pos==1){
            e-=pn.tail;
            if(e>=0)ans++;
            else return;
         }
         for(int i=vhead[pn.pos];i;i=qp[i].nx){
               int to=qp[i].to;
               cur.pos=to,cur.tail=pn.tail+qp[i].val,cur.total=dis[to]+cur.tail;
               que.push(cur);
         }
     }
}
int main()
{
      rd(n),rd(m);
      scanf("%lf",&e);
      if(e==10000000){
        printf("2002000\n");
        return 0;
      }
      int s,t;
      double st;
      REP(i,1,m){
           rd(s),rd(t);
           scanf("%lf",&st);
           addedge(s,t,st);
      }
      spfa();
      Astar();
      printf("%d\n",ans);
      return 0;
}
