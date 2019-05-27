#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int t, k, n;
int a[N], p[N], pre[N];
long long dp[2*N][4][N];
vector<int> dogs[N];

long long solve(int i, int j, int done, int cnt) {

	if(cnt == k) {
		if(done)
			return 0;
		return 1e18;
	}
	if(i == N)
		return 1e18;

	int ind = pre[i] + j;
	if(dp[ind][done][cnt] != -1)
		return dp[ind][done][cnt];

	long long ch1 = 1e18, ch2 = 1e18;
	if(done == 1) {
		if(dogs[i].size() <= j)
			return dp[ind][done][cnt] = solve(i+1, 0, 2, cnt);

		if(j == 0)
			ch1 = solve(i, 1, done, cnt+1) + dogs[i][0];
		else
			ch1 = solve(i, j+1, done, cnt+1) + (dogs[i][j] - dogs[i][j-1]);
		ch2 = solve(i+1, 0, 2, cnt);

		return dp[ind][done][cnt] = min(ch1, ch2);
	}
	else if(done == 2) {
		if(dogs[i].size() <= j)
			return dp[ind][done][cnt] = solve(i+1, 0, done, cnt);

		if(j == 0)
			ch1 = solve(i, 1, done, cnt+1) + dogs[i][0] * 2;
		else
			ch1 = solve(i, j+1, done, cnt+1) + (dogs[i][j] - dogs[i][j-1]) * 2;
		ch2 = solve(i+1, 0, done, cnt);

		return dp[ind][done][cnt] = min(ch1, ch2);
	}
	else {
		if(dogs[i].size() <= j)
			return dp[ind][done][cnt] = min(solve(i+1, 0, done, cnt), solve(i+1, 0, 1, cnt));

		if(j == 0)
			ch1 = solve(i, 1, done, cnt+1) + dogs[i][0] * 2;
		else
			ch1 = solve(i, j+1, done, cnt+1) + (dogs[i][j] - dogs[i][j-1]) * 2;
		ch2 = min(solve(i+1, 0, done, cnt), solve(i+1, 0, 1, cnt));

		return dp[ind][done][cnt] = min(ch1, ch2);
	}
}

int main() {

    cin >> t;
    for(int z=1; z<=t; z++) {
    	for(int i=0; i<N; i++)
    		dogs[i].clear();

    	cin >> n >> k;
    	for(int i=0; i<n; i++)
    		cin >> p[i];
    	for(int i=0; i<n; i++) {
    		cin >> a[i];
    		dogs[a[i]].push_back(p[i]);
    	}

    	pre[0] = 1;
    	for(int i=1; i<N; i++)
    		pre[i] = pre[i-1] + dogs[i-1].size() +1;

    	for(int i=0; i<N; i++)
    		sort(dogs[i].begin(), dogs[i].end());

    	memset(dp, -1, sizeof(dp));
    	long long ans = min(solve(0, 0, 0, 0), solve(0, 0, 1, 0));

    	printf("Case #%d: %lld\n", z, ans);
    }
}