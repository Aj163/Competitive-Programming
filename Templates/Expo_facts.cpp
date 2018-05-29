#define maxn 1000009
int fact[maxn];

int power(int a, int n, int m = 1000000007)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a*1ll*power((a*1ll*a)%m, (n-1)/2, m))%m;
	return power((a*1ll*a)%m, n/2, m);
}

void facts(int m = 1000000007)
{
	fact[0] = 1;
	F(i, 1, maxn, 1)
		fact[i] = (fact[i-1]*1ll*i)%m;
}

int comb(int a, int b, int m = 1000000007)
{
	ll ans = fact[a];
	ans = (ans*power(fact[b], m-2))%m;
	ans = (ans*power(fact[a-b], m-2))%m;
	return ans;
}

int perm(int a, int b, int m = 1000000007)
{
	ll ans = fact[a];
	ans = (ans*power(fact[a-b], m-2))%m;
	return ans;
}