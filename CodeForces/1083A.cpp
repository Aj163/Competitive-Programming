#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 5;
int n;
int w[N];
long long dp[N][2];
vector<pair<int, int > > v[N];
 
void dfs(int x, int p) {
 
	long long max2 = -1e18, max1 = -1e18;
	dp[x][0] = -1e18;
 
	for(auto it : v[x]) {
		int v = it.first;
		int weight = it.second;
 
		if(v == p)
			continue;
 
		dfs(v, x);
		long long c = dp[v][1] - weight;
		dp[x][0] = max(dp[x][0], dp[v][0]);
 
		if(c > max1) {
			max2 = max1;
			max1 = c;
		}
		else if(c > max2)
			max2 = c;
	}
 
	dp[x][1] = w[x] + max(0ll, max1);
	dp[x][0] = max(dp[x][0], w[x] + max(0ll, max1) + max(0ll, max2));
}
 
int main() {
 
	cin >> n;
	for(int i=1; i<=n; i++)
		scanf("%d", &w[i]);
 
	int x, y, weight;
	for(int i=0; i<n-1; i++) {
		scanf("%d%d%d", &x, &y, &weight);
		v[x].push_back(make_pair(y, weight));
		v[y].push_back(make_pair(x, weight));
	}
 
	dfs(1, 0);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
}