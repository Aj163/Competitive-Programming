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
	int t, n;
	int a[10009], b[10009];
	ll temp;

	read(t);
	f(z, t)
	{
		read(n);
		f(i, n)
		{
			cin>>temp;
			a[i] = temp%(1<<16);
			b[i] = (temp - a[i])/(1<<16);
		}

		printf("Case %d:\n", z+1);
		f(i, n)
			printf("%d ", a[i]);

		printf("\n");
		f(i, n)
			printf("%d ", b[i]);

		printf("\n");
	}
}