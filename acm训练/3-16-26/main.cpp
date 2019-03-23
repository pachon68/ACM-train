#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
      long long x,y;
}p[5666],q[5666];
int n;
bool cmp(node a,node b){
     return a.x*b.y-a.y*b.x>0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    sort(p+1,p+1+n,cmp);
    long long minn=1e18;
    q[1].x=p[1].x-p[n].x;
    q[1].y=p[1].y-p[n].y;
    for(int i=2;i<=n;i++){
        q[i].x=p[i].x-p[i-1].x;
        q[i].y=p[i].y-p[i-1].y;
    }
    for(int i=2;i<=n;i++)minn=min(minn,abs(q[i].x*q[i-1].y-q[i].y*q[i-1].x));
    printf("%.3f",(double)minn/2.0);
    return 0;
}
