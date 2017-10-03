#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long

using namespace std;

int n, val[200009], ans[200009], x, y;
vi v[200009];

int gcd(int a, int b)
{
	int c = max(a, b);
	int d = min(a, b);
	if(d==0)
		return c;
	return gcd(d, c%d);
}

void dfs(int s, int e, int g, int d)
{
	ans[s] = max(ans[s], gcd(g, val[s]));
	if(d==0)
		ans[s] = max(ans[s], g);

	f(i, v[s].size())
		if(v[s][i]!=e)
		{
			dfs(v[s][i], s, gcd(g, val[s]), d);
			if(d==0 && gcd(val[s], g)!=g)
				dfs(v[s][i], s, g, 1);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	f(i, n)
		cin>>val[i+1];

	f(i, n-1)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	memset(ans, 0, sizeof(ans));
	dfs(1, -1, 0, 0);
	f(i, n)
		cout<<ans[i+1]<<" ";
}