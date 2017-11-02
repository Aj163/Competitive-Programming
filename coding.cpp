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

int main()
{
	int n, a[4009];
	ll ans, dp[4009], t1, t2, t3, t4;

	read(n);
	f(i, n)
		read(a[i]);

	f(i, n)
	{
		t3 = 1e18;
		f(j, i+1)
		{
			if(j==0)
				t2 = 0;
			else
				t2 = dp[j-1];

			t4 = i-j+1;
			t2 += max(t4*20, (a[i]-a[j])*1ll-1800+20);
			t2 += 120;
			t3 = min(t3, t2);
		}
		dp[i] = t3;
	}

	cout<<dp[n-1];
}