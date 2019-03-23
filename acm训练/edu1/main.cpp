#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4+6;
int n,p[maxn],cnt;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++,cnt++){
          int dis=p[i];
          while(i<dis){
              i++;
              dis=max(dis,p[i]);
          }
    }
    cout<<cnt<<endl;
    return 0;
}
