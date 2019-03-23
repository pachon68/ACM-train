#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 2*100 * 1000 + 10;
int x1, y11, x2,y22,n;
int ud[MAXN], rl[MAXN];
string s;

int main() {

	scanf("%d%d",&x1,&y11);
	scanf("%d%d",&x2,&y22);
	scanf("%d",&n);
	cin >> s;
	s.insert(s.begin(),'t');				//此处插入只是为了方便下面for循环书写
	ud[0] = rl[0] = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'U')ud[i]=ud[i-1]+1,rl[i]=rl[i-1];
		else if (s[i] == 'D')ud[i]=ud[i-1]-1,rl[i]=rl[i-1];
		else if (s[i] == 'R')rl[i]=rl[i-1]+1,ud[i]=ud[i-1];
		else rl[i]=rl[i-1]-1,ud[i]=ud[i-1];
	}

	ll R = 1e15, L = 0;
	ll disx = (x2 - x1), disy = (y22 - y11);
	for(int i=1;i<=n;i++){
        cout<<ud[i]<<' '<<rl[i]<<endl;
	}
	cout<<disx<<' '<<disy<<endl;
	while (R > L) {							//二分天数
		ll mid = (R + L) / 2;
		ll cnt = mid / n, res = mid % n;
		ll disxx = cnt * rl[n] + rl[res];
		ll disyy = cnt * ud[n] + ud[res];
		if (abs(disxx - disx) + abs(disyy - disy) <= mid  )R = mid;
		else
			L = mid+1;
	}
	if (R ==1e15)
		puts("-1");
	else
		cout << R << endl;
	return 0;
}
