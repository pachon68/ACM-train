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
int n,p[maxn],fi=-1;
double dis;
int main()
{
     rd(n);
     REP(i,1,n){
        rd(p[i]);
        fi=max(fi,p[i]);
     }
     REP(i,1,n){
        if(abs(p[i]-fi)/(double)2.0)
     }
}
