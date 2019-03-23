#include <bits/stdc++.h>

using namespace std;
const int maxn=106;
struct node{
     int tot;
     vector<int>G;
}p[maxn];
int n,tmp,cnt,cur=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        cnt+=tmp*10,p[i].tot=tmp*10;
    }
    while(cnt--){
        for(int i=1;i<=n;i++){
            if(p[i].G.size()!=p[i].tot){
                if(p[i].G.empty()==false&&p[i].G.back()+1==cur){
                    p[i].G.push_back(cur+1);
                    cur+=2;
                }
                else{
                    p[i].G.push_back(cur);
                    cur++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<'#'<<i<<endl;
        for(int j=0;j<p[i].G.size();j++){
            if(!(j%10)&&j!=0){
                cout<<endl;
            }
            if(j%10!=0)cout<<' ';
            cout<<p[i].G[j];
        }
        cout<<endl;
    }
    return 0;
}
