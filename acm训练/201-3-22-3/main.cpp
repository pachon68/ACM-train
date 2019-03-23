#include <bits/stdc++.h>

using namespace std;
const int maxn=106;
int n,cur,mffour,mftwo,odd,dif;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cur;
        if(!(cur%4))mffour++;
        else if(!(cur%2))mftwo++;
        else odd++;
    }
    dif=mffour-odd;
    if(dif>=0||(dif==-1&&!mftwo))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
