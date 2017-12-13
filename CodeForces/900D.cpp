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

int power(int a, int n)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a * 1ll * power((a*1ll*a)%M, (n-1)/2))%M;
	return power((a*1ll*a)%M, n/2);
}

int main()
{
	int x, y, k, l, n, ans = 0, t1, t2;
	vi v;

	read2(x, y);

	if(y%x != 0)
	{
		printf("0\n");
		return 0;
	}

	k = y/x;
	x = 2;
	n = k;

	while(k!=1)
	{
		y = 0;
		while(k%x == 0)
		{
			k/=x;
			y=1;
		}

		if(y)
			v.pb(x);

		x++;
	}

	l = v.size();
	f(i, (1<<l))
	{
		t1 = 0;
		t2 = 1;
		f(j, l)
			if(i & (1<<j))
			{
				t1++;
				t2 *= v[j];
			}

		if(t1%2)
			ans = (ans + power(2, n/t2 -1)*(-1) +M)%M;
		else
			ans = (ans + power(2, n/t2 -1))%M;
	}

	printf("%d\n", ans);
}