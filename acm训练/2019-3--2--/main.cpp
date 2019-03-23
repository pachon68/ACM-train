#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,m;
ll p[maxn],q[maxn],s[maxn],t[maxn];
ll tot;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>q[i];
    int e=n;
    for(int i=1;i<=n;i++){
        while(p[i]+q[e]>m&&e>=1)e--;
        if(!e)break;
        tot=max(tot,p[i]+q[e]);
    }
    cout<<tot<<endl;
    return 0;
}
