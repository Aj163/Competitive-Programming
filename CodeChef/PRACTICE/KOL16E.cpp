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

ll p;

ll power(ll a, ll n)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a * power((a*a)%p, (n-1)/2))%p;
	return power((a*a)%p, n/2);
}

int main()
{
	ll t, temp, pow, x, y, ans, t1;
	vector<ll> factors;
	
	scanf("%lld", &t);
	f(z, t)
	{
		scanf("%lld", &p);

		temp = p-1;
		factors.clear();

		for(x=1; x*x<= temp; x++)
			if(temp%x == 0)
			{
				factors.pb(x);
				factors.pb(temp/x);
			}

		sort(factors.begin(), factors.end());
		f(i, factors.size())
		{
			t1 = power(10, factors[i]);
			if(t1 == 1 || t1 == p-1)
			{
				ans = i;
				break;
			}
		}

		if(t1 == 1)
			printf("Case %d: %lld-sum\n", z+1, factors[ans]);
		else
			printf("Case %d: %lld-altersum\n", z+1, factors[ans]);
	}
}