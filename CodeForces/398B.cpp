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

int n;
double dp[2009][2009];

double solve(int r, int c)
{
	if(r==n && c==n)
		return 0.0;
	if(r>n || c>n)
		return 0.0;

	if(dp[r][c] > -2)
		return dp[r][c];

	double ans = 1.0*r*(n-c) /n/n*(solve(r, c+1) +1);
	ans += 1.0 * c*(n-r) /n/n * (solve(r+1, c) +1);
	ans += 1.0 * (n-c)*(n-r) /n/n * (solve(r+1, c+1) +1);
	ans += 1.0 * r*c /n/n;
	double fac = 1.0 - 1.0*r*c/n/n;
	ans /= fac;

	return dp[r][c] = ans;
}

int main()
{
	set<int> r, c;
	int x, y, m;

	read2(n, m);
	for(int i=0; i<m; i++)
	{
		read2(x, y);
		r.insert(x);
		c.insert(y);
	}

	for(int i=0; i<2009; i++)
		for(int j=0; j<2009; j++)
			dp[i][j] = -3.0;

	printf("%0.9lf\n", solve(r.size(), c.size()));
}