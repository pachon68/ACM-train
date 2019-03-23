#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define REP(k, a, b) for(int k = (a); k <= (b); ++ k)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
#define PER(j, a, b) for(int j = (a); j >= (b); -- j)
using namespace std;
const int maxn=206;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
typedef long long ll;
int n,m,s,t;
ll dp[maxn],val[26][206];
ll fast_pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans*=a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main()
{
    memset(dp,127,sizeof(dp));
    rd(n),rd(m);
    REP(i,1,m){
        scanf("%d%d",&s,&t);
        REP(j,1,n){
           val[i][j]=s*fast_pow(j,t);
        }
    }
    dp[0]=0;
    REP(i,1,m){
        PER(j,n,0){
           REP(k,1,j){
              dp[j]=min(dp[j],dp[j-k]+val[i][k]);
           }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
