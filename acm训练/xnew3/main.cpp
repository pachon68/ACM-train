#include<bits/stdc++.h>
#define REP(i, a, b) for(long long i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e6+5;
const long long mod=1e9+7;
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
long long fac[maxn],inc[maxn],h,w,a,b,tot,leave;
long long fast_pow(long long cur,long long mi){
     long long ans=1;
     while(mi){
         if(mi&1)ans=(ans*cur)%mod;
         cur=(cur*cur)%mod;
         mi>>=1;
     }
     return ans;
}
long long C(long long m,long long n){
     return (fac[m]*inc[m-n])%mod*inc[n]%mod;
}
long long cal(long long u,long long v,long long s,long long t){
     long long m=s-u+t-v;
     long long n=s-u;
     return C(m,n);
}
int main()
{
    fac[0]=1;
    inc[0]=fast_pow(fac[0],mod-2);
    REP(i,1,maxn)fac[i]=i*fac[i-1]%mod,inc[i]=fast_pow(fac[i],mod-2);
 //   for(int i=1;i<=100;i++)cout<<fac[i]<<' '<<inc[i]<<endl;
    rd(h),rd(w),rd(a),rd(b);
    tot=cal(1,1,h,w);
    REP(i,1,b){
         leave=cal(1,1,h-a,i)*cal(h-a+1,i,h,w)%mod;
         if(tot<leave)tot+=mod;
         tot=(tot-leave)%mod;
    }
    cout<<tot<<endl;
}
