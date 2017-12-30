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
	int n, r;
	int x[1009];
	double y[1009];

	read2(n, r);
	f(i, n)
		read(x[i]);

	y[0] = r*1.0;
	F(i, 1, n, 1)
	{
		double h = r*1.0;
		f(j, i)
			h = max(h, y[j] + sqrt(4*1.0*r*r - (x[i] - x[j])*1.0*(x[i] - x[j])));

		y[i] = h;
	}

	f(i, n)
		printf("%0.9lf ", y[i]);
}