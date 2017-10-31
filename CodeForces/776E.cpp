#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
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

vi v[100009];
int a[100009][25];
ll dp[100009][25][2], ans[25];

void dfs(int x, int p)
{
	ll t[25][2];
	memset(t, 0, sizeof(t));

	f(i, 25)
		dp[x][i][a[x][i]] = 1;

	f(i, v[x].size())
		if(v[x][i] != p)
		{
			dfs(v[x][i], x);
			f(j, 25)
				f(k, 2)
				{
					dp[x][j][k] += dp[v[x][i]][j][k^a[x][j]];
					t[j][k] += dp[v[x][i]][j][k];
				}
		}

	f(j, 25)
	{
		ll y=0, z=0;
		f(i, v[x].size())
			if(v[x][i] != p)
			{
				y += (t[j][1] - dp[v[x][i]][j][1])*dp[v[x][i]][j][1] + (t[j][0] - dp[v[x][i]][j][0])*dp[v[x][i]][j][0];
				z += (t[j][1] - dp[v[x][i]][j][1])*dp[v[x][i]][j][0] + (t[j][0] - dp[v[x][i]][j][0])*dp[v[x][i]][j][1];
			}

		if(a[x][j])
			ans[j] += y/2;
		else
			ans[j] += z/2;
	}

	f(i, 25)
		ans[i] += dp[x][i][1];
}

int main()
{
	int n, t2, x, y;
	ll answer=0;

	read(n);
	F(i, 1, n+1, 1)
	{
		read(t2);
		f(j, 25)
			a[i][j] = (bool)(t2 & (1<<j));
	}

	f(i, n-1)
	{
		read2(x, y);
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);
	f(i, 25)
		answer += (ans[i]*(1ll<<i));

	cout<<answer;
}