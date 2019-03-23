#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e6+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
const int mod=1e9+7;
long long len,ans,dp[maxn][16];
char str[maxn];
int main(){
    scanf("%s",str);
    len=strlen(str);
    if(str[0]=='*')dp[0][4]=dp[0][5]=1;
    if(str[0]=='0')dp[0][0]=1;
    if(str[0]=='1')dp[0][2]=1;
    if(str[0]=='2'||str[len-1]=='2'){puts("0"); return 0;}
    if(str[0]=='?')dp[0][0]=dp[0][2]=dp[0][4]=dp[0][5]=1;
    REP(i,1,len){
        if (str[i]=='*'||str[i]=='?')dp[i][4]=dp[i][5]=(dp[i-1][2]+dp[i-1][3]+dp[i-1][4])%mod;
        if (str[i]=='0'||str[i]=='?')dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
        if (str[i]=='1'||str[i]=='?')dp[i][2]=(dp[i-1][1]+dp[i-1][0])%mod,dp[i][1]=dp[i-1][5];
        if (str[i]=='2'||str[i]=='?')dp[i][3]=dp[i-1][5];
    }
    len--;
    ans=(dp[len][0]+dp[len][1]+dp[len][5])%mod;
    cout<<ans<<endl;
    return 0;
}
