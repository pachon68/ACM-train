#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
pair<int,int>p[maxn];
pair<int,int>q[maxn];
int n,increase=1,cnt,pre=0x3f3f3f3f,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].first;
        q[i].second=i;
    }
    sort(q+1,q+1+n);
    for(int i=1;i<=n;i++){
        if(i==1||q[i].first!=q[i-1].first){
            p[cnt].second=q[i-1].second;
            p[++cnt].first=q[i].second;
        }
    }
    p[cnt].second=q[n].second;
    for(int i=1;i<=cnt;i++){
        if(increase){
            if(pre<p[i].first)pre=p[i].second;
            else pre=p[i].first,ans++,increase=0;
        }
        else{
            if(pre>p[i].second)pre=p[i].first;
            else pre=p[i].second,increase=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
