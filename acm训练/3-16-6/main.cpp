#include <bits/stdc++.h>

using namespace std;
int r1,c1,r2,c2;
int p[1005][1005],q[1005][1005],d[1005][1005];
int main()
{
    cin>>r1>>c1;
    for(int i=1;i<=r1;i++){
        for(int j=1;j<=c1;j++){
             cin>>p[i][j];
        }
    }
    cin>>r2>>c2;
    for(int i=1;i<=r2;i++){
        for(int j=1;j<=c2;j++){
             cin>>q[i][j];
        }
    }
    if(c1!=r2){
        printf("Error: %d != %d\n",c1,r2);
        exit(0);
    }
    for(int i=1;i<=r1;i++){
        for(int j=1;j<=c2;j++){
            for(int k=1;k<=c1;k++){
                d[i][j]+=p[i][k]*q[k][j];
            }
        }
    }
    cout<<r1<<' '<<c2<<endl;
    for(int i=1;i<=r1;i++){
        for(int j=1;j<=c2;j++){
            if(j!=1)cout<<' ';
            cout<<d[i][j];
        }
        cout<<endl;
    }
    return 0;
}
