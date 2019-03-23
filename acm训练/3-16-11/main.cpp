#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+10;
char str[maxn];
long long dp[maxn][6];
int main()
{
    scanf("%s",str+1);
    dp[0][0]=1;
    int n=strlen(str+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=3;j++){
            if(!dp[i-1][j])continue;
            if(j<3)dp[i][j+1]+=dp[i-1][j];
            dp[i][j]+=dp[i-1][j];
            for(int k=i-1;k>=1&&(i-k)<=j;k--){
                 if(str[i]==str[k]){
                    dp[i][j]-=dp[k-1][j-(i-k)];
                    break;
                 }
            }
        }
    }
    cout<<dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]<<endl;
    return 0;
}
