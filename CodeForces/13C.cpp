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

int n, turn = 0;
int a[5009];
ll dp[2][5009], sorts[5009], mindp[5009];

int main()
{
	read(n);
	f(i, n)
	{
		read(a[i]);
		sorts[i] = a[i];
	}

	sort(sorts, sorts+n);
	f(i, 5009)
	{
		mindp[i] = 0;
		dp[turn][i] = 0;
	}

	f(k, n)
	{
		turn = 1-turn;
		f(i, 5009)
			dp[turn][i] = 0;

		f(i, n)
		{
			dp[turn][i] = mindp[i] + abs(a[k] - sorts[i]);
			if(i==0)
				mindp[i] = dp[turn][0];
			else
				mindp[i] = min(mindp[i-1], dp[turn][i]);
		}
	}

	ll ans = 1e18;
	f(i, n)
		ans = min(ans, dp[turn][i]);

	cout<<ans<<endl;
}