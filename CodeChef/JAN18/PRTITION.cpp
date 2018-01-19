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

int t, n, x, tot;
ll sum;
vi v;
vector<int>::iterator it;

bool solve(int k, ll s)
{
	tot++;
	//printf("%d %d\n", k, s);
	if(s==sum)
		return 1;
	if(k == 0)
		return 0;
	if(k==x)
		return solve(k-1, s);

	bool b = 0;
	if(sum-s >= k)
	{
		v.pb(k);
		b = solve(k-1, s+k);
		if(b==0)
		{
			it = v.end();
			it--;
			v.erase(it);
		}
	}
	else if(sum-s<k && sum-s>0 && sum-s != x)
	{
		v.pb(sum-s);
		return 1;
	}

	if(b==0)
		return solve(k-1, s);
	return 1;
}

int main()
{
	int p;

	read(t);
	f(z, t)
	{
		tot=0;
		read2(x, n);
		sum = n*1ll*(n+1)/2 - x;

		if(n<=3 || sum%2)
		{
			printf("impossible\n");
			continue;
		}
		sum/=2;

		v.clear();
		solve(n, 0);

		p=0;
		sort(v.begin(), v.end());
		F(i, 1, n+1, 1)
		{
			if(i==x)
				printf("2");
			else if(p<n && v[p] == i)
			{
				p++;
				printf("0");
			}
			else
				printf("1");
		}
		printf("\n");
	}
}