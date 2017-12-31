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

int l;
int dp[100009][2];
char str[100009];

int solve(int i, int type)
{
	if(i==l)
		return 0;
	if(dp[i][type] != -1)
		return dp[i][type];

	int ret;
	if(type == 1)
	{
		ret = solve(i+1, 1);
		if(str[i] < 'a')
			ret++;
	}
	else
	{
		if(str[i]<'a')
			ret = solve(i+1, 0);
		else
			ret = min(solve(i+1, 1), solve(i+1, 0)+1);
	}

	return dp[i][type] = ret;
}

int main()
{
	reads(str);
	l = strlen(str);
	memset(dp, -1, sizeof(dp));

	printf("%d\n", solve(0, 0));
}