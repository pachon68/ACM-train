#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
#define REP(k, a, b) for(int k = (a); k <= (b); ++ k)
using namespace std;
const int maxn=505;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n,m,dis[maxn],dp[maxn][maxn],w[maxn][maxn];
int main()
{
    rd(n),rd(m);
    REP(i,2,n)rd(dis[i]),dis[i]+=dis[i-1];
    REP(i,1,n){
        REP(j,i,n){
           int mid=i+j>>1;
           REP(k,i,j){
              w[i][j]+=abs(dis[mid]-dis[k]);
           }
        }
    }
    REP(i,0,n){
       REP(j,0,m){
          dp[i][j]=0x3f3f3f3f;
       }
    }
    dp[0][0]=0;
    REP(i,1,n){
        REP(j,1,m){
           if(j>i){
               dp[i][j]=0;
               continue;
           }
           REP(k,j-1,i){
              dp[i][j]=min(dp[i][j],dp[k][j-1]+w[k+1][i]);
           }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
