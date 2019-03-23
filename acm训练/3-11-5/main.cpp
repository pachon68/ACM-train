#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define Mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int n,m,S,T;
ll Ans;
int U[200001],V[200001],D[200001];
int h[100001],nxt[400001],to[400001],w[400001],tot;
void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}

ll d1[100001],d2[100001],g1[100001],g2[100001];bool v1[100001],v2[100001];
priority_queue<pli,vector<pli>,greater<pli> > pq;

void Dij(ll*d,ll*g,bool*v,int s){
    d[s]=0ll;
    pq.push(pli(0ll,s));
    g[s]=1;
    while(!pq.empty()){
        pli P=pq.top(); pq.pop();
        int u=P.second; ll du=P.first;
        if(v[u]||d[u]<du) continue;
        v[u]=1;
        eF(i,u){
            if(d[to[i]]==du+w[i])
                g[to[i]]=(g[to[i]]+g[u])%Mod;
            if(d[to[i]]>du+w[i])
                g[to[i]]=g[u],
                d[to[i]]=du+w[i], pq.push(pli(d[to[i]],to[i]));
        }
    }
}

int main(){
    int x,y,z;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&S,&T);
    F(i,1,m) scanf("%d%d%d",&x,&y,&z), ins(x,y,z), ins(y,x,z), U[i]=x, V[i]=y, D[i]=z;
    memset(d1,0x3f,sizeof d1);
    Dij(d1,g1,v1,S);
    memset(d2,0x3f,sizeof d2);
    Dij(d2,g2,v2,T);
    ll Dist=d1[T];
    Ans=g1[T]*g1[T]%Mod;
    F(i,1,n){
        if(d1[i]+d2[i]==Dist&&d1[i]==d2[i])
            Ans=(Ans-g1[i]*g1[i]%Mod*g2[i]%Mod*g2[i]%Mod)%Mod;
    }
    int u,v,d;
    F(i,1,m){
        u=U[i];
        v=V[i];
        d=D[i];
        if(d1[u]+d+d2[v]==Dist && d1[u]+d>d2[v] && d2[v]+d>d1[u]){
            Ans=(Ans-g1[u]*g2[v]%Mod*g1[u]%Mod*g2[v]%Mod)%Mod;
        }
        u=V[i], v=U[i], d=D[i];
        if(d1[u]+d+d2[v]==Dist && d1[u]+d>d2[v] && d2[v]+d>d1[u]){
            Ans=(Ans-g1[u]*g2[v]%Mod*g1[u]%Mod*g2[v]%Mod)%Mod;
        }
    }
    printf("%lld",(Ans%Mod+Mod)%Mod);
    return 0;
}
