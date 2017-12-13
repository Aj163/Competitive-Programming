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
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int n;
int dp[109][2009];
int ch[109][2009];
pair< pii, pii > p[109];
vi ans;

int solve(int i, int tim)
{
	if(i==n)
		return 0;

	if(dp[i][tim] != -1)
		return dp[i][tim];

	if(tim + p[i].first.second >= p[i].first.first)
		return dp[i][tim] = solve(i+1, tim);

	int temp = solve(i+1, tim);

	if(solve(i+1, tim + p[i].first.second) + p[i].second.first > temp)
	{
		temp = solve(i+1, tim + p[i].first.second) + p[i].second.first;
		ch[i][tim] = 1;
	}
	
	return dp[i][tim] = temp;
}

int main()
{
	int pi, t, d;
	read(n);

	f(i, n)
	{
		read3(t, d, pi);
		p[i] = mp(mp(d, t), mp(pi, i+1));
	}

	memset(dp, -1, sizeof(dp));
	memset(ch, 0, sizeof(ch));

	sort(p, p+n);
	printf("%d\n", solve(0, 0));

	int temp = 0;
	f(i, n)
		if(ch[i][temp] == 1)
		{
			ans.pb(p[i].second.second);
			temp += p[i].first.second;
		}

	printf("%d\n", (int)ans.size());
	f(i, ans.size())
		printf("%d ", ans[i]);
}