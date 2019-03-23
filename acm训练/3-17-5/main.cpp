#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
vector<int>G[maxn];
vector<double>u(1005),v(1005);
int k,cnt[maxn];
string now;
int a,b;
double amaxn,bmaxn;
stringstream st;
bool q[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>k;
        G[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>now;
            bool flag=true;
            int cur;
            if(now[0]=='-')flag=false,now=now.substr(1);
            st.clear();
            st.str("");
            st<<now;
            st>>cur;
            q[cur]=flag;
            G[i][j]=cur;
        }
    }
    st.clear();
    st.str("");
    cin>>now;
    if(now[0]=='-')now=now.substr(1);
    st<<now;
    st>>a;
    cin>>now;
    st.clear();
    st.str("");
    if(now[0]=='-')now=now.substr(1);
    st<<now;
    st>>b;
    for(int i=1;i<=m;i++){
        bool s=find(G[i].begin(),G[i].end(),a)!=G[i].end();
        bool t=find(G[i].begin(),G[i].end(),b)!=G[i].end();
        double cur=1.0/G[i].size();
        if(s||t){
            for(int j=0;j<G[i].size();j++){
                if(s&&q[a]!=q[G[i][j]]){
                     u[G[i][j]]+=cur;
                     amaxn=max(amaxn,u[G[i][j]]);
                }
                if(t&&q[b]!=q[G[i][j]]){
                    v[G[i][j]]+=cur;
                    bmaxn=max(bmaxn,v[G[i][j]]);
                }
            }
        }
    }
    if(amaxn==u[b]&&bmaxn==v[a]){
        printf("%s%d %s%d\n",q[a]==false?"-":"",a,q[b]==false?"-":"",b);
    }
    else{
        for(int i=0;i<n;i++){
             if(amaxn==u[i])printf("%s%d %s%d\n",q[a]==false?"-":"",a,q[i]==false?"-":"",i);
        }
        for(int i=0;i<n;i++){
             if(bmaxn==v[i])printf("%s%d %s%d\n",q[b]==false?"-":"",b,q[i]==false?"-":"",i);
        }
    }
    return 0;
}
