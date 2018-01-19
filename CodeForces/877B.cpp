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

char s[5009];
int dp[5009][3], n;

int solve(int i, int type)
{
	if(i==n)
		return 0;

	if(dp[i][type] != -1)
		return dp[i][type];

	if(type == 2)
		return dp[i][type] = solve(i+1, 2) + (s[i] != 'a');

	if(type == 1)
		return dp[i][type] = min(solve(i+1, 1) + (s[i] != 'b'), solve(i+1, 2));
	
	return dp[i][type] = min(solve(i+1, 0) + (s[i] != 'a'), solve(i+1, 1));
}

int main()
{
	reads(s);
	n = strlen(s);
	memset(dp, -1, sizeof(dp));

	printf("%d\n", n-solve(0, 0));
}