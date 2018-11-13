#define maxn 1000009
int fact[maxn];

long long fastPow(long long a, long long n) {

	long long res=1;
	while(n>0) {
		if(n%2)
			res = (res * a) % M;
		a = (a * a) % M;
		n /= 2;
	}

	return res;
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