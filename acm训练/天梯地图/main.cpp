#include <bits/stdc++.h>
#include<queue>

using namespace std;
const int maxn=1e6+5;
typedef pair<int,int> P;
int n,m;
vector<int>ans1,ans2;
struct node{
     int to,l,t;
};
vector<node>p[maxn];
int d1[maxn],d2[maxn],tmm[maxn],p1[maxn],p2[maxn],s,t,tot[maxn];
void dijtm(){
      priority_queue<P,vector<P>,greater<P> >q;
      memset(d2,127,sizeof(d2));
      memset(tmm,127,sizeof(tmm));
      q.push(P(s,0));
      tmm[s]=0;
      d2[s]=0;
      while(q.size()){
           P cur=q.top();
           q.pop();
           int nd=cur.first,tmptm=cur.second;
           if(tmm[nd]<tmptm)continue;
           for(int i=0;i<p[nd].size();i++){
                int to=p[nd][i].to;
                int tmpdis2=p[nd][i].l;
                int tmptm2=p[nd][i].t;
                if(tmm[to]>tmm[nd]+tmptm2){
                    tmm[to]=tmm[nd]+tmptm2;
                    q.push(P(to,tmptm2+tmm[nd]));
                    d2[to]=d2[nd]+p[nd][i].l;
                    p2[to]=nd;
                }
                else if(tmm[to]==tmm[nd]+tmptm2){
                      if(d2[to]>d2[nd]+tmpdis2){
                           d2[to]=d2[nd]+tmpdis2;
                           p2[to]=nd;
                      }
                }
           }
      }
      return;
}
void dijdis(){
      priority_queue<P,vector<P>,greater<P> >q;
      memset(d1,127,sizeof(d1));
      q.push(P(s,0));
      d1[s]=0;
      while(q.size()){
            P cur=q.top();
            q.pop();
            int nd=cur.first,tmpdis=cur.second;
            if(d1[nd]<tmpdis)continue;
            for(int i=0;i<p[nd].size();i++){
                   int to=p[nd][i].to;
                   int tmpdis2=d1[nd]+p[nd][i].l;
                   if(d1[to]>tmpdis2){
                        d1[to]=tmpdis2;
                        tot[to]=tot[nd]+1;
                        q.push(P(to,d1[to]));
                        p1[to]=nd;
                   }
                   else if(tmpdis2==d1[to]){
                         if(tot[to]>tot[nd]+1){
                            tot[to]=tot[nd]+1;
                            p1[to]=nd;
                         }
                   }
            }
      }
      return;
}
void dfs(int *tmp,int cur,vector<int>& vtmp){
       if(cur==s){
           vtmp.push_back(cur);
           return;
       }
       dfs(tmp,tmp[cur],vtmp);
       vtmp.push_back(cur);
       return;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int v1,v2,o,len,t;
        scanf("%d%d%d%d%d",&v1,&v2,&o,&len,&t);
        if(o)p[v1].push_back(node{v2,len,t});
        else {
             p[v1].push_back(node{v2,len,t});
             p[v2].push_back(node{v1,len,t});
        }
    }
    cin>>s>>t;
    dijtm();
    dijdis();
    dfs(p1,t,ans1);
    dfs(p2,t,ans2);
    bool flag=false;
    if(ans1.size()!=ans2.size())flag=true;
    else{
        for(int i=0;i<ans1.size();i++){
             if(ans1[i]!=ans2[i]){
                 flag=true;
                 break;
             }
        }
    }
    if(!flag){
        printf("Time = %d; Distance = %d: %d",tmm[t],d1[t],s);
        for(int i=1;i<ans1.size();++i)printf(" => %d",ans1[i]);
    }
    else{
        printf("Time = %d: %d",tmm[t],s);
        for(int i=1;i<ans2.size();++i)printf(" => %d",ans2[i]);
        printf("\nDistance = %d: %d",d1[t],s);
        for(int i=1;i<ans1.size();++i)printf(" => %d",ans1[i]);
    }
    return 0;
}
