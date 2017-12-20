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

int n, ans = 1;
vi v[10009];
int col[10009];

void dfs(int x, int p, int c)
{
	if(col[x] != c)
		ans++;

	f(i, v[x].size())
		if(v[x][i] != p)
			dfs(v[x][i], x, col[x]);
}

int main()
{
	int a;

	read(n);
	F(i, 2, n+1, 1)
	{
		read(a);
		v[a].pb(i);
		v[i].pb(a);
	}

	f1(i, n)
		read(col[i]);

	dfs(1, -1, col[1]);
	printf("%d\n", ans);
}