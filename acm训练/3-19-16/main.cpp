#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct node{
     int to,nx;
}p[maxn];
int T,n,k,head[maxn],vis[maxn],tot,d[maxn];
ll small[maxn],big[maxn],val[maxn];
void addedge(int u,int v){
       p[++tot].to=v,p[tot].nx=head[u],head[u]=tot;
}
bool dfs(int now,int fa,int w){
      for(int i=head[now];i;i=p[i].nx){
            int to=p[i].to;
            if(to==fa)continue;
            if(!dfs(to,now,w))return false;
            ll tempsmall=small[to]-w;
            ll tempbig=big[to]+w;
            if(tempsmall>big[now]||tempbig<small[now])return false;
            small[now]=max(small[now],tempsmall);
            big[now]=min(big[now],tempbig);
      }
      return true;
}
bool ok(int cur,int root){
      for(int i=1;i<=n;i++){
           if(vis[i])continue;
           small[i]=-0x3f3f3f3f;
           big[i]=0x3f3f3f3f;
      }
      if(dfs(root,-1,cur))return true;
      else return false;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        tot=0;
        scanf("%d%d",&n,&k);
        memset(d,0,sizeof(d));
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(small,0,sizeof(small));
        memset(big,0,sizeof(big));
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
            d[a]++,d[b]++;
        }
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            small[a]=big[a]=b;
            vis[a]=1;
        }
        int root=1;
        for(int i=1;i<=n;i++){
            if(!d[i]){
                root=i;
                break;
            }
        }
        int l=0,r=0x3f3f3f3f;
        while(l<=r){
            int mid=l+r>>1;
            if(ok(mid,root))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}
