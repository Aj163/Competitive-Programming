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

int k, a, b, pa, pb;
int dp[2009][2009];

int power(int a, int n, int m = 1000000007)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a*1ll*power((a*1ll*a)%m, (n-1)/2))%m;
	return power((a*1ll*a)%m, n/2);
}

int solve(int i, int j)
{
	if(j>=k)
		return j;
	if(i+j>=k)
		return (power(pb, M-2) -1 +i +j +M)%M;

	if(dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = (pa*1ll*solve(i+1, j) + pb*1ll*solve(i, j+i))%M;
}

int main()
{
	read3(k, a, b);
	memset(dp, -1, sizeof(dp));

	pa = (a*1ll*power(a+b, M-2))%M;
	pb = (b*1ll*power(a+b, M-2))%M;

	printf("%d\n", solve(1, 0));
}