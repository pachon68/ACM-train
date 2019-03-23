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
int h,w,n,cnt[16],mt[100][100];
int main()
{
    rd(h),rd(w),rd(n);
    REP(i,1,n){
        int x,y;
        mt[x][y]++;
    }
    for(int i=1;i<=10;i++){
        if(mt[i][i]){
            cout<<mt[i][i]<<endl;
        }
    }
    return 0;
}
