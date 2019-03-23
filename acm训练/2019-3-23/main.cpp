#include<cstdio>
#include<algorithm>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=200+10,maxd=10000000+10;
int x[maxn],s[maxd],pri[maxd],r[maxn],a[maxn],b[maxn];
bool bz[maxd],dis[maxn][maxn],pd[maxn];
int i,j,k,l,t,n,m,tot,top,num,sum,tmp,ans;
void prepare(){
    bz[1]=1;
    fo(i,2,maxd-10){
        if (!bz[i]) pri[++top]=i;
        fo(j,1,top){
            if ((ll)i*pri[j]>maxd-10) break;
            bz[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
}
bool dfs(int x){
    int i;
    fo(i,1,sum)
        if (dis[x][i]&&!pd[i]){
            pd[i]=1;
            if (!r[i]||dfs(r[i])){
                r[i]=x;
                return 1;
            }
        }
    return 0;
}
int main(){
    prepare();
    scanf("%d",&n);
    fo(i,1,n){
        scanf("%d",&x[i]);
        s[x[i]]^=1;
    }
    fo(i,1,maxd-9){
        if (s[i]!=s[i-1]){
            if (i%2==1) a[++num]=i;
            else b[++sum]=i;
        }
    }
    fo(i,1,num)
        fo(j,1,sum)
            if (!bz[abs(a[i]-b[j])]) dis[i][j]=1;
    fo(i,1,num){
        fo(j,1,sum) pd[j]=0;
        if (dfs(i)) tmp++;
    }
    ans+=2*((num-tmp)/2);
    ans+=2*((sum-tmp)/2);
    ans+=tmp;
    if (num%2!=tmp%2) ans+=3;
    printf("%d\n",ans);
}
