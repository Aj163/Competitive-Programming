#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {

	int t, n, p;
	long long a[N], pre[N];

	cin >> t;
	for(int z=1; z<=t; z++) {
		cin >> n >> p;
		for(int i=1; i<=n; i++)
			cin >> a[i];

		sort(a+1, a+n+1);

		pre[0] = 0;
		for(int i=1; i<=n; i++)
			pre[i] = pre[i-1] + a[i];

		long long ans = 1e18;
		for(int i=p; i<=n; i++)
			ans = min(ans, a[i] * p - pre[i] + pre[i-p]);

		printf("Case #%d: %lld\n", z, ans);
	}
}