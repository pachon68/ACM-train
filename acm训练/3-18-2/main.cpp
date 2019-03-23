#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=6;
const ll mod=123456789;
struct matrix{
      ll q[maxn][maxn];
      matrix(){
          memset(q,0,sizeof(q));
      }
      void init(){
          for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)q[i][j]=(i==j);
      }
      matrix operator+(const matrix &x)const{
           matrix s;
           for(int i=0;i<6;i++){
               for(int j=0;j<6;j++){
                   s.q[i][j]=(q[i][j]+x.q[i][j])%mod;
               }
           }
           return s;
      }
      matrix operator*(const matrix &x)const{
           matrix s;
           for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                    for(int k=0;k<6;k++){
                        s.q[i][j]=(s.q[i][j]+(q[i][k]*x.q[k][j])%mod)%mod;
                    }
                }
           }
           return s;
      }
      matrix operator^(const ll &x)const{
           matrix dis,now=(*this);
           dis.init();
           ll cur=x;
           while(cur){
               if(cur&1)dis=dis*now;
               now=now*now;
               cur>>=1;
           }
           return dis;
      }
};
int T;
ll n;
matrix t,s,v;
int main()
{
    cin>>T;
    t.q[0][0]=1,t.q[0][1]=2,t.q[0][2]=1,t.q[0][3]=0,t.q[0][4]=0,t.q[0][5]=0;
    t.q[1][0]=1,t.q[1][1]=0,t.q[1][2]=0,t.q[1][3]=0,t.q[1][4]=0,t.q[1][5]=0;
    t.q[2][0]=0,t.q[2][1]=0,t.q[2][2]=1,t.q[2][3]=3,t.q[2][4]=3,t.q[2][5]=1;
    t.q[3][0]=0,t.q[3][1]=0,t.q[3][2]=0,t.q[3][3]=1,t.q[3][4]=2,t.q[3][5]=1;
    t.q[4][0]=0,t.q[4][1]=0,t.q[4][2]=0,t.q[4][3]=0,t.q[4][4]=1,t.q[4][5]=1;
    t.q[5][0]=0,t.q[5][1]=0,t.q[5][2]=0,t.q[5][3]=0,t.q[5][4]=0,t.q[5][5]=1;
    v.q[0][0]=2,v.q[1][0]=1,v.q[2][0]=27,v.q[3][0]=9,v.q[4][0]=3,v.q[5][0]=1;
    while(T--){
         cin>>n;
         if(n==1){
              cout<<1<<endl;
              continue;
         }
         if(n==2){
               cout<<2<<endl;
               continue;
         }
         s=t^(n-2);
         s=s*v;
         cout<<s.q[0][0]%mod<<endl;
    }
    return 0;
}
