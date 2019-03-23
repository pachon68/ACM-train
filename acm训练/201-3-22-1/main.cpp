#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,p[maxn],q[maxn];
ll minn;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++)cin>>q[i];
    sort(p+1,p+1+n);
    sort(q+1,q+1+m);
    int i=1,j=1;
    while(i<=n&&j<=m){
        if(p[i]<=q[j])minn+=q[j],i++,j++;
        else j++;
    }
    if(i<n)cout<<-1<<endl;
    else cout<<minn<<endl;
    return 0;
}
