#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
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

int n, x, y, ans=0;
vi v[100009];

int dfs(int e, int p)
{
	int ret = 0;
	for(int i=0; i<v[e].size(); i++)
		if(v[e][i] != p)
		{
			int temp = dfs(v[e][i], e);
			ret += temp;
			if(temp%2 == 0)
				ans++;
		}

	return ret +1;
}

int main()
{
	read(n);
	for(int i=0; i<n-1; i++)
	{
		read2(x, y);
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);
	if(n%2==1)
		printf("-1\n");
	else
		printf("%d\n", ans);
}