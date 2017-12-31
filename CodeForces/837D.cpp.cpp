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

int main()
{
	ll a, b;
	int n, k, turn = 0, ans = 0;
	pii p[210];
	int dp[2][210][8300];

	read2(n, k);
	f(i, n)
	{
		cin>>a;
		p[i] = mp(0, 0);
		b = a;
		while(a%2==0)
			p[i].first++, a/=2;
		while(b%5==0)
			p[i].second++, b/=5;

		//cout<<p[i].first<<" "<<p[i].second<<endl;
	}

	f(i, 210)
		f(j, 8300)
			dp[turn][i][j] = -1e9;

	dp[turn][0][0] = 0;
	f(z, n)
	{
		turn = 1-turn;

		f(i, 210)
			f(j, 8300)
				dp[turn][i][j] = -1e9;

		f(i, z+2)
			f(j, 8300)
			{
				dp[turn][i][j] = dp[1-turn][i][j];
				if(j>=p[z].second && i>=1)
					dp[turn][i][j] = max(dp[turn][i][j], dp[1-turn][i-1][j-p[z].second] + p[z].first)%M;
			}
	}

	f(i, 8300)
		ans = max(ans, min(i, dp[turn][k][i]));

	//f(i, 10)
		//printf("%d %d\n", i, dp[turn][0][i]);

	//printf("\n%d\n", dp[turn][1][2]);

	printf("%d\n", ans);
}