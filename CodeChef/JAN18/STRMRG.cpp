#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int t, n, m;
int dp[5009][5009][2];
char a[5009], b[5009];

int solve(int i, int j, int p)
{
	if(i==n && j==m)
		return 0;

	if(dp[i][j][p] != -1)
		return dp[i][j][p];

	int ans = 1e9;
	char t1;

	if(p==0)
		t1 = a[i-1];
	else
		t1 = b[j-1];

	if(i==n)
		ans = min(ans, solve(i, j+1, 1) + (b[j] != t1));
	else if(j==m)
		ans = min(ans, solve(i+1, j, 0) + (a[i] != t1));
	else
	{
		ans = min(ans, solve(i+1, j, 0) + (a[i] != t1));
		ans = min(ans, solve(i, j+1, 1) + (b[j] != t1));
	}

	return dp[i][j][p] = ans;
}		

int main()
{
	read(t);
	f(z, t)
	{
		memset(dp, -1, sizeof(dp));
		read2(n, m);
		reads(a);
		reads(b);

		F_(i, n-1, -1, 1)
			a[i+1] = a[i];

		a[n+1] = '\0';
		a[0] = '!';
		n++;

		printf("%d\n", solve(1, 0, 0));
	}
}