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
int h,w,ans;
char str[3005][3005];
int main()
{
    rd(h),rd(w);
    REP(i,1,h)scanf("%s",str[i]+1);
    REP(i,1,h){
       REP(j,1,w){
         // printf("%c",str[i][j]);
          if(str[i][j]=='J'){
              int s=0,t=0;
              for(int k=j+1;k<=w;k++){
                   if(str[i][k]=='O')s++;
              }
              for(int k=i+1;k<=h;k++){
                 if(str[k][j]=='I')t++;
              }
              ans+=s*t;
          }
       }
      // cout<<endl;
    }
    printf("%d",ans);
    return 0;
}
