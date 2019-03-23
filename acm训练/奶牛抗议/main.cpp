#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1000000009;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int t,w,p[maxn],dp[1005][3][35];
int dfs(int tm,int tree,int pos){
     if(tm>t)return 0;
     if(dp[tm][tree][pos])return dp[tm][tree][pos];
     int u=0,v=0;
     if(pos<w&&tree!=p[tm]){
           u=dfs(tm+1,3-tree,pos+1)+1;
     }
     v=dfs(tm+1,tree,pos)+(tree==p[tm]);
     return dp[tm][tree][pos]=max(u,v);
}
int main()
{
    rd(t),rd(w);
    REP(i,1,t)rd(p[i]);
    cout<<dfs(1,1,0)<<endl;
    return 0;
}
