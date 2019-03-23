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
priority_queue<int,vector<int>,greater<int> >q;
vector<int>ans;
bool vis[maxn];
int head[maxn],n,m,tot;
struct node{
    int to,nx;
}p[maxn];
void addedge(int s,int t){
     p[++tot].to=t,p[tot].nx=head[s],head[s]=tot;
}
int main()
{
    rd(n),rd(m);
    REP(i,1,m){
        int u,v;
        rd(u),rd(v);
        addedge(u,v),addedge(v,u);
    }
    q.push(1);
    while(!q.empty()){
         int cur=q.top();
         q.pop();
         if(vis[cur])continue;
         vis[cur]=true;
         ans.push_back(cur);
         for(int i=head[cur];i;i=p[i].nx){
              int to=p[i].to;
              if(vis[to])continue;
             // vis[to]=1;
              q.push(to);
         }
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    return 0;
}
