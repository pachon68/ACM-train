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
int magic[M_max+5];
int T_num,M_num,ans[M_max+5][4],F[T_max+5];
int main()
{
    scanf("%d%d",&M_num,&T_num);
    for(int i=1;i<=T_num;i++) F[i]=read(),magic[F[i]]++;
    for(int i=1;i<=M_num/9;i++)
    {
        for(int d=i*9+2,sum=0;d<=M_num;d++)
        {
            int c=d-i,b=d-7*i-1,a=d-9*i-1;
            sum+=magic[a]*magic[b];
            ans[c][2]+=magic[d]*sum;
            ans[d][3]+=magic[c]*sum;
        }
        for(int a=M_num-i*9-1,sum=0;a>=1;a--)
        {
            int b=a+2*i,c=a+8*i+1,d=a+9*i+1;
            sum+=magic[c]*magic[d];
            ans[a][0]+=magic[b]*sum;
            ans[b][1]+=magic[a]*sum;
        }
    }
    for(int i=1;i<=T_num;i++)
        printf("%d %d %d %d\n",ans[F[i]][0],ans[F[i]][1],ans[F[i]][2],ans[F[i]][3]);
    return 0;
}
