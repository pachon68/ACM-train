#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+6;
int vis[maxn],n,k,tmp,tot,p[maxn],fa[maxn];
char c;
int fd(int o){
     return o==fa[o]?o:fa[o]=fd(fa[o]);
}
void mg(int a,int b){
     int u=fd(a),v=fd(b);
     if(u!=v)fa[u]=v;
}
bool comp(int a,int b){return a>b;}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        cin>>k>>c;
        for(int j=1;j<=k;j++){
            cin>>tmp;
            if(vis[tmp])mg(vis[tmp],i);
            else vis[tmp]=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==fa[i])tot++;
        p[fd(i)]++;
    }
    sort(p+1,p+1+n,comp);
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++){
        if(i!=1)cout<<' ';
        cout<<p[i];
    }
    return 0;
}
