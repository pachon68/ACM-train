#include <bits/stdc++.h>

using namespace std;
int n;
double tmp;
char now;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        getchar();
        scanf("%c",&now);
        cin>>tmp;
        //printf("%.3f\n",tmp);
        if(now=='F'){
            printf("%.2f\n",1.09*tmp);
        }
        else{
            printf("%.2f\n",(double)tmp/1.09);
        }
    }
    return 0;
}
