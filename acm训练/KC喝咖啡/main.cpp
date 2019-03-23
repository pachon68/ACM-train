#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
struct node{
    int v,c;
    double val;
}p[maxn];
int n,m;
double l,r,mid;
bool comp(node a,node b){
          return a.val>b.val;
}
bool ok(double cur){
    double tot=0.0;
    REP(i,1,n)p[i].val=p[i].v-cur*(double)p[i].c;
    sort(p+1,p+1+n,comp);
    REP(i,1,m){
       tot+=p[i].val;
    }
    if(tot>=0)return true;
    else return false;
}
int main()
{
    rd(n),rd(m);
    REP(i,1,n)rd(p[i].v);
    REP(i,1,n){
        rd(p[i].c);
        r=max(r,p[i].v*1.0/(double)p[i].c);
    }
    while(r-l>1e-6){
        mid=(l+r)/2.0;
        if(ok(mid))l=mid;
        else r=mid;
    }
    printf("%.3f",l);
    return 0;
}
