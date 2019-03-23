#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
struct node{
    int s,t,val;
}p[maxn];
vector<node>f;
int l,r,fi,n,total;
int main()
{
    scanf("%d",&fi);
    cin>>n;
    for(int i=1;i<=n;i++){
        int q,w,e;
        cin>>q>>w>>e;
        p[q]={q,e,w};
    }
    while(true){
        f.push_back(p[fi]);
        fi=p[fi].t,total++;
        if(fi==-1)break;
    }
    r=total-1;
    while(l<=r){
         printf("%05d %d %05d\n",f[r].s,f[r].val,f[l].s);
         printf("%05d %d ",f[l].s,f[l].val);
         l++,r--;
         if(l==r){
             printf("%05d\n%05d %d -1",f[r].s,f[r].s,f[r].val);
             break;
         }
         else{
             if(l<total/2)printf("%05d\n",f[r].s);
             else{
                    printf("-1\n");
                    break;
             }
         }
    }
    return 0;
}
