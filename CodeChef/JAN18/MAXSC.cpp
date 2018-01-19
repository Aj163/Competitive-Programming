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

int main()
{
	int t, n, a[709][709], maxi, prev, flag;
	ll ans;

	read(t);
	f(z, t)
	{
		read(n);
		f(i, n)
			f(j, n)
				read(a[i][j]);

		ans = 0;
		prev = 2e9;
		flag = 1;

		F_(i, n-1, -1, 1)
		{
			maxi = -1;
			f(j, n)
				if(a[i][j] > maxi && a[i][j] < prev)
					maxi = a[i][j];

			if(maxi == -1)
				flag = 0;
			
			ans += maxi;
			prev = maxi;
		}

		if(flag)
			printf("%lld\n", ans);
		else
			printf("-1\n");
	}
}