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
int a,b,c,d,val,dis;
int gt(int cur){
    a=cur/1000;
    b=(cur/100)%10;
    c=(cur/10)%10;
    d=cur%10;
}
queue<int>q;
int rt;
#define LEN_MAX 3
#define LenMax 6
#if LEN_MAX==3
#define ui
#endif // LEN_MAX
extern inline void Debug(T tar){
      cerr << tar << endl;
}
void bfs(){

}
int main()
{
    int T;
    rd(T);
    while(T--){
        #ifndef ui
        cout<<T<<end;
        #endif // ui
        rd(val),rd(dis);
        cout<<bfs()<<endl;
    }
    return 0;
}
