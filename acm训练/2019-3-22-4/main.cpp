#include<bits/stdc++.h>

using namespace std;
const int maxn=26;
int n,k,p[maxn],tot,cur[maxn];
int dfs(int com,int ave,int sum,int idx){
     if(!com)return 1;
     if(sum==0)return dfs(com-1,ave,ave,1);
     for(int i=idx;i<=n;i++){
          if(cur[i])continue;
          cur[i]=1;
          if(sum-p[i]>=0&&dfs(com,ave,sum-p[i],i+1))return 1;
          cur[i]=0;
     }
     return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        tot+=p[i];
    }
    if(tot%k){
        cout<<"No"<<endl;
        return 0;
    }
    if(dfs(k,tot/k,tot/k,1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
