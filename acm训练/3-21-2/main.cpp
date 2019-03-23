#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=66000;
int n;
ll p[maxn];
//int q[maxn];
ll tot;
void dfs(int cur,int val,ll now){
    if(cur==n+1){
        tot=max(tot,now);
        return;
    }
    for(ll i=0;i<=p[cur];i++){
         if(i<=val){
            //for(int j=1;j<=i;j++)q[j]=0;
            dfs(cur+1,-1,0);
         }
         else{
             //q[cur]=i;
             dfs(cur+1,i,now+i);
         }
    }
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    dfs(1,-1,0);
    cout<<tot<<endl;
    //for(int i=1;i<=n;i++)cout<<q[i]<<' ';
    return 0;
}
