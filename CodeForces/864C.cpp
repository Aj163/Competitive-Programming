#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
	int a, b, f, k, flag=1, fuel, ans=0;
	int r1, r2;

	read2(a, b);
	read2(f, k);

	r1 = 2*f;
	r2 = 2*(a-f);
	fuel = b-r1/2;
	f(i, k-1)
	{
		if(fuel<0)
		{
			flag=0;
			break;
		}

		if(i%2==0)
		{
			if(fuel<r2)
			{
				fuel = b;
				ans++;
			}

			fuel -= r2;
		}

		if(i%2==1)
		{
			if(fuel<r1)
			{
				fuel = b;
				ans++;
			}

			fuel -= r1;
		}
	}

	if(fuel<0)
		flag=0;

	if(k%2==0 && fuel<r1/2)
	{
		fuel = b;
		fuel-=r1/2;
		ans++;
	}
	else if(k%2==1 && fuel<r2/2)
	{
		fuel = b;
		fuel-=r2/2;
		ans++;
	}
	if(fuel<0)
		flag=0;

	if(flag)
		printf("%d", ans);
	else
		printf("-1");
}