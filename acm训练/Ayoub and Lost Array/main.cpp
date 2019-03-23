#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=2e5+5;
const int mod=1e9+7;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n,l,r;
long long dp[maxn][5];
int main()
{
    rd(n),rd(l),rd(r);
    int u=r/3-(l-1)/3;
    int v=(r+2)/3-(l-1+2)/3;
    int w=(r+1)/3-(l-1+1)/3;
    dp[1][0]=u,dp[1][1]=v,dp[1][2]=w;
    REP(i,2,n){
        dp[i][0]=(dp[i-1][2]*v%mod+dp[i-1][1]*w%mod+dp[i-1][0]*u%mod)%mod;
        dp[i][1]=(dp[i-1][0]*v%mod+dp[i-1][1]*u%mod+dp[i-1][2]*w%mod)%mod;
        dp[i][2]=(dp[i-1][0]*w%mod+dp[i-1][1]*v%mod+dp[i-1][2]*u%mod)%mod;
    }
    cout<<dp[n][0]<<endl;
}
