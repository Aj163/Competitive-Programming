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

int n, used[16], used_sum[16], ans=0;

void solve(int i)
{
	if(i==n)
	{
		ans++;
		return;
	}

	f(j, n)
	{
		if(used[j] == 1)
			continue;

		int t1 = i+j;
		if(t1>=n)
			t1-=n;

		if(used_sum[t1] == 1)
			continue;

		used[j] = 1;
		used_sum[t1] = 1;
		solve(i+1);

		used[j] = 0;
		used_sum[t1] = 0;
	}
}

int main()
{
	read(n);
	int answer[16] = {1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

	memset(used, 0, sizeof(used));
	memset(used_sum, 0, sizeof(used_sum));

	ans = 0;
	//solve(0);
	F(i, 2, n+1, 1)
		ans = (ans*1ll*i)%M;

	printf("%d\n", answer[n-1]);
}