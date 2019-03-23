#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn=1e5+5;
template <class T>
inline void rd(T &ret){
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9'){
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
char str[30];
char now[maxn];
char ch;
map<char,char>p;
int main()
{
    gets(str);
    for(char i='A';i<='Z';i++){
        scanf("%c",&ch);
        p[i]=ch;
    }
    for(int i=0;i<strlen(str);i++){
        if(str[i]==' ')printf(" ");
        else printf("%c",p[str[i]]);
    }
    return 0;
}
