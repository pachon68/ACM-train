#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+6;
int n,g,k,tp,tot,rk[maxn];
struct node{
     string str;
     int score;
};
string tmp;

bool cmp(node a,node b){
    if(a.score!=b.score)return a.score>b.score;
    else return a.str<b.str;
}
int main()
{
    cin>>n>>g>>k;
    vector<node>G(n);
    for(int i=0;i<n;i++){
        cin>>tmp>>tp;
        G[i]={tmp,tp};
        if(tp>=60)tot+=20;
        if(tp>=g)tot+=30;
    }
    rk[0]=1;
    sort(G.begin(),G.end(),cmp);
    for(int i=1;i<n;i++){
        if(G[i].score==G[i-1].score)rk[i]=rk[i-1];
        else rk[i]=i+1;
    }
    cout<<tot<<endl;
    for(int i=0;i<n&&rk[i]<=k;i++){
        printf("%d %s %d\n",rk[i],G[i].str.c_str(),G[i].score);
    }
    return 0;
}
