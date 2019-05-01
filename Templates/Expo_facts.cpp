#define maxn 1000009
#define N 100005
const int MOD = 1e9 + 7;
int fact[N];

long long fastPow(long long a, long long n) {

	long long res=1;
	while(n>0) {
		if(n%2)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}

	return res;
}

void facts() {
	
	fact[0] = 1;
	for(int i=1; i<N; i++)
		fact[i] = (fact[i-1] * 1ll * i) % MOD;
}

int comb(int a, int b) {

	long long ans = fact[a];
	ans = (ans * power(fact[b],   MOD-2)) % MOD;
	ans = (ans * power(fact[a-b], MOD-2)) % MOD;
	return ans;
}

int perm(int a, int b) {

	long long ans = fact[a];
	ans = (ans * power(fact[a-b], MOD-2)) % MOD;
	return ans;
}