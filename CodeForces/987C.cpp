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

ll dp[3009][3009][3];
int s[3009], c[3009];
int n;

ll solve(int i, int j, int k)
{
	if(k==3)
		return 0;
	if(i==n)
		return 1e17;

	if(dp[i][j][k] != -1)
		return dp[i][j][k];

	if(j != 3007 && s[i]>s[j])
		return dp[i][j][k] = min(solve(i+1, i, k+1) +c[i], solve(i+1, j, k));
	else if(j != 3007)
		return dp[i][j][k] = solve(i+1, j, k);
	return dp[i][j][k] = min(solve(i+1, i, k+1) +c[i], solve(i+1, j, k));
}

int main()
{
	memset(dp, -1, sizeof(dp));

	read(n);
	for(int i=0; i<n; i++)
		read(s[i]);
	for(int i=0; i<n; i++)
		read(c[i]);

	ll ans = solve(0, 3007, 0);
	if(ans == 1e17)
		printf("-1\n");
	else
		printf("%lld\n", ans);
}