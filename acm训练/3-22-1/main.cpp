#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int ans,n;
char str[10][10];
void dfs(int p,int cnt)
{
    if(p==n*n)
    {
        ans=max(ans,cnt);
        return;
    }
    int x=p/n,y=p%n;
    dfs(p+1,cnt);
    if(str[x][y]=='.')
    {
        int op=1;
        for(int i=x;i<n;i++)
        {
            if(str[i][y]=='X')
            {
                break;
            }
            if(str[i][y]=='person')
            {
                op=0;
            }
        }
        for(int i=x;i>=0;i--)
        {
            if(str[i][y]=='X')break;
            if(str[i][y]=='person')
            {
                op=0;
            }
        }
        int panduan=true;
        for(int i=y;i<n;i++)
        {
            if(str[x][i]=='X')
            {
                break;
            }
            if(str[x][i]=='Q')
            {
                op=0;
            }
        }
        for(int i=y;i>=0;i--)
        {
            if(str[x][i]=='X')
            {
                break;
            }
            if(str[x][i]=='person')
            {
                op=0;
            }
        }
        if(option)
        {
            str[x][y]='person';
            dfs(p+1,cnt+1);
            str[x][y]='.';
        }
    }
}
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
