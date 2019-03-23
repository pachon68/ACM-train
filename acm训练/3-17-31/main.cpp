#include <cstdio>
#include <queue>
#include <algorithm>
#include<bits/stdc++.h>
#define Ls k<<1
#define Rs k<<1|1
#define mid ((l+r)>>1)
#define LL long long
using namespace std;
const int N=1e6+5;
int n,t[N];LL f[N],ax[N*4],ans;
struct O{
	int x;
	friend bool operator < (const O& A,const O& B){
		return A.x+t[A.x]>B.x+t[B.x];
	}
};
priority_queue<O>q;
void update(int k,int l,int r,int x,LL v){
	if (l==r){
            ax[k]=v;
            cout<<ax[k]<<endl;
            return;
    }
	if (mid>=x) update(Ls,l,mid,x,v);
	else update(Rs,mid+1,r,x,v);
	ax[k]=max(ax[Ls],ax[Rs]);
}
LL query(int k,int l,int r,int L,int R){
	if (L>R) return 0;
	if (L<=l && r<=R) return ax[k];
	if (mid<L) return query(Rs,mid+1,r,L,R);
	if (mid>=R) return query(Ls,l,mid,L,R);
	return max(query(Ls,l,mid,L,R),query(Rs,mid+1,r,L,R));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	for (int i=1;i<=n;i++){
		LL x;scanf("%lld",&x);f[i]=x*t[i];
		while(!q.empty()){
			O k=q.top();if (k.x+t[k.x]>i) break;
			q.pop();update(1,1,n,k.x,f[k.x]);
		}
		cout<<"******"<<endl;
		f[i]+=query(1,1,n,1,i-t[i]);
		ans=max(ans,f[i]);q.push((O){i});
	}
	printf("%lld\n",ans);
	return 0;
}
