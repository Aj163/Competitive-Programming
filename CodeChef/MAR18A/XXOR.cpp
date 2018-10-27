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

int main()
{
	int n, q, l, r;
	ll ans;
	int a[100009], cnt[100009][32][2];

	memset(cnt, 0, sizeof(cnt));
	read2(n, q);

	f(i, n)
	{
		read(a[i]);
		f(j, 31)
			cnt[i+1][j][(bool)((1<<j)&a[i])]++;
	}

	f1(i, n)
	{
		f(j, 31)
		{
			cnt[i][j][0] += cnt[i-1][j][0];
			cnt[i][j][1] += cnt[i-1][j][1];
		}
	}

	f(z, q)
	{
		read2(l, r);
		ans = 0;

		f(i, 31)
		{
			if(cnt[r][i][0] - cnt[l-1][i][0] > cnt[r][i][1] - cnt[l-1][i][1])
				ans += (1ll<<(1ll*i));
		}

		printf("%lld\n", ans);
	}
}