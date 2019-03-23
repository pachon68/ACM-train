#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n;
ll cnt[maxn];
ll dp[5][maxn];
char str[maxn],d[10]="hard";
int main()
{
    rd(n);
    scanf("%s",str+1);
 //   printf("%s",str+1);
    REP(i,1,n)rd(cnt[i]);
    REP(i,0,3){
       REP(j,0,n+1){
          dp[i][j]=0x3f3f3f3f;
       }
    }
    PER(i,n,1){
       if(str[i]==d[3]){
           if(dp[3][i+1]==0x3f3f3f3f)dp[3][i]=cnt[i];
           else dp[3][i]=dp[3][i+1]+cnt[i];
       }
       else dp[3][i]=dp[3][i+1];
    }
    PER(i,2,0){
       PER(j,n,1){
          if(str[j]==d[i]&&dp[i+1][j]!=0x3f3f3f3f){
                if(dp[i][j+1]==0x3f3f3f3f){
                    dp[i][j]=min(cnt[j],dp[i+1][j]);
                }
                else dp[i][j]=min(dp[i][j+1]+cnt[j],dp[i+1][j]);
          }
          else dp[i][j]=dp[i][j+1];
       }
    }
    if(dp[0][1]==0x3f3f3f3f)cout<<0<<endl;
    else cout<<dp[0][1]<<endl;
    return 0;
}
