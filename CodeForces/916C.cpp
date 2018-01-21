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

vector< pair<pii , int> > ans;

int main()
{
	int n, m, answer = 0, pos = 0, x, y, w = 1e9, t1;

	read2(n, m);
	if(n==2)
	{
		printf("2 2\n");
		ans.pb(mp(mp(1, 2), 2));
	}
	else if(n==3)
	{
		printf("2 5\n");
		ans.pb(mp(mp(1, 3), 2));
		ans.pb(mp(mp(1, 2), 3));
	}
	else
	{
		answer = 2;
		ans.pb(mp(mp(1, n), 2));
		F(i, 3, n, 1)
		{
			answer++;
			ans.pb(mp(mp(1, i), 1));
		}

		t1 = 15485863 - answer;
		ans.pb(mp(mp(1, 2), t1));
		answer += t1;

		printf("2 %d\n", answer);
	}

	m -= (n-1);
	x=2;
	y=3;
	while(m>0)
	{
		ans.pb(mp(mp(x, y), w));
		m--;
		if(y==n)
		{
			x++;
			y=x+1;
		}
		else
			y++;
	}

	f(i, ans.size())
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
}