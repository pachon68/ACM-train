#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=36;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int dp[maxn][maxn],t[maxn][maxn],n,p[maxn],tot;
int dfs(int l,int r){
     if(dp[l][r]>0)return dp[l][r];
     if(l>r)return 1;
     if(l==r){
         dp[l][r]=p[l];
         t[l][r]=l;
     }
     else{
         REP(i,l,r){
            int tmp=dfs(l,i-1)*dfs(i+1,r)+p[i];
            if(tmp>dp[l][r]){
                dp[l][r]=tmp;
                t[l][r]=i;
            }
         }
     }
     return dp[l][r];
}
void dfs2(int l,int r){
    if(l>r)return;
    if(!tot)cout<<t[l][r];
    else cout<<' '<<t[l][r];
    tot++;
    dfs2(l,t[l][r]-1);
    dfs2(t[l][r]+1,r);
}
int main()
{
    rd(n);
    REP(i,1,n)rd(p[i]);
    cout<<dfs(1,n)<<endl;
    dfs2(1,n);
    return 0;
}
