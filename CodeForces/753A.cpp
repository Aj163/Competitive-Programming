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

int dp[1009][1009], ch[1009][1009];
pii step[1009][1009];

int solve(int n, int k)
{
	if(n==0)
		return 0;

	if(dp[n][k] != -1)
		return dp[n][k];

	int ret = -1, choice;
	pii st;
	F(i, 1, min(n, k-1)+1, 1)
	{
		if(solve(n-i, i) +1 > ret)
		{
			ret = solve(n-i, i) +1;
			choice = i;
			st = mp(n-i, i);
		}
	}

	ch[n][k] = choice;
	step[n][k] = st;
	return dp[n][k] = ret;
}

int main()
{
	int n;
	read(n);

	memset(dp, -1, sizeof(dp));
	f(i, 1009)
		f(j, 1009)
			step[i][j] = mp(-1, -1);
	printf("%d\n", solve(n, 1008));

	pii st = mp(n, 1008);
	while(ch[st.first][st.second] != 0)
	{
		printf("%d ", ch[st.first][st.second]);
		st = step[st.first][st.second];
	}
}