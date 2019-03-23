#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
const int maxn=105;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
char str[maxn];
int len;
ll ans;
void dfs(ll tot,int pos){
     if(pos==len+1){
        ans+=tot;
        return;
     }
     REP(i,pos,len){
          ll rt=0;
          REP(j,pos,i)rt=rt*10+str[j]-'0';
          dfs(tot+rt,i+1);
     }
}
int main()
{
    scanf("%s",str+1);
    len=strlen(str+1);
    dfs(0,1);
    cout<<ans<<endl;
}
