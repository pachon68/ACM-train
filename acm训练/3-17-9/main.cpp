#include <bits/stdc++.h>

using namespace std;
int n,tot;
string winner;
double cur=0x3f3f3f3f;
int main()
{
    cin>>n;
    map<string,int>p;
    for(int i=1;i<=n;i++){
        string tmp;
        int cur;
        cin>>tmp>>cur;
        p[tmp]=cur;
        tot+=cur;
    }
    double ave=(double)tot/(1.0*n*2.0);
    map<string,int>::iterator it=p.begin();
    for(;it!=p.end();it++){
        if(abs(it->second-ave)<cur){
            cur=abs(it->second-ave);
            winner=it->first;
        }
    }
    printf("%.0f ",ave);
    cout<<winner<<endl;
    return 0;
}
