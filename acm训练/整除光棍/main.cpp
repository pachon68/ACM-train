#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,cur,p[maxn],tmp,l,r;
int main(){
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
          scanf("%d",&tmp);
          if(!cur||p[cur-1]<tmp)p[cur++]=tmp;
          else{
              l=0,r=cur-1;
              while(l<=r){
                   int mid=l+r>>1;
                   if(p[mid]>tmp)r=mid-1;
                   else l=mid+1;
              }
              p[l]=tmp;
          }
     }
     cout<<cur<<endl;
     return 0;
}
