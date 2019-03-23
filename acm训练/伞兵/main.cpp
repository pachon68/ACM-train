#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
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
struct node{
     int tot,div;
}e[maxn];
int n,v,p[maxn],dp[maxn],cnt;
bool comp(node u,node v){
    return u.tot>v.tot;
}
int main()
{
    int now=0x3f3f3f3f;
    rd(n),rd(v);
    REP(i,1,n){
        int s,t;
        cin>>s>>t;
        e[i].tot=s+t,e[i].div=t-s;
        if(s+t>0)cnt+=e[i].tot;
    }
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0]=0;
    sort(e+1,e+1+n,comp);
    REP(i,1,n){
        for(int j=cnt;j>=e[i].tot;j--){
            if(abs(dp[j-e[i].tot]+e[i].div)<abs(dp[j])){
                dp[j]=dp[j-e[i].tot]+e[i].div;
                if(dp[j]==0&&j>=v){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    REP(i,v,cnt)if(now>abs(dp[i]))now=abs(dp[i]);
    if(now==0x3f3f3f3f)cout<<-1<<endl;
    else cout<<now<<endl;
    return 0;
}
