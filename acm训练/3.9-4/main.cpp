//#include<iostream>
#include<cstring>
#include<cstdio>
//#include<time.h>
//#include<complex>
//#include<set>
#include<algorithm>
//#include<math.h>
#include<stdlib.h>
using namespace std;

int n,m;
char mp[15][15];

int a[15]; bool vis[15],ans=0;

bool v2[15];
bool check()
{
//    for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
    memset(v2,0,sizeof(v2));
    bool used=(m&1);
    for (int i=1;i<=m;i++) if (!v2[i])
    {
        bool flag=0;
        for (int j=i+1;j<=m;j++) if (!v2[j])
        {
            bool ff=1;
            for (int k=1;k<=n;k++) if (mp[a[k]][i]!=mp[a[n-k+1]][j]) ff=0;
            if (ff) {v2[j]=1; flag=1; break;}
        }
        if (!flag)
        {
            if (used)
            {
                bool ff=1;
                for (int k=1;k<=n;k++) if (mp[a[k]][i]!=mp[a[n-k+1]][i]) ff=0;
                if (ff) used=0;
                else return 0;
            }
            else return 0;
        }
    }
    return 1;
}
void dfs(int cur,int pos,bool odd)
{
    if (ans) return;
    if (cur>n) {ans=check(); return;}
    if (vis[cur]) {dfs(cur+1,pos,odd); return;}
    for (int i=cur+1;i<=n;i++) if (!vis[i])
    {
        a[pos]=i; a[n-pos+1]=cur;
        vis[i]=1;
        dfs(cur+1,pos+1,odd);
        vis[i]=0;
    }
    if (odd)
    {
        a[(n>>1)+1]=cur;
        dfs(cur+1,pos,0);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    dfs(1,1,n&1);
    puts(ans?"YES":"NO");
    return 0;
}
