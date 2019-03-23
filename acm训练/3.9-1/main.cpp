#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=2e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n,p[maxn],q[maxn];
int main(){
	rd(n);
	REP(i,1,n)rd(p[i]),q[i]=p[i];
	sort(p+1,p+n+1);
	int mid=n>>1;
	REP(i,1,n){
		if(q[i]<=p[mid])printf("%d\n",p[mid+1]);
		else if(q[i]>p[mid])printf("%d\n",p[mid]);
	}
}
