# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <bitset>
# include <set>
# include <cmath>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-8
# define MOD 1000000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FDR(i,a,n) for(int i=a; i>=n; --i)
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
inline int Scan() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
const int N=200005;
//Code begin....

struct qnode{
   int l, r, vl, vr;
   qnode(int _l=0, int _r=0, int _vl=0, int _vr=0):l(_l),r(_r),vl(_vl),vr(_vr){}
   bool operator<(const qnode &m)const{return vl>m.vl;}
};
priority_queue<qnode>que;
struct Seg{int odd, even;}seg[N<<3];
int a[N], id[N];
VI ans;

void push_up(int p){
    seg[p].even=min(seg[p<<1].even, seg[p<<1|1].even);
    seg[p].odd=min(seg[p<<1].odd, seg[p<<1|1].odd);
}
void init(int p, int l, int r){
    if (l<r) {
        int mid=(l+r)>>1;
        init(lch); init(rch); push_up(p);
    }
    else {
        if (l&1) seg[p].even=a[l], seg[p].odd=INF;
        else seg[p].odd=a[l], seg[p].even=INF;
    }
}
int query(int p, int l, int r, int L, int R, int flag){
    if (L>r||R<l) return INF;
    if (L<=l&&R>=r) return flag?seg[p].even:seg[p].odd;
    else {
        int mid=(l+r)>>1;
        return min(query(lch,L,R,flag),query(rch,L,R,flag));
    }
}
int main ()
{
    int n, x, y, l, r, ll;
    qnode tmp;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i), id[a[i]]=i;
    init(1,1,n);
    x=query(1,1,n,1,n,1); l=id[x]; y=query(1,1,n,l+1,n,0);
    que.push(qnode(1,n,x,y));
    FOR(i,1,n/2) {
        tmp=que.top(); que.pop();
        ans.pb(tmp.vl); ans.pb(tmp.vr);
        l=id[tmp.vl]; r=id[tmp.vr];
        if (tmp.l<l-1) {
            x=query(1,1,n,tmp.l,l-1,tmp.l&1); ll=id[x]; y=query(1,1,n,ll+1,l-1,(l-1)&1);
            que.push(qnode(tmp.l,l-1,x,y));
        }
        if (l+1<r-1) {
            x=query(1,1,n,l+1,r-1,(l+1)&1); ll=id[x]; y=query(1,1,n,ll+1,r-1,(r-1)&1);
            que.push(qnode(l+1,r-1,x,y));
        }
        if (r+1<tmp.r) {
            x=query(1,1,n,r+1,tmp.r,(r+1)&1); ll=id[x]; y=query(1,1,n,ll+1,tmp.r,tmp.r&1);
            que.push(qnode(r+1,tmp.r,x,y));
        }
    }
    for (int i=0; i<ans.size(); ++i) printf(i==0?"%d":" %d",ans[i]);
    putchar('\n');
    return 0;
}
