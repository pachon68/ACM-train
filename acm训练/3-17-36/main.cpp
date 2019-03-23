#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int maxn = 1e6 + 5;
template <class T>
inline void rd(T &ret) {
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0' && c <= '9') {
		ret = ret * 10 + (c - '0'), c = getchar();
	}
}
typedef long long ll;
int t[maxn];
ll ans, dp[maxn], cur, p[maxn*4];
struct node {
	int now;
	bool operator<(const node &tmp)const {
		return now + t[now] > tmp.now + t[tmp.now];
	}
};
priority_queue<node>q;
void update(int root, int l, int r, int cur, ll val) {
	    if (l == r) {
			p[root] = val;
			//cout<<p[root]<<endl;
			return;
		}
		int mid = l + r >> 1;
		if (cur <= mid)update(root << 1, l, mid, cur, val);
		else update(root << 1 | 1, mid + 1, r, cur, val);
		p[root] = max(p[root << 1], p[root << 1 | 1]);
		return;
}
long long query(int root, int l, int r, int ql, int qr) {
	    if (ql > qr)return 0;
		if (ql <= l && qr >= r)return p[root];
		int mid = l + r >> 1;
		if (mid < ql)return query(root << 1 | 1, mid + 1, r, ql, qr);
		if (mid >= qr)return query(root << 1, l, mid, ql, qr);
		return max(query(root<<1,l,mid,ql,qr),query(root<<1|1,mid+1,r,ql,qr));
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> t[i];
	for (int i = 1; i <= n; i++) {
		  cin >> cur;
		  dp[i] = cur * t[i];
		  while (!q.empty()) {
			  node tmp = q.top();
			  if (tmp.now + t[tmp.now] > i)break;
			  q.pop();
			  update(1,1,n,tmp.now,dp[tmp.now]);
		  }
		  //cout<<"******"<<endl;
		  dp[i] += query(1,1,n,1,i-t[i]);
		  ans = max(ans, dp[i]);
		  q.push(node{ i });
	}
	cout << ans << endl;
	return 0;
}
