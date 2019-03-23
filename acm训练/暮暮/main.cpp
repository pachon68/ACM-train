#include<bits/stdc++.h>
#define REP(i, a, b) for(long long int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const long long maxn=1e18+5;
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
long long n,m,k,p[maxn],pre[maxn];
long long ed[maxn],dp[maxn];
int main() {
     rd(n),rd(m),rd(k);
     REP(i,0,n+m+1)pre[i]=-1;
     REP(i,1,n)scanf("%d",&p[i]);
     dp[0]=1;
     REP(i,1,n+m){
          long long cur;
          if(i<=n)cur=p[i];
          else{
             cur=1;
             REP(j,2,k)if(pre[j]<pre[cur])cur=j;
          }
          if(pre[cur]==-1)ed[i]=dp[i-1];
          else ed[i]=(dp[i-1]-dp[pre[cur]-1]+mod)%mod;
          dp[i]=(dp[i-1]+ed[i])%mod;
          pre[cur]=i;
     }
     cout<<dp[m+n]-1<<endl;
     return 0;
}
