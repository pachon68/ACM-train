#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=506;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n,m,p[maxn][maxn],vis[maxn][maxn],ans;
void dfs(int cx,int cy){
     if(vis[cx][cy]==1||p[cx][cy]==-1||cx<1||cy<1||cx>n||cy>m)return;
     vis[cx][cy]=1;
     dfs(cx+1,cy);
     dfs(cx-1,cy);
     dfs(cx,cy+1);
     dfs(cx,cy-1);
}
int main()
{
    rd(n),rd(m);
    REP(i,1,n)REP(j,1,m)scanf("%d",&p[i][j]);
    REP(i,1,n){
       REP(j,1,m){
         if(p[i][j]==0&&!vis[i][j]){
                dfs(i,j);
                ans++;
         }
       }
    }
    cout<<ans<<endl;
    return 0;
}
