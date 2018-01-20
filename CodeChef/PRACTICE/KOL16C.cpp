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
 
vi primes;
int C, plow, phigh, t;
ll low, high;
#define MAX 50000000
 
void seive()
{
	bool isprime[MAX];
	memset(isprime, 0, sizeof(isprime));

	primes.pb(0);
	F(i, 2, MAX, 1)
		if(isprime[i] == 0)
		{
			primes.pb(i);
			F(j, i*2, MAX, i)
				isprime[j] = 1;
		}
}
 
ll cnt(ll n, int p)
{
	ll x=1, c=0;
	while(x <= n/p)
	{
		x *= p;
		c += n/x;
	}
	return c;
}
 
ll findrange(int p, ll l, ll r, int t)
{
	if(l>r)
		return -1;
 
	ll mid;
	if(t<p)
	{
		mid = max(l, p*1ll*t);
		if(mid <= min(r, p*1ll*t + p-1))
			return mid;
		return -1;
	}
	while(l<r)
	{
		mid = (l + r)/2;
		if(cnt(mid, p) >= t)
			r = mid;
		else
			l = mid+1;
	}
 
	if(cnt(l, p) == t)
		return l;
	return -1;
}
 
int main()
{
	seive();
	read(C);
	f(z, C)
	{
		scanf("%lld%lld", &low, &high);
		read3(plow, phigh, t);
 
		ll ans = 0, L, R;
		F(i, plow, phigh+1, 1)
		{
			int p = primes[i];
			L = findrange(p, low, high, t);
			if(L == -1)
				continue;
 
			R = min(high, p*(L/p) + p-1);
			ans += R-L+1;
			low = R+1;
		}
 
		cout<<ans<<endl;
	}
} 