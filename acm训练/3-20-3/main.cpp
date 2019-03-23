# include <bits/stdc++.h>
using namespace std;
const int maxn=366;
int n,m,vis[maxn],p[maxn][maxn],dis[maxn];
int cur[maxn];
bool ok(int now){
      for(int i=1;i<=n;i++)cur[i]=1;
      memset(dis,0,sizeof(dis));
      while(true){
           memset(vis,0,sizeof(vis));
           int dg=1;
           for(int i=1;i<=n;i++){
                while(cur[i]<=m&&dis[p[i][cur[i]]])cur[i]++;
                if(++vis[p[i][cur[i]]]>now){
                    dis[p[i][cur[i]]]=1;
                    dg=0;
                    break;
                }
                if(cur[i]>m){
                    dg=0;
                    return false;
                }
           }
           if(dg)return true;
      }
      return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&p[i][j]);
        }
    }
    int l=1,r=n;
    while(l<=r){
        int mid=l+r>>1;
        if(ok(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
