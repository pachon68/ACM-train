#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
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
ll p[16],q[16];
ll tot;
void exgcd(ll a,ll b,ll &x,ll &y){
       if(!b){
            x=1,y=0;
            return;
       }
       exgcd(b,a%b,y,x);
       y-=x*(a/b);
}
int main()
{
    ll ans=0;
    rd(n),tot=1;
    REP(i,1,n)rd(p[i]),rd(q[i]),tot*=p[i];
    REP(i,1,n){
         ll tmp=tot/p[i],x,y;
         exgcd(tmp,p[i],x,y);
         ans=(ans+(x*q[i]*tmp)%tot+tot)%tot;
    }
    printf("%lld",ans);
    return 0;
}
