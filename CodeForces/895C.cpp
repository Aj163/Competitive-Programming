#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
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

int p[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int n, a, turn=0, t1, t2;
int ctr[80], dp[2][1<<20], p2[100005];

int mask(int a)
{
	int num = 0, t, n = a;
	f(i, 19)
	{
		t = 0;
		while(n%p[i]==0)
		{
			t++;
			n/=p[i];
		}

		num |= ((t%2)<<i);
	}
	return num;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(ctr, 0, sizeof(ctr));

	read(n);
	f(i, n)
	{
		read(a);
		ctr[a]++;
	}

	dp[0][0] = 1;
	p2[0] = 1;
	F(i, 1, 100005, 1)
		p2[i] = (p2[i-1]*1ll*2)%M;

	F(i, 1, 71, 1)
	{
		turn = 1-turn;
		t1 = mask(i);

		f(j, 1<<19)
			dp[turn][j] = dp[1-turn][j];

		if(ctr[i] == 0)
			continue;

		f(j, 1<<19)
		{
			dp[turn][j] = (dp[turn][j] + dp[1-turn][j] * 1ll * (p2[ctr[i] -1] -1))%M;
			dp[turn][j^t1] = (dp[turn][j^t1] + dp[1-turn][j] * 1ll * p2[ctr[i] -1])%M;
		}
	}

	printf("%d\n", (dp[turn][0] -1 +M)%M);
}