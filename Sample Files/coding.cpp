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

int n, k;
pii p[210];
map< pii, int > dp[210][210];

int solve(int i, int c, int p2, int p5)
{
	if(c==k)
		return min(p2, p5);
	if(i==n)
		return -1e9;

	if(dp[i][c].find(mp(p2, p5)) != dp[i][c].end())
		return dp[i][c][mp(p2, p5)];

	int a = solve(i+1, c+1, p2+p[i].first, p5+p[i].second);
	int b = solve(i+1, c, p2, p5);

	return dp[i][c][mp(p2, p5)] = max(a, b);
}

int main()
{
	ll a;

	cin>>n>>k;
	f(i, n)
	{
		cin>>a;
		p[i] = mp(0, 0);
		while(a%2==0)
			p[i].first++, a/=2;
		while(a%5==0)
			p[i].second++, a/=5;

		//cout<<p[i].first<<" "<<p[i].second<<endl;
	}

	cout<<solve(0, 0, 0, 0);;
}