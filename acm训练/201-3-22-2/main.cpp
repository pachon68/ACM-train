#include <bits/stdc++.h>

using namespace std;
const int maxn=6e6+5;
typedef long long ll;
ll p[maxn];
int n,tot,cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
    for(int i=1;i<=n;i++){
        cnt=0;
        while(p[i]){
            if(cnt>1)break;
            if(p[i]&1)cnt++;
            p[i]>>=1;
        }
        if(cnt==1)tot++;
    }
    printf("%d",tot);
    return 0;
}
