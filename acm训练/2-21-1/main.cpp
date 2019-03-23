#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n,p[20],in[20],ans[20];
void dfs(int cur){
    if(cur==2*n){
        for(int i=1;i<=2*n;i++)cout<<ans[i]<<' ';
        exit(0);
    }
    if(ans[cur]==-1){
        for(int i=1;i<=n;i++){
            if(!in[i]&&cur+p[i]+1<=2*n){
                if(ans[cur+p[i]+1]!=-1)continue;
                in[i]=1;
                ans[cur]=p[i];
                ans[cur+p[i]+1]=p[i];
                dfs(cur+1);
                ans[cur+p[i]+1]=-1;
                ans[cur]=-1;
                in[i]=0;
            }
            else if(cur+p[i]+1>2*n)break;
        }
    }
    else dfs(cur+1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    sort(p+1,p+1+n);
    memset(in,0,sizeof(in));
    memset(ans,-1,sizeof(ans));
    dfs(1);
    cout<<-1<<endl;
    return 0;
}
