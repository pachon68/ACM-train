#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+6;
int n;
ll d[maxn],ans;
map<ll,int>p;
int main()
{
    cin>>n;
    p[0]++;
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++){
        d[i]=d[i]+d[i-1];
        ans+=p[d[i]];
        p[d[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}
