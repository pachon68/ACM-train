#include <bits/stdc++.h>

using namespace std;
const int maxn=106;
int n,cur,now;
string tmp;
struct node{
     string name;
     double ave;
     int total;
};
set<int>s[maxn];
vector<node>G;
bool cmp(node s,node t){
     if(s.total!=t.total)return s.total>t.total;
     else return s.ave<t.ave;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
          cin>>tmp>>cur;
          for(int j=1;j<=cur;j++){
              cin>>now;
              s[i].insert(now);
          }
          G.push_back(node{tmp,(double)cur/(double)s[i].size(),s[i].size()});
    }
    sort(G.begin(),G.end(),cmp);
    for(int i=0;i<3;i++){
         if(i)cout<<' ';
         if(i<G.size())cout<<G[i].name;
         else cout<<'-';
    }
    return 0;
}
