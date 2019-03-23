#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
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
     int to,pos,nx;
}p[2*maxn];
int n,m,head[maxn],cnt,dis[maxn];
void addedge(int u,int v,int w){
     p[++cnt].to=v,p[cnt].nx=head[u],head[u]=cnt,p[cnt].pos=w;
}
set<int>st[maxn];
int main()
{
    rd(n),rd(m);
    REP(i,1,m){
        int u,v,w;
        rd(u),rd(v),rd(w);
        addedge(u,v,w),addedge(v,u,w);
    }
    priority_queue<pair<int,int> >q;
    q.push({0,1});
    REP(i,1,n)dis[i]=0xfffffff;
    dis[1]=0;
    while(!q.empty()){
        int tmp=q.top().second;
        int profit=-q.top().first;
        q.pop();
        if(dis[tmp]<profit)continue;
        for(int i=head[tmp];i;i=p[i].nx){
             int to=p[i].pos;
             int tot=profit+(!st[tmp].count(to));
             if(tot<dis[p[i].to]){
                 dis[p[i].to]=tot;
                 st[p[i].to].clear();
                 st[p[i].to].insert(p[i].pos);
                 q.push({-dis[p[i].to],p[i].to});
             }
             else if(tot==dis[p[i].to])st[p[i].to].insert(to);
        }
    }
    if(dis[n]==0xfffffff)printf("-1\n");
    else printf("%d\n",dis[n]);
    return 0;
}
