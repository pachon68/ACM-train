#include <bits/stdc++.h>

using namespace std;
int n;
string str[100005];
int main()
{
    int i;
    for(i=1;;i++){
         cin>>str[i];
         if(str[i][0]=='.')break;
    }
    if(i<2)cout<<"Momo... No one is for you ...";
    else if(i<14){
            cout<<str[2];
            printf(" is the only one for you...");
    }
    else{
         cout<<str[2];
         printf(" and ");
         cout<<str[14];
         printf(" are inviting you to dinner...");
    }
    return 0;
}
