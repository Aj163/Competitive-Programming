#define maxn 1000009
int fact[maxn];

int power(int a, int n)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a*1ll*power((a*1ll*a)%M, (n-1)/2))%M;
	return power((a*1ll*a)%M, n/2);
}

void facts()
{
	fact[0] = 1;
	F(i, 1, maxn, 1)
		fact[i] = (fact[i-1]*1ll*i)%M;
}

int comb(int a, int b)
{
	ll ans = fact[a];
	ans = (ans*power(fact[b], M-2))%M;
	ans = (ans*power(fact[a-b], M-2))%M;
	return ans;
}

int perm(int a, int b)
{
	ll ans = fact[a];
	ans = (ans*power(fact[a-b], M-2))%M;
	return ans;
}