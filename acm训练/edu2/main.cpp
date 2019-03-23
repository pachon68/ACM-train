#include <bits/stdc++.h>

using namespace std;
const int maxn=2e6+10;
typedef long long ll;
int x1,y1,x2,y2,x[maxn],y[maxn],n;
string str;
int main()
{
     cin>>x1>>y1>>x2>>y2>>n;
     cin>>str;
     str.insert(str.begin(),'t');
     for(int i=1;i<str.size();i++){
          if(str[i]=='U'){
              x[i]=x[i-1],y[i]=y[i-1]+1;
          }
          else if(str[i]=='D'){
              x[i]=x[i-1],y[i]=y[i-1]-1;
          }
          else if(str[i]=='L'){
              x[i]=x[i-1]-1,y[i]=y[i-1];
          }
          else{
              x[i]=x[i-1]+1,y[i]=y[i-1];
          }
     }
     ll l=0,r=1e15;
     ll sx=x2-x1,sy=y2-y1;
     while(l<r){
           ll mid=(l+r)/2;
           ll disx=x[n]*mid/n+x[mid%n],disy=y[n]*mid/n+y[mid%n];
           if(abs(disx-sx)+abs(disy-sy)<=mid)r=mid;
           else l=mid+1;
     }
     if(r==1e15)cout<<-1<<endl;
     else cout<<l<<endl;
     return 0;
}
