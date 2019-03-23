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
int n,p[10],tmp[10],ans;
void dfs(int fi,int sc){
       if(tmp[fi]>p[fi])return;
    //   if(tmp[fi]+3*(n-sc+1)<p[fi])return;
       if(fi==n+1){
            if(p[fi]==tmp[fi])ans++;
            return;
       }
       if(sc==n+1){
           if(tmp[fi]==p[fi]){
                dfs(fi+1,fi+2);
           }
           else return;
       }
       else{
           if(p[fi]-tmp[fi]>=3){
              tmp[fi]+=3;
              dfs(fi,sc+1);
              tmp[fi]-=3;
           }
           tmp[sc]+=3;
           dfs(fi,sc+1);
           tmp[sc]-=3;
           if(p[fi]-tmp[fi]>=1){
              tmp[fi]++,tmp[sc]++;
              dfs(fi,sc+1);
              tmp[fi]--,tmp[sc]--;
           }
       }
       return;
}
int main()
{
    scanf("%d",&n);
    REP(i,1,n)scanf("%d",&p[i]);
    dfs(1,2);
    printf("%d",ans);
    return 0;
}
