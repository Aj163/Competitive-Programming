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
	int t, n, a, t1;
	int cnt[4];

	read(t);
	f(z, t)
	{
		memset(cnt, 0, sizeof(cnt));

		read(n);
		f(i, n)
		{
			read(a);
			cnt[a%4]++;
		}

		a = 0;

		t1 = min(cnt[1], cnt[3]);
		a += t1;
		cnt[1] -= t1;
		cnt[3] -= t1;

		if(cnt[3]%2 == 1)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			cnt[2] += cnt[3]/2;
			a += cnt[3]/2;
		}

		if(cnt[1]%2 == 1)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			a += cnt[1]/2;
			cnt[2] += cnt[1]/2;
		}

		if(cnt[2]%2 == 1)
		{
			printf("-1\n");
			continue;
		}
		else
			a += cnt[2]/2;

		printf("%d\n", a);
	}
}