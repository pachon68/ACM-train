#include <bits/stdc++.h>

using namespace std;
int n,boom[100005],tmp;
double z,r;
vector<int>G[100005];
double dfs(int cur,int generation){
     double ans=0.0;
     if(G[cur].size()==0)ans=z*boom[cur]*pow(1-r/100.0,generation);
     else{
          for(int i=0;i<G[cur].size();i++)ans+=dfs(G[cur][i],generation+1);
     }
     return ans;
}
int main()
{
    cin>>n;
    scanf("%lf%lf",&z,&r);
    for(int i=0;i<=n-1;i++){
        int ki;
        cin>>ki;
        if(!ki){
            cin>>tmp;
            boom[i]=tmp;
        }
        else{
            for(int j=1;j<=ki;j++){
                cin>>tmp;
                G[i].push_back(tmp);
            }
        }
    }
    cout<<(long long)dfs(0,0)<<endl;
    return 0;
}
