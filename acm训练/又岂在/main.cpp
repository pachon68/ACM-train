#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;
const int N=1e5+111;
const ll Inf=9223372036854775807;
struct Edge {
    int u,v,nx;
    ll w;
}g[2*N];
ll d[N];
bool b[N];
int cnt,list[N];
ll h,x,y,z,ans;

void Add(ll u,ll v,ll w) {
    g[++cnt].u=u;g[cnt].v=v;g[cnt].w=w;g[cnt].nx=list[u];list[u]=cnt;
}

void Spfa() {
    queue<int> q;
    while (!q.empty()) q.pop();
    for (int i=0;i<=x;i++) d[i]=Inf;
    q.push(1);d[1]=1;b[1]=1;
    while (!q.empty()) {
        int u=q.front();q.pop();
        for (int i=list[u];i;i=g[i].nx)
        if (d[g[i].v]>d[u]+g[i].w) {
            d[g[i].v]=d[u]+g[i].w;
            if (!b[g[i].v]) q.push(g[i].v);
            b[g[i].v]=1;
        }
        b[u]=0;
    }
}

int main() {
    scanf("%lld",&h);
    scanf("%lld%lld%lld",&x,&y,&z);
    if (y<z) swap(y,z);if (x<y) swap(x,y);
    for (int i=0;i<x;i++) {
        Add(i,(i+y)%x,y);
        Add(i,(i+z)%x,z);
    }
    Spfa();
    for (int i=0;i<x;i++)
        if (h-d[i]>=0) ans+=(h-d[i])/x+1;
    printf("%lld",ans);
}
