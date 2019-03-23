#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1005;
const double eps=1e-7;
int n,k;
double mu[maxn],zi[maxn],y[maxn];
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF){
        if(n==0&&k==0)break;
        for(int i=0;i<n;i++)scanf("%lf",&zi[i]);
        for(int i=0;i<n;i++)scanf("%lf",&mu[i]);
        double l=0.0,r=1.0,mid;
        while(r-l>eps){
            double tol=0.0;
            mid=(l+r)*1.0/2.0;
            for(int i=0;i<n;i++)y[i]=zi[i]-mu[i]*mid;
            sort(y,y+n);
            for(int i=k;i<n;i++)tol+=y[i];
            if(tol<0)r=mid;
            else l=mid;
        }
        printf("%.0f\n",mid*100);
    }
    return 0;
}
