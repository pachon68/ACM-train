#include <bits/stdc++.h>

using namespace std;
int y,n,tot;
bool vis[16];
bool check(int cur){
    int now=0;
    memset(vis,0,sizeof(vis));
    while(cur){
        if(!vis[cur%10])now++,vis[cur%10]=1;
        cur/=10;
    }
    return now==n;
}
int main()
{
    cin>>y>>n;
    while(!check(y))y++,tot++;
    cout<<tot<<' ';
    printf("%4d",y);
    return 0;
}
