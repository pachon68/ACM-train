#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n,m,t,x,y,c,ds[100001],vis[100001];
long long ans;
bool b[100001];
vector<int> to[100001],cost[100001];
queue<int> q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(x==y&&!(t%2)) {printf("-1");return 0;}
		if(t==2)
		  to[x].push_back(y),cost[x].push_back(-1);
		else if(t==3)
		  to[y].push_back(x),cost[y].push_back(0);
		else if(t==4)
		  to[y].push_back(x),cost[y].push_back(-1);
		else if(t==5)
		  to[x].push_back(y),cost[x].push_back(0);
		else
		{
			to[x].push_back(y);cost[x].push_back(0);
			to[y].push_back(x);cost[y].push_back(0);
		}
	}
	std::cout<<ans<<std::endl;
	for(int i=1;i<=n;i++)
	  to[0].push_back(i),cost[0].push_back(0);
	memset(ds,0x7f,sizeof(ds));
	ds[0]=-1;b[0]=1;q.push(0);vis[0]=1;
	while(!q.empty())
	{
		x=q.front();q.pop();b[x]=0;
		for(int i=0;i<to[x].size();i++)
		{
			y=to[x][i];c=cost[x][i];
			if(ds[x]+c<ds[y])
			{
				ds[y]=ds[x]+c;
				if(!b[y])
				{
					if(vis[y]==n) {printf("-1");return 0;}
					vis[y]++;
					b[y]=1;
					q.push(y);
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	  ans-=ds[i];
	printf("%lld",ans);
}
