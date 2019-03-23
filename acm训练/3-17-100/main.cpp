#include <iostream>

using namespace std;
int x,y;
int main()
{
    int a,b;
    cin>>a>>b;
    int u,v,w;
    cin>>u>>v>>w;
    if(u)x++;
    if(v)x++;
    if(w)x++;
    y=3-x;
    if(u&&v&&w)printf("The winner is b: %d + 3",b);
    else if(!u&&!v&&!w)printf("The winner is a: %d + 3",a);
    else if((u||v||w)&&a>b)printf("The winner is a: %d + %d",a,y);
    else printf("The winner is b: %d + %d",b,x);
    return 0;
}
