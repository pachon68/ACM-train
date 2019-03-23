#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,ans;
int main()
{
    cin>>n>>k;
    ans=n*k;
    for(int l=1,r=0;l<=n;l=r+1){
        if(k/l)r=min(n,k/(k/l));
        else r=n;
        ans-=(k/l)*(r-l+1)*(l+r)/2;
    }
    cout<<ans<<endl;
    return 0;
}
