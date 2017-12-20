#define INF ((int)1e9)
int dp[100009]; //Say max value of N is 10^5. Set initial values to -1

int solve(int N)
{
	if(n == 0)
		return 0;
	if(n<0)
		return INF;

	if(dp[n] != -1)
		return dp[n];

	int choice1 = solve(n-1) + 1;
	int choice2 = solve(n-3) + 1;
	int choice3 = solve(n-4) + 1;

	return dp[n] = min(choice1, min(choice2, choice3));
}