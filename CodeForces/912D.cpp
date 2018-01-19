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

int n, m, r, k;
ll ans = 0;
priority_queue< pair< ll, pii > > mul;
pair< ll, pii > t1;
map< pii, int> vis;

bool valid(int x, int y)
{
	if(x<0 || x>=n || y<0 || y>=m)
		return 0;
	return 1;
}

ll calc(int x, int y)
{
	return min(min(r, x+1), min(n-x, n-r+1))*1ll*min(min(r, y+1), min(m-y, m-r+1));
}

void bfs(int x, int y)
{
	mul.push(mp(calc(x, y), mp(x, y)));
	while(!mul.empty() && k)
	{
		t1 = mul.top();
		mul.pop();

		x = t1.second.first;
		y = t1.second.second;

		if(vis.find(mp(x, y)) != vis.end())
			continue;

		vis[mp(x, y)] = 1;

		ans += t1.first;
		//cout<<t1.first<<" - "<<x<<" "<<y<<endl;
		k--;

		
		if(valid(x+1, y))
			mul.push(mp(calc(x+1, y), mp(x+1, y)));
		if(valid(x-1, y))
			mul.push(mp(calc(x-1, y), mp(x-1, y)));
		if(valid(x, y+1))
			mul.push(mp(calc(x, y+1), mp(x, y+1)));
		if(valid(x, y-1))
			mul.push(mp(calc(x, y-1), mp(x, y-1)));

		/*
		if(valid(x+1, y+1))
			mul.push(mp(calc(x+1, y+1), mp(x+1, y+1)));
		if(valid(x-1, y+1))
			mul.push(mp(calc(x-1, y+1), mp(x-1, y+1)));
		if(valid(x-1, y-1))
			mul.push(mp(calc(x-1, y-1), mp(x-1, y-1)));
		if(valid(x+1, y-1))
			mul.push(mp(calc(x+1, y-1), mp(x+1, y-1)));
		*/
	}
}

int main()
{
	vis.clear();
	read2(n, m);
	read2(r, k);

	bfs(n/2, m/2);

	double answer = 1.0*ans/((n-r+1)*1ll*(m-r+1));
	printf("%0.9lf\n", answer);
}