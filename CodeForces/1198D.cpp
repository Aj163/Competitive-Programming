#include <bits/stdc++.h>
using namespace std;
 
const int N = 55;
 
int n;
char s[N][N];
int dp[N][N][N][N];
 
int solve(int a, int b, int x, int y) {
 
	if(dp[a][b][x][y] != -1)
		return dp[a][b][x][y];
 
	if(a == x && b == y)
		return s[a][b] == '#';
 
	int ans = max(x-a+1, y-b+1);
	for(int i=a; i<x; i++)
		ans = min(ans, solve(a, b, i, y) + solve(i+1, b, x, y));
	for(int i=b; i<y; i++)
		ans = min(ans, solve(a, b, x, i) + solve(a, i+1, x, y));
 
	return dp[a][b][x][y] = ans;
}
 
int main() {
 
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> s[i];
 
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0, n-1, n-1));
}