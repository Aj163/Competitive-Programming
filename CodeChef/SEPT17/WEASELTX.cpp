#include <bits/stdc++.h>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long
 
using namespace std;
 
int n, m, x, y, p, height=0, cyc, hp[200009];
ll val[200009], lev[200009], ans[300009], del;
vi v[200009];
 
int dfs(int s, int e, int l)
{
	lev[l] ^= val[s];
	height = max(height, l);
 
	f(i, v[s].size())
		if(v[s][i] != e)
			dfs(v[s][i], s, l+1);
}
 
int main()
{
	read2(n, m);
 
	f(i, n-1)
	{
		read2(x, y);
		v[x].pb(y);
		v[y].pb(x);
	}
 
	int e=1;
	f(i, 200009)
	{
		if(e>=i)
			hp[i]=e;
		else
		{
			e*=2;
			hp[i]=e;
		}
	}
 
	f(i, n)
		scanf("%lld", &val[i]);
 
	memset(lev, 0, sizeof(lev));
	dfs(0, -1, 0);
 
	cyc = hp[height+1];
	
	f(i, height+1)
		ans[i] = lev[i];
	int step=1;
	while(step<=cyc/2)
	{
		int j=0;
		while(j<cyc)
		{
			f(i, step)
				ans[i+step+j] ^= ans[i+j];
			
			j+=step*2;
		}
		step*=2;	
	}
 
	f(z, m)
	{
		scanf("%lld", &del);
		printf("%lld\n", ans[(cyc - del%cyc)%cyc]);
	}
}   