#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 1e6+55;
#define LL long long
string s;
int k;
int num=0;
void dfs(string ss)
{
	for(char i='a';i<='z';i++){
		string sss=ss+i;
		if(num==k){
			return;
		}
		if(s.find(sss)==string::npos){

		}
		else{
			num++;
			if(num==k){
				cout<<sss<<endl;
				return;
			}
			dfs(sss);
		}
	}
}

int main()
{
	cin>>s;
	cin>>k;
	string ss="";
	dfs(ss);

	return 0;
}
