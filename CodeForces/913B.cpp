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

int n;
vi v[1009];

int dfs(int x, int p)
{
	int ret = 1;
	f(i, v[x].size())
		if(v[x][i] != p)
			ret += dfs(v[x][i], x);

	return ret;
}

bool dfs2(int x, int p)
{
	int ret = 0;
	bool ans = 1;
	f(i, v[x].size())
	{
		if(v[x][i] != p && v[v[x][i]].size() == 0)
			ret++;
		else if(v[x][i] != p)
			ans &= dfs2(v[x][i], x);
	}
	//printf("#%d#\n", ans&(ret>=3));
	return (ans & (ret>=3));
}

int main()
{
	int a;

	read(n);
	f(i, n-1)
	{
		read(a);
		v[a].pb(i+2);
	}

	F(i, 1, n, 1)
	{
		if(dfs(i, -1) == n)
		{
			//printf("~%d~\n", i);
			if(!dfs2(i, -1))
				printf("No\n");
			else
				printf("Yes\n");

			return 0;
		}
	}
}