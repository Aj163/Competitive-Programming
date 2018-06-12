#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int n, m, k;
int c[109];
ll dp[109][109][109];
int p[109][109];

ll solve(int i, int j, int prev)
{
	if(i==n)
	{
		if(j==k)
			return 0;
		return 1e15;
	}

	if(dp[i][j][prev] != -1)
		return dp[i][j][prev];

	if(c[i] != 0)
		return dp[i][j][prev] = solve(i+1, j+(c[i]!=prev), c[i]);

	ll ans = 1e15;
	for(int x=1; x<=m; x++)
		ans = min(ans, solve(i+1, j+(x!=prev), x) + 1ll*p[i][x-1]);

	return dp[i][j][prev] = ans;
}

int main()
{
	read3(n, m, k);
	for(int i=0; i<n; i++)
		read(c[i]);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			read(p[i][j]);

	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, 0, 0);
	if(ans == 1e15)
		printf("-1\n");
	else
		printf("%lld\n", ans);
}