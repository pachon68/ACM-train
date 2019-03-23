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
int n,p[3][maxn],ans,vis[3][maxn];
void dfs(int cx,int cy,int cur){
    if(cx<1||cy<1||cx>2||cy>n)return;
   // vis[cx][cy]=1;
    if(cx==2&&cy==n){
        ans=max(ans,cur);
        return;
    }
    if(cx==1)dfs(cx+1,cy,cur+p[cx+1][cy]);
    //dfs(cx-1,cy,cur+p[cx-1][cy]);
    //dfs(cx,cy-1,cur+p[cx][cy-1]);
    if(cy<n)dfs(cx,cy+1,cur+p[cx][cy+1]);
}
int main()
{
    rd(n);
    REP(i,1,2)REP(j,1,n)scanf("%d",&p[i][j]);
    dfs(1,1,p[1][1]);
    cout<<ans<<endl;
    return 0;
}
