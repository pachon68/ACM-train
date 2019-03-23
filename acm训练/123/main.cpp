/**/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>

typedef long long LL;
using namespace std;

int n, k;
int a[100005];

int min(int x, int y){
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0x3f3f3f3f;
	for (int i = k; i <= n; i++){
		ans = min(ans, a[i] - a[i - k + 1] + min(abs(a[i]), abs(a[i - k + 1])));
	}
	printf("%d\n", ans);

	return 0;
}
