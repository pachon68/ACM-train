#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
struct node{
    int to,nx;
}p[maxn<<1];
int n,head[maxn<<1],tot,d[maxn],ans;
void addedge(int s,int t){
     p[++tot].to=t,p[tot].nx=head[s],head[s]=tot;
}
void dfs(int ver,int fa,int cur){
      int mx=0,minn=maxn;
      for(int i=head[ver];i;i=p[i].nx){
            if(p[i].to==fa)continue;
            dfs(p[i].to,ver,cur);
            mx=max(mx,d[p[i].to]+1);
            minn=min(minn,d[p[i].to]+1);
      }
      if(mx+minn<0)d[ver]=minn;
      else d[ver]=mx;
      if(d[ver]>=cur)ans++,d[ver]=-cur-1;
}
bool ok(int cur){
     ans=0;
     memset(d,0,sizeof(d));
     dfs(1,0,cur);
     if(d[1]>=0)ans++;
     return ans>2;
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        addedge(x,y),addedge(y,x);
    }
    int l=0,r=n;
    while(l<=r){
        int mid=l+r>>1;
        if(ok(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
