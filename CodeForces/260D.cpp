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

int main()
{
	int n, t1, x, y;
	vector< pii > v[2];

	read(n);
	f(i, n)
	{
		read2(x, y);
		v[x].pb(mp(y, i));
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	x=0;
	y=0;
	while(x<v[0].size() && y<v[1].size())
	{
		t1 = min(v[0][x].first, v[1][y].first);
		printf("%d %d %d\n", v[0][x].second +1, v[1][y].second +1, t1);

		v[0][x].first -= t1;
		v[1][y].first -= t1;

		if(v[0][x].first < v[1][y].first)
			x++;
		else if(v[0][x].first > v[1][y].first)
			y++;
		else if(x<v[0].size()-1)
			x++;
		else
			y++;
	}

}