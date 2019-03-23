#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e6+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
const int mod=998244353;
long long cnt=0;
int a[maxn],b[maxn],n,s,e,tmp[maxn];
void Merge(int a[],int s,int m,int e,int b[]){
    int pb=s;
    int p1=s,p2=m+1;
    while(p1<=m&&p2<=e){
        if(a[p1]<a[p2])
        b[pb++]=a[p1++];
        else{
            b[pb++]=a[p2++];
            cnt=(cnt+m-p1+1)%mod;
        }
    }
    while(p1<=m)
        b[pb++]=a[p1++];
    while(p2<=e)
        b[pb++]=a[p2++];
    for(int i=s;i<=e;i++){
        a[i]=b[i];
    }
}
void msort(int a[],int s,int e,int b[]){
    if(s<e){
        int m=s+(e-s)/2;
        msort(a,s,m,b);
        msort(a,m+1,e,b);
        Merge(a,s,m,e,b);
    }
}
int main(){
    scanf("%d",&n);
    REP(i,0,n-1)a[i]=i+1;
    do{
        REP(i,0,n-1)tmp[i]=a[i];
        memset(b,0,sizeof(b));
        msort(a,0,n-1,b);
        REP(i,0,n-1)a[i]=tmp[i];
    }while(next_permutation(a,a+n));
    cout<<cnt%mod<<endl;
    return 0;
}
