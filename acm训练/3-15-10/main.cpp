#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n;
struct node{
     int to,pre,dis,cnt;
     bool operator<(const node &tmp)const{
           if(dis!=tmp.dis)return dis>tmp.dis;
           else return cnt>tmp.cnt;
     }
};
struct graph{
     int to,nx;
}p[maxn];
priority_queue<node>q;
int head[maxn],d[maxn],tot,vis[maxn],dm[maxn],pre[maxn]
void add(int s,int t){
      p[++tot].to=t,p[tot].nx=head[s],head[s]=tot;
}
void dij(int s,int t){
       memset(vis,0,sizeof(vis));
       memset(dm,127,sizeof(dm));
       memset(pre,0,sizeof(pre));
       dm[s]=0;
       q.push(node{s,0,0,0});
       while(q.size()){
             node tmp=q.top();
             q.pop();
             if(vis[tmp.to])continue;
             for(int i=head[tmp.to];i;i=p[i].nx){
                    int to=p[i].to;
                    if(dm[])
             }
       }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int m,tmp,tmp2;
        cin>>m>>tmp;
        for(int j=1;j<=m;j++){
            cin>>tmp2;
            add(tmp,tmp2),add(tmp2,tmp);
            tmp=tmp2;
        }
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int s,t;
        cin>>s>>t;
        dij(s,t);
    }
    return 0;
}
