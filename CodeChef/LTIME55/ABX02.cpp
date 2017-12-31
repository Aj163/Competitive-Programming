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

int t, p, q, n, b1, b2, s1, s2;
int dp[410][59][59];

int main()
{
	read(t);
	f(z, t)
	{
		read3(p, q, n);
		read2(b1, b2);
		read2(s1, s2);

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;

		F(i, 1, 100000, 1)
		{
			if(i%2 == 0)
			{
				if(i/2>b2)
					break;

				f(k, p+1)
				{
					F(j, 1, q+1, 1)
						F(l, max(j-s2, 0), j, 1)
							dp[i][k][j] = (dp[i][k][j] + dp[i-1][k][l])%M;
				}
			}
			else
			{
				if((i+1)/2>b1)
					break;

				f(k, q+1)
				{
					F(j, 1, p+1, 1)
						F(l, max(j-s1, 0), j, 1)
							dp[i][j][k] = (dp[i][j][k] + dp[i-1][l][k])%M;
				}
			}
		}

		int ans = 0;
		f(i, 410)
			f(j, 59)
			{	
				if(n-j<=q)
					ans = (ans + dp[i][j][n-j])%M;
			}

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;

		F(i, 1, 100000, 1)
		{
			if(i%2 == 1)
			{
				if((i+1)/2>b2)
					break;

				f(k, p+1)
				{
					F(j, 1, q+1, 1)
						F(l, max(j-s2, 0), j, 1)
							dp[i][k][j] = (dp[i][k][j] + dp[i-1][k][l])%M;
				}
			}
			else
			{
				if(i/2>b1)
					break;

				f(k, q+1)
				{
					F(j, 1, p+1, 1)
						F(l, max(j-s1, 0), j, 1)
							dp[i][j][k] = (dp[i][j][k] + dp[i-1][l][k])%M;
				}
			}
		}

		f(i, 410)
			f(j, 59)
			{	
				if(n-j<=q)
					ans = (ans + dp[i][j][n-j])%M;
			}

		printf("%d\n", ans);
		
	}
}