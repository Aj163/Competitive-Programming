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

#define maxn 100009

bool isprime[maxn];
vector<int> primes;
int a[maxn], cnt[maxn][200], tmp[10], block=400;
pii maskers[maxn];

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
}

void update(int pos, int add)
{
	int t1, curr, siz, mask;

	t1 = a[pos];
	curr = pos/block;
	siz = 0;

	for(int i=0; primes[i]*primes[i] <= t1; i++)
	{
		if(t1%primes[i] == 0)
		{
			tmp[siz++] = primes[i];
			while(t1%primes[i] == 0)
				t1/=primes[i];
		}
	}

	if(t1>1)
		tmp[siz++] = t1;

	mask = (1<<siz) -1;
	f1(i, mask)
	{
		t1 = 1;
		f(j, siz)
			if((1<<j)&i)
				t1 *= tmp[j];

		cnt[t1][curr] += add;
	}
}

int main()
{
	int n, q, blocks, t1, t2, t3, t4, t5, t6, masks, left, right, ans;
	int mask, siz=0;

	seive();
	read(n);
	blocks = n/block;

	f1(i, n)
		read(a[i]);

	f1(i, n)
		update(i, 1);

	read(q);
	f(z, q)
	{
		read3(t1, t2, t3);
		if(t1 == 1)
		{
			update(t2, -1);
			a[t2] = t3;
			update(t2, 1);
		}
		else
		{
			read(t4);
			if(t4 == 1)
				ans = t3-t2+1;
			else
			{
				left = t2/block;
				right = t3/block;
				ans = 0;

				F(i, t2, t3+1, 1)
				{
					if(i/block != t2/block)
						break;
					if(__gcd(a[i], t4) > 1)
						ans++;
				}

				if(t2/block != t3/block)
				{
					F_(i, t3, t2-1, 1)
					{
						if(i/block != t3/block)
							break;
						if(__gcd(a[i], t4) > 1)
							ans++;
					}
				}

				siz = 0;
				for(int i=0; primes[i]*primes[i] <= t4; i++)
					if(t4%primes[i] == 0)
					{
						tmp[siz++] = primes[i];
						while(t4%primes[i] == 0)
							t4/=primes[i];
					}

				if(t4 > 1)
					tmp[siz++] = t4;

				mask = (1<<siz) -1;
				masks = 0;

				f1(j, mask)
				{
					t5 = 1;
					f(k, siz)
						if((1<<k)&j)
							t5 *= tmp[k];

					if(__builtin_popcount(j) %2 == 0)
						t6 = 0;
					else
						t6 = 1;

					maskers[masks++] = mp(t5, t6);
				}
				
				F(i, left+1, right, 1)
					f(j, masks)
					{
						if(maskers[j].second == 0)
							ans -= cnt[maskers[j].first][i];
						else
							ans += cnt[maskers[j].first][i];
					}

				t5 = t3-t2+1;
				ans = t5-ans;
			}

			printf("%d\n", ans);
		}
	}
}