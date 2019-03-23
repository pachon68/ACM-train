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
int vis[maxn],tmp,p[maxn];
bool check(int cur){
      while(cur){
          if(vis[cur%10]){
              return false;
          }
          cur/=10;
      }
      return true;
}
int main(){
     int n,k;
     rd(n),rd(k);
     REP(i,1,k)rd(tmp),vis[tmp]=1;
     for(int i=n;;i++){
         if(check(i)){
             cout<<i<<endl;
             exit(0);
         }
     }
}
