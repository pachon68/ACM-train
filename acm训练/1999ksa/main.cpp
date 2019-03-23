#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=106;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int n,m,row[maxn],colunm[maxn];
char str[maxn][maxn];
int main()
{
    rd(n),rd(m);
    REP(i,1,n)scanf("%s",str[i]+1);
    REP(i,1,n){
       int now=0;
       REP(j,1,m){
          if(str[i][j]=='.')now++;
       }
       if(now==m)row[i]=1;
    }
    REP(i,1,m){
       int now=0;
       REP(j,1,n){
           if(str[j][i]=='.')now++;
       }
       if(now==n)colunm[i]=1;
    }
    REP(i,1,n){
       bool cur=false;
       REP(j,1,m){
          if(row[i]||colunm[j])continue;
          cur=true;
          printf("%c",str[i][j]);
       }
       if(cur)cout<<endl;
    }
    return 0;
}
