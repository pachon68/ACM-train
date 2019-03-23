#include<bits/stdc++.h>
using namespace std;
int w,p;
double ans;
int main()
{
    cin>>w>>p;
    double init=2*1000*100/(double)w;
    while(init>1e-6){
        ans+=init/9.8;
        init=init*(100-p)/100.0;
    }
    printf("%.3f",ans);
    return 0;
}
