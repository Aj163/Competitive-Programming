#define maxn 1000009

bool isprime[maxn];
vector<int> primes;

void seive()
{
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;

	for(int i=2; i<maxn; i++)
		if(isprime[i])
		{
			primes.push_back(i);
			for(int j=2*i; j<maxn; j+=i)
				isprime[j] = 0;
		}

	//printf("%d\n", primes.size());
}