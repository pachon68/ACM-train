#include<bits/stdc++.h>
using namespace std;

int ti[1005],p[1005];
int main()
{
    int day,n=0,pos,th,tm;
    int E=0,T=0;
    char s[2];
    scanf("%d",&day);
    while(scanf("%d%s%d:%d",&pos,s,&th,&tm)!=EOF){
        if(pos==0)
        {
            n++;
            printf("%d %.0f\n",E,E==0?E:T*1./E);
            E=0,T=0;
            memset(p,0,sizeof p);
            continue;
        }
        if(day==n)break;
        if(s[0]=='S')ti[pos]=th*60+tm,p[pos]=1;
        else if(s[0]=='E'&&p[pos])p[pos]=0,E++,T+=th*60+tm-ti[pos];
    }
}
