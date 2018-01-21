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

#define maxn 1000009
int fact[maxn];

int power(int a, int n, int m = 1000000007)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a*1ll*power((a*1ll*a)%m, (n-1)/2))%m;
	return power((a*1ll*a)%m, n/2);
}

void facts(int m = 1000000007)
{
	fact[0] = 1;
	F(i, 1, maxn, 1)
		fact[i] = (fact[i-1]*1ll*i)%m;
}

int comb(int a, int b, int m = 1000000007)
{
	if(a<b)
		return 0;

	ll ans = fact[a];
	ans = (ans*power(fact[b], m-2))%m;
	ans = (ans*power(fact[a-b], m-2))%m;
	return ans;
}

int main()
{
	set<int> v;
	set<int>::iterator it;
	facts();

	char n[1009];
	int l, ans = 0, cnt = 0, k;
	int steps[1009];

	memset(steps, 0, sizeof(steps));

	reads(n);
	read(k);
	if(k==0)
	{
		printf("1\n");
		return 0;
	}

	if(k==1)
		v.insert(1);

	F(i, 2, 1001, 1)
	{
		steps[i] = steps[__builtin_popcount(i)] +1;
		if(steps[i] == k-1)
			v.insert(i);
	}
	
	
	l = strlen(n);

	for(it = v.begin(); it!=v.end(); it++)
	{
		cnt = *it;
		int flag = 1;
		f(i, l)
		{
			if(n[i] == '1')
			{
				ans = (ans + comb(l-i-1, cnt))%M;
				cnt--;
			}
			if(cnt == 0)
			{
				ans = (ans+1)%M;
				flag = 0;
				break;
			}
		}

		if(flag == 0)
			continue;
		if(cnt == 0)
			ans = (ans+1)%M;
		//printf("%d\n", ans);
	}

	if(k==1)
		printf("%d\n", (ans-1+M)%M);
	else
		printf("%d\n", ans);
}