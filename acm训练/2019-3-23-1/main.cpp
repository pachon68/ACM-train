#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+10;
int dp[maxn][5][5],n,m,p[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        p[tmp]++;
    }
    memset(dp,-127,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int h=0;h<3;h++){
                     if(p[i]<h+j+k)continue;
                     dp[i][k][j]=max(dp[i][k][j],dp[i-1][h][k]+(p[i]-h-j-k)/3+h);
                }
            }
        }
    }
    cout<<dp[m][0][0]<<endl;
    return 0;
}
