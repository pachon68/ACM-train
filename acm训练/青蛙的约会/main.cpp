#include <iostream>

using namespace std;
typedef long long ll;
int exgcd(ll a,ll b,ll &x,ll &y){
   if(!b){
       x=1,y=0;
       return a;
   }
   ll r=exgcd(b,a%b,x,y);
   int tmp=x;
   x=y,y=tmp-a/b*y;
   return r;
}
int main()
{
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    ll k=n-m,q=x-y;
    if(k<0)k=-k,q=-q;
    ll h,j;
    ll gcd=exgcd(k,l,h,j);
    if(q%gcd!=0){
        cout<<"Impossible"<<endl;
    }
    else{
        int e=l/gcd;
        cout<<(h*q/gcd%e+e)%e<<endl;
    }
    return 0;
}
