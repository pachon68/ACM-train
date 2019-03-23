#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define REP(k, a, b) for(int k = (a); k <= (b); ++ k)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
const int maxn=266;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int p[maxn][maxn],dp[maxn][maxn],n,m,ans,cur;
int main()
{
    rd(n),rd(m);
    REP(i,1,n)REP(j,1,m){
       scanf("%d",&p[i][j]);
       dp[i][j]=dp[i][j-1]+p[i][j];
    }
    REP(i,1,m){
       REP(j,i,m){
          cur=0;
          REP(k,1,n){
             cur+=dp[k][j]-dp[k][i-1];
             if(cur<0)cur=0;
             if(cur>ans)ans=cur;
          }
       }
    }
    cout<<ans<<endl;
    return 0;
}
