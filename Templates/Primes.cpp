#define maxn 1000009

bool isprime[maxn];
vector<int> primes;

void sieve() {

	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;

	for(int i=2; i*i<=maxn; i++)
		if(isprime[i]) {
			primes.push_back(i);
			for(int j=2*i; j<maxn; j+=i)
				isprime[j] = 0;
		}
}

int phi[maxn];

void eulerSieve() {

	for(int i=0; i<maxn; i++)
		phi[i] = i;

	for(int i=2; i<maxn; i++)
		if(phi[i] == i) {
			phi[i] = i-1;
			for(int j=2*i; j<maxn; j+=i)
				phi[j] = phi[j] / i * (i-1);
		}
}