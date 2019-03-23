#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e6+6;
int T,n,m;
ll inv[maxn<<1],fac[maxn<<1],dif[maxn<<1];
ll fast_pow(ll a,ll b){
      ll ans=1;
      while(b){
          if(b&1)ans=(ans%mod*a%mod)%mod;
          a=a*a%mod;
          b>>=1;
      }
      return ans;
}
ll prepare(){
       fac[0]=inv[0]=1;
       for(int i=1;i<=maxn;i++)fac[i]=(fac[i-1]%mod*i)%mod,inv[i]=fast_pow(fac[i],mod-2);
       dif[1]=0,dif[2]=dif[0]=1;
       for(int i=3;i<=maxn;i++)dif[i]=(i-1)*(dif[i-1]+dif[i-2])%mod;
}
int main()
{
    scanf("%d",&T);
    prepare();
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%lld\n",fac[n]%mod*inv[m]%mod*inv[n-m]%mod*dif[n-m]%mod);
    }
    return 0;
}
