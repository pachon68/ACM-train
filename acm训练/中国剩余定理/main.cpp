#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[15],b[15],k,lcm;
int qmul(int a,int b,int mod){
   int ans=0;
   while(b>0){
    if(b&1)ans=(ans+a)%mod;
    a=(a+a)%mod;
    b>>=1;
   }
   return ans%mod;
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return ;}
    else{
       exgcd(b,a%b,x,y);
       int tp=x;
       x=y;
       y=tp-a/b*y;
    }
}
int china(){
    ll ans=0,x,y;
    for(int i=0;i<k;i++)lcm*=b[i];
    for(int i=0;i<k;i++){
        ll tp=lcm/b[i];
        exgcd(tp,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+qmul(qmul(tp,x,lcm),a[i],lcm)+lcm)%lcm;
    }
    if(ans<0)ans+=lcm;
    return ans;
}
int main()
{
    scanf("%lld",&k);
    lcm=1;
    for(int i=0;i<k;i++)scanf("%lld",&a[i]);
    for(int i=0;i<k;i++)scanf("%lld",&b[i]);
    cout<<china()%lcm;
    return 0;
}
